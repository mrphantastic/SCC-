#ifndef DFSPHASE2_H_
#define DFSPHASE2_H_

//precondition: adjVert!=NULL and is a Transposed graph
void dfsT(int v, IntList adjVert[], int color[], int leader, int scc[]);
void dfsSweepT(int n, IntList adjVert[], Stack* S, int scc[]);
//precondition: n>0 and scc!=NULL
void printMapT(int n, int scc[]);

#endif //DFSPHASE2_H__
