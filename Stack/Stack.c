#include "Stack.h"

#pragma warning(disable:4996)

enum BOOL createStack(Stack* sp, int size, size_t dSize)
{
    if (sp == NULL) {
        return FALSE;
    }
    sp->stack = (char*)calloc(size, sizeof(char)*dSize);
    if (sp->stack != NULL)
    {
        sp->size = size;
        sp->top = NULL;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    

    return TRUE;
}

enum BOOL isStackFull(Stack* sp)
{
    if (sp == NULL) {
        return FALSE;
    }
    if (sp->top == sp->size)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

enum BOOL isStackEmpty(Stack* sp)
{
    if (sp == NULL) {  /* sp������ NULL check*/
        return FALSE;
    }
    if (sp->top == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

enum BOOL push(Stack* sp, Student* data, size_t dSize,
               void (*studentMemCpy)(Student*, Student*))
{
    if (sp == NULL) {  /* sp������ NULL check*/
        return FALSE;
    }
    if (isStackFull(sp) == TRUE)
    {
        return FALSE;
    }
    else
    {
        studentMemCpy((char*)sp->stack + sp->top*dSize, data);
        sp->top++;
        return TRUE;
    }
    


}

enum BOOL pop(Stack* sp, Student* data, size_t dSize,
              void (*studentMemCpy)(Student*, Student*),
              void (*studentClear)(Student*))
{
    if (sp == NULL) {
        return FALSE;
    }
    if (isStackEmpty(sp) == TRUE)
    {
        return FALSE;
    }
    else
    {

        --sp->top;
        studentMemCpy(data, (char*)sp->stack + sp->top * dSize);
        if (studentClear != NULL)                /*dataFree üũ*/
        {
            studentClear((char*)sp->stack + sp->top * dSize);
        }
        return TRUE;
    }


}

void printStack(const Stack* sp, size_t dSize, void(*studentPrint)(Student*))
{
    int i = sp->top;
    if (sp == NULL) {
        return;
    }
    while (i != 0)
    {
        studentPrint((char*)sp->stack + --i * dSize);
    }
    printf("\n");
}

void destroyStack(Stack*sp, size_t dSize,  void (*studentClear)(Student*))
{
    int i = sp->top;
    if (sp == NULL) {
        return;
    }
    while(i != 0)
    {
        studentClear((char*)sp->stack + --i * dSize);
    }
    if (sp->stack != NULL)
    {
        free(sp->stack);
    }
    sp->stack = NULL;
    sp->size = sp->top = 0;

    return;
}
