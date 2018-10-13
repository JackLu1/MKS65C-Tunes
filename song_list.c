/*
 * A linked list with each node representing a song
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_list.h"

char *n_strncpy(char * dest, char * src, int len)
{
    /*
     * Same as strncpy, but always null terminates the dest array.
     */
    strncpy(dest, src, len);
    dest[len - 1] = 0;
}

void print_list(struct song_node *n)
{
    while(n)
    {
        printf("[%s - %s]\n", n->name, n->artist);
        n = n->next;
    }
}

struct song_node *add_song(struct song_node *front, char *name, char *artist)
{
    struct song_node * new_front = malloc(sizeof(struct song_node));
    new_front->next = front;
    n_strncpy(new_front->name, name, 100);
    n_strncpy(new_front->artist, artist, 100);
    return new_front;
}

struct song_node *free_list(struct song_node * front)
{
    struct song_node * temp = front;
    struct song_node * ret = front;
    while(temp)
    {
        temp = temp->next;
        free(front);
        front = temp;
    }

    return ret;
}
