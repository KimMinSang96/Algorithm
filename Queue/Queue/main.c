#include <stdio.h>
#include "Queue.h"
#include "Student.h"
#pragma warning(disable:4996)
int menu(const char**, int);
void input(Queue*);
void myOutput(Queue*);
void myDelete(Queue*);
void myflush();

int main() {
    Queue que;
    const char* menuList[] = {"Input", "Delete", "Output(Print)", "Exit"};
    int menuCnt;
    int menuNum;


    createQueue(&que, 6, sizeof(Queue));

    menuCnt = sizeof(menuList) / sizeof(menuList[0]);
    
    while (1)
    {
        menuNum = menu(menuList, menuCnt);
        if (menuNum == menuCnt)
        {
            break;
        }
        switch (menuNum) {
            case 1: input(&que); break;
            case 2: myDelete(&que); break;
            case 3: myOutput(&que);break;
            default: break;
        }
    }
    
    destroyQueue(&que,sizeof(Queue),studentClear);
    
    return 0;
}

void input(Queue* qp)
{
    Student data = { NULL, 0 };
    char tname[100];
    int res;
    int size;
    while (1) {
        res = 0;
        printf("Insert Student Name(type 'stop' if you want to stop this loop): ");
        scanf("%s", tname);
        if (strcmp(tname, "stop") == 0) { break; }
        data.name = (char*)calloc(strlen(tname) + 1, sizeof(char));
        strcpy(data.name, tname);
        while (1) {
            printf("Insert Student ID: ");
            res = scanf("%d", &data.num);
            if (res == 1)
            {
                break;
            }
            
            else
                myflush();
        }
        
        if (enqueue(qp, &data, sizeof(Student), studentMemCpy) == FALSE) {
            printf("You Can't Input It(Queue is Full)!\n");
        }
        
        free(data.name);
    }
}

void myOutput(Queue* sp)
{
    printQueue(sp, sizeof(Student), studentPrint);
}

void myDelete(Queue* qPtr)
{
    int i;
    int cnt;
    Student qData = { NULL, 0 };
    
    int res;
    printf("Insert Delete Number : ");
    scanf("%d", &cnt);
    for (i = 0; i < cnt; i++) {
        res = dequeue(qPtr, &qData, sizeof(Student), studentMemCpy, studentClear);
        
        if (res == 1)
        {
            studentPrint(&qData);
        }
        else
            printf("You Can't Delete It(Queue is Empty)!\n");
    }
    
    free(qData.name);
}

int menu(const char** menuList, int menuCnt)
{
    int i;
    int menuNum = 0;
    int res;
    
    for (i = 0; i < menuCnt; i++)
    {
        printf("%d. %s\n", i + 1, menuList[i]);
    }
    while (menuNum<1 || menuNum>menuCnt)
    {
        printf("# Menu-List : ");
        res = scanf("%d", &menuNum);
        if (res != 1)
        {
            myflush();
            continue;
        }
    }
    return menuNum;
}

void myflush()
{
    while (getchar() != '\n')
    {
        ;
    }
}
