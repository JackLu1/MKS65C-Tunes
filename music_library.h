//music_library functions
struct song_node **create_lib();
void print_lib(struct song_node **);
void add_song(struct song_node **, char *, char *);
struct song_node *search_song(struct song_node **, char *, char *);
void clear_lib(struct song_node **);
