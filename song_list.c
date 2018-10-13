/*
 * A linked list with each node representing a song
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
};

void print_songs(struct song_node *n)
{
    while(n)
    {
        printf("[%s - %s]\n", n->name, n->artist);
        n = n->next;
    }
}

struct song_node * add_song(struct song_node *front, char *name, char *artist)
{
    struct song_node * new_front = malloc(sizeof(struct song_node));
    /* TODO: Fix potential buffer overflow */
    strcpy(new_front->name, name);
    strcpy(new_front->artist, artist);
    new_front->next = front;
    return new_front;
}

struct song_node * free_list(struct song_node * front)
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
