#include <stdio.h>
#include <stdlib.h>
#include "edgeList.h"

////////// DATA STRUCTURES //////////

struct EdgeListNode{
   EdgeInfo element;
   EdgeList next;
}; EdgeList edgenil = NULL; 

////////// FUNCTIONS //////////
  
EdgeInfo edgeFirst(EdgeList oldL){
   return oldL->element; 
}

EdgeList edgeRest(EdgeList oldL){
   return oldL->next;
}

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL){
   EdgeList newList = calloc(1, sizeof(struct EdgeListNode));
   newList->element = newE;
   newList->next = oldL;
   return newList;
}
