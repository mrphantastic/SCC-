#include <stdio.h>
#include <stdlib.h>
#include "loadGraph.h"
#include "intList.h"
#include "edgeList.h"

struct Edge{ // Data structure for our edges of our graph
   int from;
   int to;
   double weight;
};

struct IntListNode{ // Nodes for our linkedlist to keep track of edges
   int element;
   IntList next;
}; 

struct EdgeListNode{ // Special data structure for edges with weight
   EdgeInfo element;
   EdgeList next;
}; 

IntList* initEdges(int n){ //Creates and initializes a Linked List to null of size n
   int i;
   IntList* adjVert = calloc(n+1,sizeof(IntList));
   for(i=1;i<n+1;i++){
      adjVert[i] = NULL;
   }
   return adjVert;
}

EdgeList* initEdgesW(int n){
   int i;
   EdgeList* adjVertW = calloc(n+1,sizeof(EdgeList));
   for(i=1;i<n+1;i++){
      adjVertW[i]=NULL;
   }
   return adjVertW;   
}

void loadEdges(char line[],Edge e, IntList adjVert[]){
   adjVert[e->from] = intCons(e->to,adjVert[e->from]);
  // return adjVert;
}

void loadEdgesReverse(char line[], Edge e, IntList adjVert[]){
   adjVert[e->to] = intCons(e->from,adjVert[e->to]);
}

void loadEdgesW(char line[], Edge e, EdgeList adjVertW[]){
   EdgeInfo newI;
   newI.to=e->to;
   newI.wgt=e->weight; 
   adjVertW[e->from] = edgeCons(newI,adjVertW[e->from]);
}

void loadEdgesWReverse(char line[], Edge e, EdgeList adjVertW[]){
   EdgeInfo newI;
   newI.to=e->from;
   newI.wgt=e->weight;
   adjVertW[e->to] = edgeCons(newI,adjVertW[e->to]);
}


Edge parseEdge(char line[]){
   Edge newE = calloc (1,sizeof(struct Edge));
   int numFields;
   numFields = sscanf(line, " %d %d %lf %*s", &newE->from, &newE->to, &newE->weight);
   if(numFields <2 || numFields > 3){
      printf("Bad edge: %s", line);
      exit(1);
   }
   if(numFields == 2) newE->weight=0.0;
   return newE;
}

void printList(IntList L){
   if(L->next != NULL){
      printList(L->next);
   }
   printf("%d ", intFirst(L));

}
 
void printListW(EdgeList L){
   EdgeInfo e=edgeFirst(L);
   if(L->next!=NULL){
      printListW(L->next);
      printf(",");
   }
   printf("%d@%.01f ",e.to,e.wgt);
}
