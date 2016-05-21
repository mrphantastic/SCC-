#include <stdio.h>
#include <stdlib.h>
#include "intList.h"
#include "stack.h"

/*
struct map{
   int vertex;
   int color[vertex];
   int parent[vertex];
   int dTime[vertex];
   int fTime[vertex];
};
*/

int color[1024];
char color2[1024];
int parent[1024];
int dTime[1024];
int fTime[1024];
int time;


void dfsT(int v, IntList adjVert[], int color[], int leader, int scc[]){
   time++;
   dTime[v]=time;
   color[v] = 1;
   scc[v]=leader;
   IntList remAdj = adjVert[v];
   //printList(remAdj);
   while(remAdj!=NULL){
      int w = intFirst(remAdj);
      if(color[w] == 0){
         parent[w]=v;
         dfsT(w,adjVert,color,leader,scc);
      }
      else{
      }
      remAdj= intRest(remAdj);
   }
   time++;
   fTime[v]=time; 
   color[v]=-1;
   
   //printf("%d was marked black\n", v); 
   return;
}

void dfsSweepT(int n, IntList adjVert[], Stack* S, int scc[]){
   time=0;
   int w;
   for(w=1;w<n+1;w++){
      color[w]=0;
   }
   while(S->top!=0){
      int v = stackTop(S);
      stackPop(S);
      if(color[v]==0){
         dfsT(v,adjVert,color,v,scc);
      }
   }
   return;
}

void printMapT(int n, int scc[]){
   int i;
   printf("V   color dTime fTime parent dfstRoot2\n");
   for(i=1;i<n+1;i++){
      if(color[i]==0){
         color2[i]='W';
      }
      if(color[i]==1){
         color2[i]='G';
      }
      if(color[i]==-1){
         color2[i]='B';
      }
      printf("%d%8c%6d%6d%7d%10d\n",i,color2[i],dTime[i],fTime[i],parent[i],scc[i]);
   }
}
   
