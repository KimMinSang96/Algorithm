
#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Student Struct
typedef struct _student {
    char name[20];                              // Student Name
    int num;                                    // Student ID
} Student;


void studentMemCpy(Student* p1, Student* p2);   // Copy Student Data (p1 -> p2)
void studentClear(Student* p);                  // Delete Student Data
void studentPrint(Student* p);                  // Print Student Data

#endif /* Student_h */
