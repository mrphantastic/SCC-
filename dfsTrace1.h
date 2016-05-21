#ifndef DFSTRACE_H__
#define DFSTRACE_H__
#include "stack.h"

typedef struct map* map;

//precondition: adjVertW[]!= NULL
double LDP(int v, EdgeList adjVertW[]);
void ldpSweep(int n, EdgeList adjVertW[]);
//precondition: adjVert[]!=NULL
void dfsTrace(int v, IntList adjVert[],Stack* S);
void dfsSweep(int n, IntList adjVert[], Stack* S);
//precondition: n>0
void printMap(int n);
void printMapDAG(int n);
#endif // DFSTRACE_H__
