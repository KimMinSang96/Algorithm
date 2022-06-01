//
//  Student.h
//  Queue
//
//  Created by 김민상 on 2022/06/02.
//

#ifndef Student_h
#define Student_h

#pragma once
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct _student
{
    char* name;
    int num;
}Student;

void studentMemCpy(Student* p1, Student* p2);
void studentClear(Student* p);
void studentPrint(Student* p);






#endif /* Student_h */
