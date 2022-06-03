//
//  InsertSort.c
//  Sort
//
//  Created by 김민상 on 2022/06/03.
//

#include "InsertSort.h"

void insertSort (int *list, int n )
{
  int i, j, remember;
  for ( i = 1; i < n; i++ )
  {
    remember = list[(j=i)];
    while ( --j >= 0 && remember < list[j] ){
        list[j+1] = list[j];
    }
    list[j+1] = remember;
  }
}
