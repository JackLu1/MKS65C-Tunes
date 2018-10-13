#include <stdio.h>
#include <stdlib.h>
#include "song_list.h"

void test_song_list()
{
    printf("===Testing basic linked list operations===\n");

    printf(":::Empty list:::\n");
    struct song_node *song_list = 0;
    print_list(song_list);
    printf("\n");

    printf(":::Adding songs to the front:::\n");
    song_list = add_song(song_list, "Red Hot Chili Peppers", "Otherside");
    print_list(song_list);
    printf("\n");

    printf(":::Another one:::\n");
    song_list = add_song(song_list, "Queen", "Bohemeian Rhapsody");
    print_list(song_list);
    printf("\n");

    printf(":::Another one:::\n");
    song_list = add_song(song_list, "John Coltrane", "Blue Train");
    print_list(song_list);
    printf("\n");

    printf(":::Buffer overflow test:::\n");
    song_list = add_song(song_list, 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    print_list(song_list);
    printf("\n");

    song_list = free_list(song_list);
}

int main()
{
    test_song_list();
}

