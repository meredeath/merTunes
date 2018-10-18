all: musiclist.o main.o musiclib.o
	gcc -o test musiclist.o main.o musiclib.o
musiclist.o: musiclist.c musiclist.h
	gcc -g -c musiclist.c
main.o: main.c musiclist.h
	gcc -g -c main.c
musiclib.o: musiclib.c musiclib.h musiclist.h
	gcc -g -c musiclib.c
run:
	./test
clean:
	rm *.o test
	ls
