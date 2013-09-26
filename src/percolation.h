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

#ifndef __PERCOLATION__HH
#define __PERCOLATION__HH

#include "union_find.h"

class percolation {
 private:
  /* We declare and maintain two UF objects here. They both run the percolation
     simulation. However, one of them maintains two virtual sites, which 
     allows us to check and see if the system percolates. The other one only 
     maintains one virtual site, which eliminates the backwash that occurs
     when the system percolates. 
  */
  union_find perc_grid;   
  union_find grid_uf;
  int dim;
  bool * vacant;
  int xyTo1D(int i, int j);

 public:
  percolation(int N);
  ~percolation();
  void open(int i, int j);
  bool is_open(int i, int j);
  bool is_full(int i, int j);
  bool percolates();
}; // end of percolation class definition. 

#endif
