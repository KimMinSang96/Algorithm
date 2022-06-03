#include "SelectionSort.h"

void selectionSort(int* list, const int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[min])
            {
                min = j;
            }
        }
        temp = list[min];
        list[min] = list[i];
        list[i] = temp;
    }
    
}
