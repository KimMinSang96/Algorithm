#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#pragma once

enum BOOL { FALSE, TRUE };

typedef struct _queue {
    struct _queue* queue;
    int size;
    int front, rear;
} Queue;

enum BOOL createQueue(Queue* qp, int size,size_t dSize);

enum BOOL isQueueEmpty(const Queue* qp);

enum BOOL isQueueFull(const Queue* qp);

enum BOOL enqueue(Queue* qp, Student* data,size_t dSize,
             void(*studentMemCpy)(Student*, Student*));

enum BOOL dequeue(Queue* qp, Student* data,size_t dSize,
             void(*studentMemCpy)(Student*, Student*), void(*studentClear)(Student*));

void printQueue(const Queue* qp, size_t dSize, void(*studentPrint)(Student*));

void destroyQueue(Queue* qp, size_t dSize, void(*studentClear)(Student*));

#endif /* Queue_h */
