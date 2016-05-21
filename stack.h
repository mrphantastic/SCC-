#ifndef STACK_H_
#define STACK_H_
#define STACK_MAX 100

struct Stack{
   int data[STACK_MAX];
   int top;
};
typedef struct Stack Stack;


Stack* initStack();
int stackTop(Stack* S);
void stackPush(Stack* S, int n);
void stackPop(Stack* S);
#endif //STACK_H__ 
