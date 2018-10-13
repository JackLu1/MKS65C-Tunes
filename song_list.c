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
    while (n)
    {
        printf("[%s - %s]\n", n->name, n->artist);
        n = n->next;
    }
}

struct song_node *add_song(struct song_node *head, char *artist, char *name)
{
    struct song_node *new_head = malloc(sizeof(struct song_node));
    new_head->next = head;
    n_strncpy(new_head->name, name, 100);
    n_strncpy(new_head->artist, artist, 100);
    return new_head;
}

struct song_node *add_song_sorted(struct song_node *head, char *artist, char *name)
{
    struct song_node *prev = 0;
    // TODO: FINISH THIS
    return 0;
}

struct song_node *free_list(struct song_node * head)
{
    struct song_node *temp = head;
    while (head)
    {
        temp = head;
        free(temp);
        head = head->next;
    }
    return 0;
}
