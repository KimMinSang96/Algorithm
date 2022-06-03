//
//  BubbleSort.c
//  Sort
//
//  Created by 김민상 on 2022/06/03.
//

#include "BubbleSort.h"

void bubbleSort(int* arr, int n) {
    int i, j, temp;
    for (i=n-1; i>0; i--) {
        for (j=0; j<i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}
