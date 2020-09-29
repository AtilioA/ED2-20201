sha: shaker_sort.o main.o
	gcc -o sha.out shaker_sort.o main.o

shaker_sort.o: shaker_sort.c item.h
	gcc -c shaker_sort.c

bub: bubble_sort.o main.o
	gcc -o bub.out bubble_sort.o main.o

bubble_sort.o: bubble_sort.c item.h
	gcc -c bubble_sort.c

ins: insertion_sort.o main.o
	gcc -o ins.out insertion_sort.o main.o

insertion_sort.o: insertion_sort.c item.h
	gcc -c insertion_sort.c

sel: selection_sort.o main.o
	gcc -o sel.out selection_sort.o main.o

selection_sort.o: selection_sort.c item.h
	gcc -c selection_sort.c

main.o: main.c item.h
	gcc -c main.c

clean:
	rm -rf *.o
	rm -rf *.out

