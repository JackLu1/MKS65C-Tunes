#include <stdio.h>
#include <stdlib.h>
#include "song_list.h"

void test_song_list()
{
    printf("===Testing basic linked list operations===\n");

    printf(":::Empty list:::\n");
    struct song_node *song_list = 0;
    print_list(song_list);

    printf(":::Add songs:::\n");
    song_list = add_song(song_list, "Red Hot Chili Peppers", "Otherside");
    song_list = add_song(song_list, "Queen", "Bohemeian Rhapsody");
    song_list = add_song(song_list, "John Coltrane", "Blue Train");
    song_list = add_song(song_list, 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb", 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb");
    print_list(song_list);
    
    printf(":::Finding [John Coltrane - Blue Train]:::\n");
    struct song_node *song = find_song(song_list, "John Coltrane", "Blue Train");
    print_song(song);

    printf(":::Finding [JynX - Present World Overhaul]:::\n");
    song = find_song(song_list, "JynX", "Present World Overhaul");
    printf("%p\n", song);

    printf(":::Finding a song by Queen:::\n");
    song = find_song_artist(song_list, "Queen");
    print_song(song);

    printf(":::Finding a song by Logan Paul:::\n");
    song = find_song_artist(song_list, "Logan Paul");
    printf("%p\n", song);

    printf(":::Remove a node:::\n");
    song_list = remove_song(song_list, 
            find_song(song_list, "Red Hot Chili Peppers", "Otherside"));
    print_list(song_list);

    printf(":::Remove head:::\n");
    song_list = remove_song(song_list, song_list);
    print_list(song_list);

    printf(":::Remove everything:::\n");
    song_list = remove_song(song_list, song_list);
    song_list = remove_song(song_list, song_list);
    print_list(song_list);
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
    song_list = add_song_sorted(song_list, "Queen", "Killer Queen");
    print_list(song_list);

    printf(":::Adding to the end:::\n");
    song_list = add_song_sorted(song_list, "Vanilla Ice", "Ice Ice Baby");
    print_list(song_list);

    printf(":::Add by song name:::\n");
    song_list = add_song_sorted(song_list, "Queen", "We Will Rock You");
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
    /* test_add_song_sorted(); */
    return 0;
}

