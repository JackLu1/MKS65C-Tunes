#include <stdio.h>
#include <stdlib.h>
#include "song_list.h"

void test_song_list()
{
    printf("===Testing basic linked list operations===\n");

    printf(":::Empty list:::\n");
    struct song_node *song_list = 0;
    print_list(song_list);

    printf(":::Adding songs to the front:::\n");
    song_list = add_song(song_list, "Red Hot Chili Peppers", "Otherside");
    print_list(song_list);

    printf(":::Another one:::\n");
    song_list = add_song(song_list, "Queen", "Bohemeian Rhapsody");
    print_list(song_list);

    printf(":::Another one:::\n");
    song_list = add_song(song_list, "John Coltrane", "Blue Train");
    print_list(song_list);

    printf(":::Buffer overflow prevention test:::\n");
    song_list = add_song(song_list, 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb", 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb");
    print_list(song_list);
    
    // NOTE: should be tested with valgrind
    song_list = free_list(song_list);
}

void test_add_song_sorted()
{
    printf("===Testing add_song_sorted()===\n");

    printf(":::Adding to an empty list:::\n");
    struct song_node *song_list = 0;
    song_list = add_song_sorted(song_list, "Paul McCartney", "Temporary Secretary");
    print_list(song_list);

    printf(":::Adding to the beginning:::\n");
    song_list = add_song_sorted(song_list, "Beatles", "Let it Be");    
    print_list(song_list);

    printf(":::Adding to the beginning:::\n");
    song_list = add_song_sorted(song_list, "ABBA", "Dancing Queen");    
    print_list(song_list);

    printf(":::Adding to the end:::\n");
    song_list = add_song_sorted(song_list, "Queen", "We Will Rock You");
    print_list(song_list);

    printf(":::Adding to the end:::\n");
    song_list = add_song_sorted(song_list, "Vanilla Ice", "Ice Ice Baby");
    print_list(song_list);

    printf(":::Add by song name:::\n");
    song_list = add_song_sorted(song_list, "Queen", "Killer Queen");
    song_list = add_song_sorted(song_list, "Queen", "Don't Stop Me Now");
    print_list(song_list);

    printf(":::Add by song name at the beginning:::\n");
    song_list = add_song_sorted(song_list, "ABBA", "Chiquita");
    print_list(song_list);

    printf(":::Add by song name, at the end:::\n");
    song_list = add_song_sorted(song_list, "Vanilla Ice", "Play That Funky Music");
    print_list(song_list);
}


int main()
{
    test_song_list();
    test_add_song_sorted();
    return 0;
}

