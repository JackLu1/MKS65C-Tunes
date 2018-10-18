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

void clear_lib(struct song_node **lib)
{
    /*
     * Completely remove all songs in the library.
     */
    int i;
    for (i = 0; i < 27; i++)
    {
        free_list(lib[i]);
    } 
}
