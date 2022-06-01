#ifndef Stack_h
#define Stack_h


#pragma once
#include "Student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum BOOL { FALSE, TRUE };

typedef struct _stack {
    struct _stack* stack;
    int size;
    int top;
}Stack;

enum BOOL createStack(Stack*sp, int size, size_t dSize);

enum BOOL isStackFull(Stack* sp);

enum BOOL isStackEmpty(Stack* sp);

enum BOOL push(Stack* sp, Student* data, size_t dSize,
               void (*studentMemCpy)(Student*, Student*));

enum BOOL pop(Stack* sp, Student* data,size_t dSize,
              void (*studentMemCpy)(Student*, Student*),
              void (*studentClear)(Student*));

void printStack(const Stack *sp,size_t dSize,void(*studentPrint)(Student*));

void destroyStack(Stack* sp, size_t dSize, void (*studentClear)(Student*));

#endif /* Stack_h */
