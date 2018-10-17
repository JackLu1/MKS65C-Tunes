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

void add_song(struct song_node **lib, char* artist, char *name)
{
    int i;
    for (i = 0; i < 26; i++)
    {
        if (artist[0] == i + 'A' || artist[0] == i + 'a')
        {
            lib[i] = add_node_sorted(lib[i], artist, name);
            return;
        }
    }
    lib[i] = add_node_sorted(lib[i], artist, name);
}
