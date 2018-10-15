all: musiclist.o main.o
	gcc -o test musiclist.o main.o
musiclist.o: musiclist.c musiclist.h
	gcc -g -c  musiclist.c
main.o: main.c musiclist.h
	gcc -g -c main.c
run:
	./test
clean:
	rm *.o a.out test
	ls
