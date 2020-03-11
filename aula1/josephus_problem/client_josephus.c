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

    // printf("Removing...\n");
    // pick_leader(circleOfPeople, M);
    // Node *leaderNode = delete_from_list(circleOfPeople, circleOfPeople->last);
    int leader = select_leader(circleOfPeople, M);
    printf("\n%i\n", leader);
    // print_list(circleOfPeople);

    // printf("\nDestroying list...\n");
    destroy_list(circleOfPeople);
    // print_list(circleOfPeople);
}
