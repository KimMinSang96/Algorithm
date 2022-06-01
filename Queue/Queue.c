#include "Queue.h"

enum BOOL createQueue(Queue* qp, int size,size_t dSize)
{
    if (qp == NULL) {
        return FALSE;
    }

    qp->queue = (char*)calloc(size,dSize);
    if (qp->queue != NULL)
    {
        qp->size = size;
        qp->front = 0;
        qp->rear = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

enum BOOL isQueueEmpty(const Queue* qp)
{
    if (qp == NULL) {
        return FALSE;
    }
    if (qp->front == qp->rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }


}

enum BOOL isQueueFull(const Queue* qp)
{
    if (qp == NULL) {
        return FALSE;
    }
    
    if (qp->front == (qp->rear + 1) % qp->size)
    {
        return TRUE;
    }
    
    else
    {
        return FALSE;
    }
}

enum BOOL enqueue(Queue* qp, Student* enqueData, size_t dSize, void(*studentMemCpy)(Student*, Student*))
{
    if (qp == NULL) {
        return FALSE;
    }
    
    if (isQueueFull(qp) == TRUE)
    {
        return FALSE;
    }
    
    studentMemCpy((char*)qp->queue+qp->rear*dSize, enqueData);
    qp->rear = (qp->rear + 1) % qp->size;
    return TRUE;
}

enum BOOL dequeue(Queue* qp, Student* data, size_t dSize,
                  void(*studentMemCpy)(Student*, Student*), void(*studentClear)(Student*))
{
    if (qp == NULL) {
        return FALSE;
    }
    
    if (isQueueEmpty(qp) == TRUE) {
        return FALSE;
    }
    
    studentMemCpy(data, (char*)qp->queue + qp->front * dSize);
    
    if (studentClear != NULL) {
        studentClear((char*)qp->queue + qp->front * dSize);
    }
    
    qp->front = (qp->front + 1) % qp->size;
    
    return TRUE;
}

void printQueue(const Queue* qp, size_t dSize, void(*studentPrint)(Student*))
{
    int i;
    if (qp == NULL) {
        return;
    }

    for (i = qp->front; i != qp->rear; i = (i + 1) % qp->size) {
        studentPrint((char*)qp->queue+i*dSize);
    }
    printf("\n");
}

void destroyQueue(Queue* qp, size_t dSize, void(*studentClear)(Student*))
{
    int i = qp->front;
    
    if (qp == NULL) {
        return;
    }

    while (i != qp->rear) {
        studentClear((char*)qp->queue + i * dSize);
        i++;
    }
    
    if (qp->queue != NULL) {
        free(qp->queue);
    }
    
    qp->queue = NULL;
    qp->rear = qp->front = 0;
    qp->size = 0;

    return;

}
