#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define STACK_MAX 100

/*
struct Stack{
   int data[STACK_MAX];
   int top;
}; //typedef struct Stack Stack;
*/
Stack* initStack(){
   Stack* S = calloc(1,sizeof(Stack));
   S->top = 0;
   return S;
}

int stackTop(Stack* S){
   if(S->top==0){
      fprintf(stderr, "Error: stack empty\n");
      return -1;
   }
   return S->data[S->top-1];
}

void stackPush(Stack* S, int n){
   if(S->top<STACK_MAX){
      S->data[S->top++]=n;
   }
   else fprintf(stderr, "Error: stack full \n");
}
 
void stackPop(Stack* S){
   if(S->top==0) fprintf(stderr, "Error: stack empty\n");
   else S->top--;
}
