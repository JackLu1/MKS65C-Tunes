struct song_node {
    char name[100];
    char artist[100];
    struct song_node *next;
};

void print_list(struct song_node *);
void print_list(struct song_node *);
struct song_node *add_song(struct song_node *, char *, char *);
struct song_node *add_song_sorted(struct song_node *, char *, char *);
struct song_node *free_list(struct song_node *);
struct song_node *find_song(struct song_node *, char *, char *);
struct song_node *find_song_artist(struct song_node *, char *);
struct song_node *remove_song(struct song_node *, struct song_node *);
