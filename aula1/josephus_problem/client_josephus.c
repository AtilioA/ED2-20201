#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    printf("N = %i, M = %i:\n", N, M);

    // LinkedList *circleOfPeople = malloc(sizeof(LinkedList));
    LinkedList *circleOfPeople = initialize_list(N);

    printf("\nPrinting list:\n");
    print_list(circleOfPeople);

    printf("Removing...\n");
    // remove_one(circleOfPeople, circleOfPeople->first, 5);
    pick_leader(circleOfPeople, M);
    print_list(circleOfPeople);

    printf("\nDestroying list...");
    destroy_list(circleOfPeople);
}
