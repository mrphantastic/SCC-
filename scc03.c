#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "intList.h" 
#include "edgeList.h"
#include "loadGraph.h"
#include "dfsTrace1.h"
#include "stack.h"
#include "dfsPhase2.h"

void printHere(IntList* adjVert, int n){
   int i;
   for(i=1;i<n+1;i++){
      printf("%d [ ",i);
      if(adjVert[i]!=NULL){
         printList(adjVert[i]);
      }
      printf("]\n");
   }
} 

void printHereW(EdgeList* adjVert, int n){
   int i;
   for(i=1;i<n+1;i++){
      printf("%d [ ",i);
      if(adjVert[i]!=NULL){
         printListW(adjVert[i]);
      }
      printf("]\n");
   }
}

void printStack(Stack* S){
   int i;
   for(i=S->top-1;i>=0;i--){
      printf("%d ",S->data[i]);
   }
   printf("\n");
}

IntList* transposeGraph(IntList* origGraph, int n){
   int i;
   IntList* remGraph = origGraph;
   IntList* newGraph = initEdges(n);
   for(i=1;i<n+1;i++){
      while(remGraph[i]!=NULL){
         int temp = intFirst(remGraph[i]);
         remGraph[i] = intRest(remGraph[i]);
         newGraph[temp]=intCons(i,newGraph[temp]);
      }
   }
   return newGraph; 
}

void findSCCs(int n, Stack* S, int scc[], IntList* adjVert, IntList* tGraph){
      printHere(adjVert,n);
      printf("\n");
      dfsSweep(n,adjVert,S);
      printMap(n);
      printf("\n");
      printStack(S);
      printf("\n");
      tGraph = transposeGraph(adjVert,n);
      printHere(tGraph,n);
      printf("\n");
      dfsSweepT(n,tGraph, S, scc);
      printMapT(n,scc);

}

int main(int argc, char* argv[]){
   int n;
   int scc[1024];
   int option=0;
   int w=0;
   int u=0; 
   IntList* adjVert;
   IntList* tGraph;
   EdgeList* adjVertW;
   char line[1024];
   char* fgetsRtn;
   Stack* S = initStack();   
  
   if(argc<2||argc>4){
      printf("Usage: java graph input.data\n");
      exit(1);
   }
   
   if(strcmp(argv[argc-1], "-") == 0){
        char name[100];
        scanf("%s", name);
        FILE* in = fopen(name, "r");
       
        if( in == NULL ){
            printf("Unable to read from file %s\n", name);
            exit(EXIT_FAILURE);
        }
        printf("\nOpened %s for input.\n\n", name);
        fgetsRtn = fgets(line,1024,in);
        n = atoi(fgetsRtn);
        printf("n = %d\n\n", n);
        adjVert = initEdges(n);
        adjVertW = initEdgesW(n);
        while(fgets(line,1024, in)){
           Edge e = parseEdge(line);
           loadEdges(line,e, adjVert);
        }
        fclose(in);
        findSCCs(n,S,scc,adjVert,tGraph);
        return 0;

    }

   while((option=getopt(argc, argv, "wu"))!= -1){
      switch(option){
         case 'w' : w=1; 
            break;
         case 'u' : u=1; 
            break;
         default: printf("Usage: bad flags\n");
                  exit(1);
      }
   }
   

   FILE* fp = fopen(argv[argc-1], "r");
   fgetsRtn = fgets(line,1024,fp);
   n = atoi(fgetsRtn);
   printf("n = %d\n\n", n);
   adjVert = initEdges(n);
   adjVertW = initEdgesW(n);
   if(u==0&&w==0){
      while(fgets(line,1024, fp)){
         Edge e = parseEdge(line);
         loadEdges(line,e, adjVert);
      }
   }
   if(u==1&&w==0){
      while(fgets(line,1024, fp)){
         Edge e = parseEdge(line);
         loadEdges(line,e, adjVert);
         loadEdgesReverse(line,e, adjVert);
      }
   }   
   if(u==0&&w==1){
      while(fgets(line,1024, fp)){
         Edge e = parseEdge(line);
         loadEdgesW(line,e, adjVertW);
      }
   }
   if(u==1&&w==1){
      while(fgets(line,1024, fp)){
         Edge e = parseEdge(line);
         loadEdgesW(line,e, adjVertW);
         loadEdgesWReverse(line,e, adjVertW);
      }   
   }
   
   fclose(fp);
   if(w==0){
      findSCCs(n,S,scc,adjVert,tGraph);  
   }   
   if(w==1){
      printHereW(adjVertW,n);
      printf("\n");
      ldpSweep(n,adjVertW);
      printMapDAG(n);
   }      
   return 0;
}

  
