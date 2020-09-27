#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *seleciona_menor(int cont_ordenados, int *indice_menor, int *array, int tam_array)
{
    int *selecionado;

    printf(" ");
    for (int i = cont_ordenados; i < tam_array; i++)
    {
        if (selecionado == NULL || *selecionado < array[i])
        {
            selecionado = &array[i];
            *indice_menor = i;
        }
    }

    return selecionado;
}

int main(int argc, char *argv[])
{
    int cont_menor = 0, *array, tam_array = 10;
    array = (int *)malloc(sizeof(int) * tam_array);

    int N = atoi(argv[1]);
    srand(time(NULL));

    printf("Numbers:\n");
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 1000;
        printf("%i ", array[i]);
    }

    printf("\nOrdered array:\n");
    int indice_menor;
    for (int cont_ordenados = 0; cont_ordenados < tam_array; cont_ordenados++)
    {
        int swap = array[cont_ordenados];
        int *menor = seleciona_menor(cont_ordenados, &indice_menor, array, tam_array);
        // printf("\ncont_ordenados: %i\n", cont_ordenados);
        // printf("swapei %i; ", swap);
        // printf("indice_menorzei %i\n", indice_menor);

        // printf("menorzei %i; ", *menor);
        array[cont_ordenados] = *menor;
        printf("%i", array[cont_ordenados]);
        array[indice_menor] = swap;

        // *menor = swap;
    }

    return 1;
}