#include <stdio.h>
#include <stdlib.h>
#include "intList.h"
#include "stack.h"
#include "edgeList.h"

int color[1024];
char color2[1024];
int parent[1024];
int dTime[1024];
int fTime[1024];
int time;
EdgeInfo* dagLongest;
int est;
double wLongest, currLongest;
EdgeInfo myLongest;

double LDP(int v, EdgeList adjVertW[]){
   time++;
   dTime[v]=time;
   color[v] = 1;
   myLongest.to = -1; 
   myLongest.wgt = 0.0;
   EdgeList remAdj = adjVertW[v];
   while(remAdj!=NULL){
      EdgeInfo wInfo = edgeFirst(remAdj);
      int w = wInfo.to;
      if(color[w] == 0){
         parent[w]=v;
         wLongest = LDP(w,adjVertW);
         currLongest = wInfo.wgt + wLongest;
         if(currLongest > myLongest.wgt){
            myLongest.to = w;
            myLongest.wgt = currLongest;
         }
      }
      else{
         if(color[w] == -1){
            currLongest= wInfo.wgt + dagLongest[w].wgt;
            if(currLongest > myLongest.wgt){
               myLongest.to = w;
               myLongest.wgt = currLongest;
            }
         }	
      }
      remAdj= edgeRest(remAdj);
   }
   time++;
   fTime[v]=time;
   color[v]=-1;
   dagLongest[v]=myLongest;
   return myLongest.wgt;
}

void ldpSweep(int n, EdgeList adjVertW[]){
   time=0;
   dagLongest = calloc(n+1,sizeof(EdgeInfo));
   int w;
   for(w=1;w<n+1;w++){
      color[w]=0;
   }
   for(w=1;w<n+1;w++){
      if(color[w]==0){
         parent[w]=-1;
         LDP(w,adjVertW);
      }
   }
   return;
}

void dfsTrace(int v, IntList adjVert[], Stack* S){
   time++;
   dTime[v]=time;
   color[v] = 1;
   IntList remAdj = adjVert[v];
   while(remAdj!=NULL){
      int w = intFirst(remAdj);
      if(color[w] == 0){
         parent[w]=v;
         dfsTrace(w,adjVert,S);
      }
      else{
      }
      remAdj= intRest(remAdj);
   }
   time++;
   fTime[v]=time; 
   color[v]=-1;
   stackPush(S,v);
   return;
}

void dfsSweep(int n, IntList adjVert[], Stack* S){
   time=0;
   int w;
   for(w=1;w<n+1;w++){
      color[w]=0;
   }
   for(w=1;w<n+1;w++){
      if(color[w]==0){
         parent[w]=-1;
         dfsTrace(w,adjVert,S);
      }
   }
   return;
}


void printMap(int n){
   int i;
   printf("V   color dTime fTime parent\n");
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
      printf("%d%8c%6d%6d%7d\n",i,color2[i],dTime[i],fTime[i],parent[i]);
   }
}

void printMapDAG(int n){
   int i;
   printf("V   color dTime fTime parent dagLongest[v].wgt dagLongest[v].to\n");
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
      printf("%d%8c%6d%6d%7d%18.1f%17d\n",i,color2[i],dTime[i],fTime[i],parent[i],dagLongest[i].wgt,dagLongest[i].to);
   }
}
     
