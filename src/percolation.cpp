/*---------------------------------------------------------------------------
 | Michael James Gilbert
 | michael.james.gilbert@gmail.com
 | Last updated: 9/24/2013 11:20 AM GMT
 |
 | percolation implements a Monte Carlo simulation of percolation on the
 | integer lattice. 
 | Copyright (c) 2013 Michael James Gilbert
 | 
 | This file is part of percolation (version 1.0)
 | 
 | percolation is free software; you can redistribute it and/or modify it 
 | under the terms of the GNU General Public License as published by the
 | free Software Foundation; either version 2 of the License, or (at your
 | option) any later version. 
 |
 | This software is distributed in the hope that it will be useful, but 
 | WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 | or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 | for more details. 
 |---------------------------------------------------------------------------*/

// system includes
#include <iostream>
#include <stdlib.h>
// local includes
#include "union_find.h"
#include "percolation.h"

// create an N-by-N grid, with all sites blocked
percolation::percolation(int N) : perc_grid(N * N + 2), grid_uf(N * N + 1) {
  dim = N;
  vacant = new bool[N * N];
  
  // initialize all sites to be blocked
  for (int i = 0; i < N * N; i++) 
    vacant[i] = false;

  // connect the top row to the virtual site located at id[N*N]
  // Note: handle the exceptional case N = 1
  if (N != 1) {
    for (int i = 0; i < N; i++) {
      grid_uf.unite(N * N, i);
      perc_grid.unite(N * N, i);
    }
    
    // connect the bottom row to the virtual site located at id[N * N + 1]
    // only do this for percolation grid
    for (int i = (N - 1) * N; i < N * N; i++) 
      perc_grid.unite(N * N + 1, i);
  }
  else {grid_uf.unite(0, 1); perc_grid.unite(0, 1); }
}

percolation::~percolation() {
  delete [] vacant;
}

// converts (i, j) format to 1-dimensional format compatible with union_find
int percolation::xyTo1D(int i, int j) {
  return (i - 1) * dim + j - 1;
}

// open site (row i, column j) if it is not open already. First check to see
// if indices are in bounds. 
void percolation::open(int i, int j) {
  if (i <= 0 || i > dim) {
    std::cout << "row index i out of bounds" << std::endl;
    exit(1);
  }
  if (j <= 0 || j > dim) {
    std::cout << "column index j out of bounds" << std::endl;
    exit(1);
  }
  // open the site
  vacant[xyTo1D(i, j)] = true;


  // check to see if nearest neighbors are open. If so, connect them 
  // to site which was just opened.

  // pathological case: N = 1
  if (dim == 1)
    perc_grid.unite(0, 2);
  // standard cases.
  if (j > 1 && vacant[xyTo1D(i, j - 1)]) {
    grid_uf.unite(xyTo1D(i, j - 1), xyTo1D(i, j));
    perc_grid.unite(xyTo1D(i, j - 1), xyTo1D(i, j));
  }
  if (j < dim && vacant[xyTo1D(i, j + 1)]) {
    grid_uf.unite(xyTo1D(i, j + 1), xyTo1D(i, j));
    perc_grid.unite(xyTo1D(i, j + 1), xyTo1D(i, j));
  }
  if (i > 1 && vacant[xyTo1D(i - 1, j)]) {
    grid_uf.unite(xyTo1D(i - 1, j), xyTo1D(i, j));
    perc_grid.unite(xyTo1D(i - 1, j), xyTo1D(i, j));
  }
  if (i < dim && vacant[xyTo1D(i + 1, j)]) {
    grid_uf.unite(xyTo1D(i + 1, j), xyTo1D(i, j));
    perc_grid.unite(xyTo1D(i + 1, j), xyTo1D(i, j));
  }
}

// is site (row i, column j) open?
bool percolation::is_open(int i, int j) {
  if (i <= 0 || i > dim) {
    std::cout << "row index i out of bounds" << std::endl;
    exit(1);
  }
  if (j <=0 || j > dim) {
    std::cout << "column index j out of bounds" << std::endl;
    exit(1);
  }
  return vacant[xyTo1D(i, j)];
}

// is site (row i, column j) full?
bool percolation::is_full(int i, int j) {
  if (i <= 0 || i > dim) {
    std::cout << "row index i out of bounds" << std::endl;
    exit(1);
  }
  if (j <= 0 || j > dim) {
    std::cout << "column index j out of bounds" << std::endl;
    exit(1);
  }
  return grid_uf.connected(xyTo1D(i, j), dim * dim) && vacant[xyTo1D(i, j)];
}

bool percolation::percolates() {
  return perc_grid.connected(dim * dim, dim * dim + 1);
}

