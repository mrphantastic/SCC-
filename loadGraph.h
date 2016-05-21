#ifndef LOADGRAPH_H_
#define LOADGRAPH_H_
#include "intList.h"
#include "edgeList.h"

typedef struct Edge* Edge;
//precondition: n>0
IntList* initEdges(int n);
EdgeList* initEdgesW(int n);
//precondition: e!=NULL
//postcondition: adjVert is filled with an intList at the correct index with information about e
void loadEdges(char line[], Edge e, IntList adjVert[]);
void loadEdgesReverse(char line[], Edge e, IntList adjVert[]);
//precondition: e!=NULL
//postcondition: adjVert is filled with an edgeList at the correct index with information about e
void loadEdgesW(char line[], Edge e, EdgeList adjVertW[]);
void loadEdgesWReverse(char line[], Edge e, EdgeList adjVertW[]);
//precondition: line is correct format (int *space* int)
//postcondition: creates an edge with information on line
Edge parseEdge(char line[]);
//precondition: L != NULL
void printList(IntList L);
void printListW(EdgeList L);

#endif //LOADGRAPH_H__
