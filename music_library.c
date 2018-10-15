#include <stdio.h>
#include <stdlib.h>
#include "song_list.h"


struct song_node *create_lib(){
    struct song_node * table = calloc(sizeof(struct song_node*), 27);

    return table;
}


