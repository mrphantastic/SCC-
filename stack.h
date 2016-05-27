#ifndef STACK_H_
#define STACK_H_
#define STACK_MAX 100

struct Stack{
   int data[STACK_MAX];
   int top;
};
typedef struct Stack Stack;


Stack* initStack(); // Creates new stack
int stackTop(Stack* S); // Returns top of stack
void stackPush(Stack* S, int n); // adds to stack
void stackPop(Stack* S); // removes from stack

#endif //STACK_H__ 
