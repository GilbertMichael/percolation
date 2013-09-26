// union_find.cpp

#include "union_find.h"

union_find::union_find(int N) {
  count = N;
  id = new int[N];
  sz = new int[N];
  for (int i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
}

union_find::~union_find() {
  delete [] id;
  delete [] sz;
}

// counts the number of connected components in the tree
int union_find::num_components() {
  return count;
}

// finds the index of the root of p in logarithmic time. Uses path compression
int union_find::find(int &p) {
  int root = p;
  while (root != id[root])
    root = id[root];
  while (p != root) {
    int new_p = id[p];
    id[p] = root;
    p = new_p;
  }
  return root;
}

// returns true if objects p and q are in the same connected component
bool union_find::connected(int p, int q) {
  return find(p) == find(q);
}

void union_find::unite(int p, int q) {
  int i = find(p);
  int j = find(q);
  if (i == j) return;
  if      (ht[i] < ht[j]) { id[i] = j; sz[j] += sz[i]; }
  else                    { id[j] = i; sz[i] += sz[j]; }  
  count--;
}

// end of class 
