#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    printf("N = %i, M = %i:\n", N, M);

    LinkedList *circleOfPeople = initialize_list(N);

    // printf("\nPrinting list:\n");
    // print_list(circleOfPeople);

    printf("Removing persons from the circle...\n");
    int leader = select_leader(circleOfPeople, M);
    printf("\nLeader: %i.\n", leader);

    printf("\nDestroying list...\n");
    destroy_list(circleOfPeople);
    print_list(circleOfPeople);
}
