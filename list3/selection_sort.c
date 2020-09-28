#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"

int *seleciona_menor(int cont_ordenados, int *indice_menor, int *array, int tam_array)
{
    int *selecionado;

    for (int i = cont_ordenados; i < tam_array; i++)
    {
        if (selecionado == NULL || less(key(*selecionado), key(array[i])))
        {
            selecionado = &array[i];
            *indice_menor = i;
        }
    }

    return selecionado;
}

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]), cont_menor = 0, tam_array = N;
    Item *array;
    array = (Item *)malloc(sizeof(Item) * tam_array);

    srand(time(NULL));

    printf("Numbers (keys):\n");
    for (int i = 0; i < N; i++)
    {
        array[i] = (Item) rand() % 1000;
        printf("%i ", key(array[i]));
    }

    printf("\nOrdered array:\n");
    int indice_menor = 0;
    for (int cont_ordenados = 0; cont_ordenados < tam_array; cont_ordenados++)
    {
        int *menor = seleciona_menor(cont_ordenados, &indice_menor, array, tam_array);
	exch(array[cont_ordenados],  array[indice_menor]);

        printf("%i ", key(array[cont_ordenados]));
    }

    return 0;
}
