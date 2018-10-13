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
        printf("[%s - %s]\n", n->artist, n->name);
        n = n->next;
    }
    printf("\n");
}

struct song_node *add_song(struct song_node *head, char *artist, char *name)
{
    /*
     * Adds a song before the node, and set its next node to the given node.
     * (Usually should only be used to add to the front of a list)
     *
     * Returns a pointer to the beginning of the list.
     * 
     * If the pointer points to the middle of a list, it will break the list unless
     * the pointer of the previous node is manually set.
     */

    struct song_node *new_head = malloc(sizeof(struct song_node));
    new_head->next = head;
    n_strncpy(new_head->artist, artist, 100);
    n_strncpy(new_head->name, name, 100);
    return new_head;
}

struct song_node *add_song_sorted(struct song_node *head, char *artist, char *name)
{
    /*
     * Adds a song in alphabetical order, first by the artist name and then the song name.
     *
     * Returns a pointer to the beginning of the list. 
     */

    // Empty list, add to head
    if (head == NULL)
    {
        return add_song(head, artist, name);
    }

    struct song_node *cur;
    struct song_node *prev;
    struct song_node *new_node;

    /* Find a position to add the node */
    for (cur = head, prev = 0; strcmp(artist, cur->artist) > 0; prev = cur, cur = cur->next)
    {
        /* Last node reached, add to end */
        if (cur->next == NULL)
        {
            new_node = add_song(0, artist, name);
            cur->next = new_node;
            return head;
        }
    }

    if (strcmp(artist, cur->artist) < 0)
    {
        /* Insert to found position */
        new_node = add_song(cur, artist, name);
        /* Added to beginning of a list */
        if (prev == NULL)
        {
            return new_node;
        }
        prev->next = new_node;
        return head;
    }

    /* Same artist name, sort by song name instead */
    if (strcmp(artist, cur->artist) == 0)
    {
        /* Find a position to add the node */
        for (; strcmp(name, cur->name) > 0; prev = cur, cur = cur->next)
        {
            /* Last node reached, add to end */
            if (cur->next == NULL)
            {
                new_node = add_song(0, artist, name);
                cur->next = new_node;
                return head;
            }
        }
        /* Insert to found position */
        new_node = add_song(cur, artist, name);
        /* Added to beginning of a list */
        if (prev == NULL)
        {
            return new_node;
        }
        prev->next = new_node;
        return head;
    }
}

struct song_node *free_list(struct song_node * head)
{
    struct song_node *temp = head;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
