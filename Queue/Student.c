#include "Student.h"

void studentMemCpy(Student* p1, Student* p2)
{
    studentClear(p1);
    if (((Student*)p2)->name != NULL)    //������ üũ
    {
        ((Student*)p1)->name = (char*)calloc(strlen(((Student*)p2)->name) + 1, sizeof(char));
        strcpy(((Student*)p1)->name, ((Student*)p2)->name);

        ((Student*)p1)->num = ((Student*)p2)->num;
    }
}

void studentClear(Student* p)
{
    if (((Student*)p)->name != NULL)
    {
        ((Student*)p)->name = NULL;
        ((Student*)p)->num = 0;
    }
}

void studentPrint(Student* p)
{
    if (p != NULL)
    {
        printf("Student Information : ");
        printf("%s /", ((Student*)p)->name);
        printf("%d /", ((Student*)p)->num);
        printf("%p ", p);
        printf("\n");
    }
}
