#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_list.h"
#include "music_library.h"

struct song_node **create_lib(){
    /*
     * Returns an array of 27 pointers to linked lists
     */
    struct song_node **table = calloc(sizeof(struct song_node*), 27);

    return table;
}

void print_lib(struct song_node **lib)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        if (lib[i])
        {
            if (i != 26)
            {
                printf("%c list:\n", i + 'A');
            }
            else
            {
                printf("Other characters list:\n");
            }
            print_list(lib[i]);
        }
    }
}

int find_index(struct song_node **lib, char* artist)
{
    /*
     * Helper function to find the correct linked list in the array.
     * 
     * Returns the index containing the linked list where the artist should belong to in the array.
     */
    int i;
    for (i = 0; i < 26; i++)
    {
        if (artist[0] == i + 'A' || artist[0] == i + 'a')
        {
            return i;
        }
    }
    return i;
}

void add_song(struct song_node **lib, char* artist, char *name)
{
    int i = find_index(lib, artist);
    lib[i] = add_node_sorted(lib[i], artist, name);
}

struct song_node *search_song(struct song_node **lib, char* artist, char*name)
{
    int i = find_index(lib, artist);
    return find_node(lib[i], artist, name);
}

int artist_exists(struct song_node **lib, char * artist){
    // return true or false
    int i;
    for (i = 0; i < 26; i++)
    {
        if (artist[0] == i + 'A' || artist[0] == i + 'a')
        {
            if (!(find_node_artist(lib[i], artist) == 0)){
                return 1;
            }
        }
    }
    return 0;
}

void print_letter(struct song_node **lib, char letter){
    int i;
    for (i = 0; i < 27; i++){
        if (letter == i + 'A' || letter == i + 'a'){
            printf("%c list\n", i + 'A');
            print_list(lib[i]);
        }
    }   
}

void print_artist(struct song_node **lib, char * artist){
    int i;
    for (i = 0; i < 27; i++){
        if (artist[0] == i + 'A' || artist[0] == i + 'a'){
            while (lib[i]){
                if (!strcasecmp(lib[i]->artist, artist)){
                    print_song(lib[i]);
                }
                lib[i] = lib[i]->next;
            }
        }
    }   
    
}

void clear_lib(struct song_node **lib)
{
    /*
     * Completely remove all songs in the library.
     */
    int i;
    for (i = 0; i < 27; i++)
    {
        lib[i] = free_list(lib[i]);
    } 
}
