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

main.o: main.c item.h
	gcc -c main.c

clean:
	rm -rf *.o
	rm -rf *.out
