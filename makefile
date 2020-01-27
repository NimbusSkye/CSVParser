main: main.o linked.o ssv.o
	gcc -g -pg -o main  main.o linked.o ssv.o
main.o: main.c 
	gcc -g -pg -c main.c

linked.o: linked.c
	gcc -g -pg -c linked.c

ssv.o: ssv.c
	gcc -g -pg -c ssv.c

