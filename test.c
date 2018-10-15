#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "song_list.h"

void test_song_list()
{
    printf("===Testing basic linked list operations===\n");

    printf(":::Empty list:::\n");
    struct song_node *song_list = 0;
    print_list(song_list);

    printf(":::Add songs:::\n");
    song_list = add_node(song_list, "Red Hot Chili Peppers", "Otherside");
    song_list = add_node(song_list, "Queen", "Bohemeian Rhapsody");
    song_list = add_node(song_list, "John Coltrane", "Blue Train");
    song_list = add_node(song_list, 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb", 
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAb");
    print_list(song_list);
    
    printf(":::Finding [John Coltrane - Blue Train]:::\n");
    print_song(find_node(song_list, "John Coltrane", "Blue Train"));

    printf(":::Finding [JynX - Present World Overhaul]:::\n");
    printf("%p\n", find_node(song_list, "JynX", "Present World Overhaul"));

    printf(":::Finding a song by Queen:::\n");
    print_song(find_node_artist(song_list, "Queen"));

    printf(":::Finding a song by Logan Paul:::\n");
    printf("%p\n", find_node_artist(song_list, "Logan Paul"));

    printf(":::Remove a node:::\n");
    song_list = remove_node(song_list, 
            find_node(song_list, "Red Hot Chili Peppers", "Otherside"));
    print_list(song_list);

    printf(":::Remove head:::\n");
    song_list = remove_node(song_list, song_list);
    print_list(song_list);

    printf(":::Remove everything:::\n");
    song_list = remove_node(song_list, song_list);
    song_list = remove_node(song_list, song_list);
    print_list(song_list);

    printf("===Testing add_node_sorted()===\n");
    song_list = add_node_sorted(song_list, "Paul McCartney", "Temporary Secretary");
    song_list = add_node_sorted(song_list, "Beatles", "Let it Be");    
    song_list = add_node_sorted(song_list, "ABBA", "Dancing Queen");    
    song_list = add_node_sorted(song_list, "Queen", "Killer Queen");
    song_list = add_node_sorted(song_list, "Vanilla Ice", "Ice Ice Baby");
    song_list = add_node_sorted(song_list, "Queen", "We Will Rock You");
    song_list = add_node_sorted(song_list, "Queen", "Don't Stop Me Now");
    song_list = add_node_sorted(song_list, "ABBA", "Chiquita");
    song_list = add_node_sorted(song_list, "Vanilla Ice", "Play That Funky Music");
    print_list(song_list);

    printf(":::Printing random songs:::\n");
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));
    print_song(random_node(song_list));

}

void test_add_node_sorted()
{
}

int main()
{
    srand(time(NULL));
    test_song_list();
    return 0;
}

