all: test.o song_list.o song_list.h
	gcc -o musicplayertest test.o song_list.o

run: all
	./musicplayertest

song_list.o: song_list.c
	gcc -c song_list.c

test.o: test.c
	gcc -c test.c

clean:
	rm *.o
	rm musicplayertest

debug: debug_o debug_link

debug_o: song_list.c test.c
	gcc -c test.c song_list.c -g

debug_link: test.o song_list.o song_list.h
	gcc -o musicplayertest test.o song_list.o -g
