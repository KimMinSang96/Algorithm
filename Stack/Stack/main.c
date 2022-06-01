#include "Stack.h"
#include"Student.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning (disable:4996)

int menu(const char** mList, size_t menuCnt);
void mInput(Stack* sp);
void myDelete(Stack* sp);
void mOutput(Stack* sp);
void myflush();

int main()
{
    Stack stk;
    const char* menuList[] = { "Input", "Delete", "Output(Print)", "Exit" };
    int menuCnt;
    int menuNum;
    enum BOOL Bres;

    Bres = createStack(&stk, 5, sizeof(Student));
    if (Bres == FALSE)
    {
        return 1;
    }

    menuCnt = sizeof(menuList) / sizeof(menuList[0]);

    while (1)
    {
        menuNum = menu(menuList, menuCnt);
        if (menuNum == menuCnt)
        {
            break;
        }
        switch (menuNum)
        {
        case 1: mInput(&stk);  break;
        case 2: myDelete(&stk); break;
        case 3: mOutput(&stk);
        }
    }
    destroyStack(&stk, sizeof(Student), studentClear);
    return 0;
}

void mInput(Stack* sp)
{
    Student data = {" ",0};
    char tname[100];
    while (1) {
        printf("Input Student Number(Type 'stop' if you want to stop this loop): ");
        scanf("%s", tname);
        if (strcmp(tname, "stop") == 0) { break; }
        strcpy(data.name, tname);
        printf("Input Student ID : ");
        while (scanf("%d", &data.num) != 1) {
            myflush();
            printf("Input Student ID : ");
        }
        if (push(sp, &data, sizeof(Student), studentMemCpy) == FALSE)
        {
            printf("You can't push this data (Stack is full)!\n");
        }
    }
}

void myDelete(Stack* sp)
{
    int i;
    int cnt;
    Student popData = { " ",0};
    int res;

    printf("Input Pop Number : ");
    scanf("%d", &cnt);
    for (i = 0; i < cnt; i++) {
        res = pop(sp, &popData, sizeof(Student), studentMemCpy, studentClear);        if (res == 1)
        {
            studentPrint(&popData);
        }
        else
            printf("You can't pop this data (Stack is empty)!\n");
    }
}

void mOutput(Stack* sp)
{
    printStack(sp, sizeof(Student), studentPrint);
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

void myflush()
{
    while (getchar() != '\n')
    {
        ;
    }
}
