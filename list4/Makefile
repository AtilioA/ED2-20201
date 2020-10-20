all: insertion_sort.o top_down_cutoffskip top_down_skip top_down_cutoff top_down bottom_up bottom_up_cutoff bottom_up_skip

top_down_cutoffskip: merge_sort_top_down_cutoffskip.o insertion_sort.o main.o
	gcc -o cutoffskip.out merge_sort_top_down_cutoffskip.o insertion_sort.o main.o

merge_sort_top_down_cutoffskip.o: merge_sort_top_down_cutoffskip.c insertion_sort.c item.h
	gcc -c merge_sort_top_down_cutoffskip.c

top_down_skip: merge_sort_top_down_skip.o main.o
	gcc -o skip.out merge_sort_top_down_skip.o main.o

merge_sort_top_down_skip.o: merge_sort_top_down_skip.c item.h
	gcc -c merge_sort_top_down_skip.c

top_down_cutoff: merge_sort_top_down_cutoff.o insertion_sort.o main.o
	gcc -o cutoff.out merge_sort_top_down_cutoff.o insertion_sort.o main.o

merge_sort_top_down_cutoff.o: merge_sort_top_down_cutoff.c insertion_sort.c item.h
	gcc -c merge_sort_top_down_cutoff.c

top_down: merge_sort_top_down.o main.o
	gcc -o top_down.out merge_sort_top_down.o main.o

merge_sort_top_down.o: merge_sort_top_down.c item.h
	gcc -c merge_sort_top_down.c

bottom_up: merge_sort_bottom_up.o main.o
	gcc -o bottom_up.out merge_sort_bottom_up.o main.o

merge_sort_bottom_up.o: merge_sort_bottom_up.c item.h
	gcc -c merge_sort_bottom_up.c

bottom_up_cutoff: merge_sort_bottom_up_cutoff.o insertion_sort.o main.o
	gcc -o bottom_up_cutoff.out merge_sort_bottom_up_cutoff.o insertion_sort.o main.o

merge_sort_bottom_up_cutoff.o: merge_sort_bottom_up_cutoff.c insertion_sort.c item.h
	gcc -c merge_sort_bottom_up_cutoff.c

bottom_up_skip: merge_sort_bottom_up_skip.o main.o
	gcc -o bottom_up_skip.out merge_sort_bottom_up_skip.o main.o

merge_sort_bottom_up_skip.o: merge_sort_bottom_up_skip.c item.h
	gcc -c merge_sort_bottom_up_skip.c

insertion_sort.o: insertion_sort.c item.h
	gcc -c insertion_sort.c

main.o: main.c item.h
	gcc -c main.c

clean:
	rm -rf *.o
	rm -rf *.out
