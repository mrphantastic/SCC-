// Nathan Phan nathphan
#include "intList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct IntListNode{
   int element;
   IntList next;
}; const IntList intNil = NULL;

int intFirst(IntList oldL){
   return oldL->element;
}

IntList intRest(IntList oldL){
   return oldL->next;
}

IntList intCons(int newE, IntList oldL){
   IntList newList = calloc(1, sizeof(struct IntListNode));
   newList->element = newE;
   newList->next = oldL;
   return newList;
}
  
