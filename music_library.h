//music_library functions
struct song_node **create_lib();
void print_lib(struct song_node **);
void add_song(struct song_node **lib, char* artist, char *name);
struct song_node *search_song(struct song_node **lib, char* artist, char*name);

