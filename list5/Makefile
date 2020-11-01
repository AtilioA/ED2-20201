all: insertion_sort.o top_down_cutoff_median top_down_median top_down_cutoff top_down bottom_up bottom_up_cutoff bottom_up_median

top_down_cutoff_median: quick_sort_top_down_cutoff_median.o insertion_sort.o main.o
	gcc -o cutoff_median.out quick_sort_top_down_cutoff_median.o insertion_sort.o main.o

quick_sort_top_down_cutoff_median.o: quick_sort_top_down_cutoff_median.c insertion_sort.c item.h
	gcc -c quick_sort_top_down_cutoff_median.c

top_down_median: quick_sort_top_down_median.o main.o
	gcc -o median.out quick_sort_top_down_median.o main.o

quick_sort_top_down_median.o: quick_sort_top_down_median.c item.h
	gcc -c quick_sort_top_down_median.c

top_down_cutoff: quick_sort_top_down_cutoff.o insertion_sort.o main.o
	gcc -o cutoff.out quick_sort_top_down_cutoff.o insertion_sort.o main.o

quick_sort_top_down_cutoff.o: quick_sort_top_down_cutoff.c insertion_sort.c item.h
	gcc -c quick_sort_top_down_cutoff.c

top_down: quick_sort_top_down.o main.o
	gcc -o top_down.out quick_sort_top_down.o main.o

quick_sort_top_down.o: quick_sort_top_down.c item.h
	gcc -c quick_sort_top_down.c

bottom_up: quick_sort_bottom_up.o stack.o main.o
	gcc -o bottom_up.out quick_sort_bottom_up.o stack.o  main.o

quick_sort_bottom_up.o: quick_sort_bottom_up.c item.h
	gcc -c quick_sort_bottom_up.c

bottom_up_cutoff_median: quick_sort_bottom_up_cutoff_median.o stack.o insertion_sort.o main.o
	gcc -o bottom_up_cutoff_median.out quick_sort_bottom_up_cutoff_median.o stack.o insertion_sort.o main.o

quick_sort_bottom_up_cutoff_median.o: quick_sort_bottom_up_cutoff_median.c item.h
	gcc -c quick_sort_bottom_up_cutoff_median.c

insertion_sort.o: insertion_sort.c item.h
	gcc -c insertion_sort.c

stack.o: stack.c item.h
	gcc -c stack.c

main.o: main.c item.h
	gcc -c main.c

clean:
	rm -rf *.o
	rm -rf *.out
