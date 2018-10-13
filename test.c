#include <stdio.h>
#include <stdlib.h>
#include "song_list.h"

void test_song_list()
{
    printf("Test basic linked list operations:\n");

    printf("New empty list:\n");
    struct song_node *song_list = 0;
    print_songs(song_list);
    printf("\n");

    printf("Adding songs to the front:\n");
    song_list = add_song(song_list, "Red Hot Chili Peppers", "Otherside");
    print_songs(song_list);
    printf("\n");

    printf("Another one:\n");
    song_list = add_song(song_list, "Queen", "Bohemeian Rhapsody");
    print_songs(song_list);
    printf("\n");

    printf("Another one:\n");
    song_list = add_song(song_list, "John Coltrane", "Blue Train");
    print_songs(song_list);
    printf("\n");
}

int main()
{
    test_song_list();
}

