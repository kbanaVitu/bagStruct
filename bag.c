#include <stdio.h>
#include <stdlib.h>
#include "bag.h"
struct bag
{
    int *data;
    int n;
    int size;
};

Bag *create(int n)
{
    Bag *bag = (Bag *)malloc(sizeof(Bag));
    bag->data = (int *)calloc(n, sizeof(int));
    bag->n = n;
    bag->size = 0; // zero, pois nenhum elemento foi inserido.
    printf("Instância de Bag criada em %p!\n\n", bag);
    return bag;
}

int insert(Bag *bag, int e)
{
    if (bag->size < bag->n && e > 0)
    { // avalia se bag não está cheio e se o elemento e é positivo
        int i = 0;
        do
        {
            i = rand() % bag->n; // atribui a i, tal que 0 <= i < n
        } while (bag->data[i] != 0); // avalia se em i já não um elemento
        bag->data[i] = e;
        bag->size++;
        printf("Elemento %i inserido em bag->[%i].\n\n", e, i);
        return i;
    }
    return -1;
}

int get(Bag *bag)
{
    int i = 0;
    do
    {
        i = rand() % bag->n; // atribui um valor a i, tal que 0 <= i < n
    } while (bag->data[i] == 0); // avalia se em i ainda não tem um elemento
    bag->data[i] = 0;
    bag->size--;
    return 0;
}

int search(Bag *bag, int e)
{
    int aux = 0;
    for(int i = 0;i<=bag->n;i++)
        if(e == bag->data[i]) // avalia se 'e' corresponde ao elemento no vetor
        aux++;
    if (aux >= 1)
        return printf("O valor %i está na bag\n\n", e);
    else
        return printf("O valor %i não está na bag\n\n", e);
}

int size(Bag *bag)
{
    return printf("Número de elementos contido na bag: %i\n\n", bag->size);
}

void printAll(Bag *bag) {
    printf("Valores contidos na bag:");
    for (int i = 0; i < bag->n; i++)
        printf("%i ", bag->data[i]);
        printf("\n\n");
}
