#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 9

#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertSort.h"

int menu(const char** mList, size_t menuCnt);
void sort(int*, int);
void randomList(int*);
void printList(int*);
void printSortList(int*, int);
void myflush();

int main() {
    const char* menuList[] = {"SelectionList", "BubbleSort", "InsertSort", "Exit"};
    int list[MAX];
    int menuCnt;
    int menuNum;
    
    menuCnt = sizeof(menuList) / sizeof(menuList[0]);
    while(1) {
        menuNum = menu(menuList, menuCnt);
        if (menuNum == menuCnt) {
            break;
        }
        
        randomList(list);
        printList(list);
        sort(list, menuNum);
        printSortList(list, menuNum);
    }
    
    return 0;
}


int menu(const char** menuList, size_t menuCnt)
{
    size_t i;
    size_t menuNum = 0;
    int res;
    for (i = 0; i < menuCnt; i++)
    {
        printf("%d. %s\n", i + 1, menuList[i]);
    }

    while (menuNum<1 || menuNum>menuCnt)
    {
        printf("# Insert the number : ");
        res = scanf("%u", &menuNum);
        if (res != 1)
        {
            myflush();
            continue;
        }
    }
    return menuNum;
}

void sort(int* list, int menuNum) {
    int cnt;
    switch(menuNum) {
        case 1: selectionSort(list, MAX); break;
        case 2: bubbleSort(list, MAX); break;
        case 3: insertSort(list, MAX); break;
        default: break;
    }
    
}

void randomList(int* list) {
    srand(time(NULL));
    
    for (int i = 0; i < MAX; i++) {
        list[i] = rand() % 100;
    }
}

void printList(int* list) {
    printf("\n생성된 List : [");
    
    for (int i = 0; i < MAX; i++) {
        printf("%d, ", list[i]);
    }
    printf("]\n");
}

void printSortList(int* list, int menuNum) {
    char str[15];
    
    switch(menuNum) {
        case 1: strcpy(str, "SelectionSort"); break;
        case 2: strcpy(str, "BubbleSort"); break;
        case 3: strcpy(str, "InsertSort"); break;
        default: break;
     }
    
    printf("사용한 Sort : %s\n", str);
    printf("List : [");
    
    for (int i = 0; i < MAX; i++) {
        printf("%d, ", list[i]);
    }
    printf("]\n\n");
}

void myflush()
{
    while (getchar() != '\n')
    {
        ;
    }
}
