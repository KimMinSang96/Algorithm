#include "Student.h"

void studentMemCpy(Student* p1, Student* p2)
{
    studentClear(p1);
    if (p2->name != NULL){
        strcpy(p1->name, p2->name);
    }
    p1->num = p2->num;
}

void studentClear(Student* p)
{
    if (p->name != NULL)
        return ;
    strcpy(p->name,"");
    p->num = 0;
}

void studentPrint(Student* p)
{
    if (p != NULL)
    {
        printf("%s\t\t%d\t\t%p\n",
               ((Student*)p)->name, ((Student*)p)->num, p);
    }
}
