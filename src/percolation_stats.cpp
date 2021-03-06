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
 | for more details. You should have received a copy of the GNU General
 | Public License with this software. 
 |---------------------------------------------------------------------------*/

// system includes 
#include <iostream>
#include <stdlib.h>
#include <vector>
// local includes 
#include "stats.h"
#include "percolation.h"
#include "random.h"

class percolation_stats {
private:
  std::vector<double> threshold;
public:
  percolation_stats(int N, int T);
  double mean();
  double stddev();
  double confidence_lo();
  double confidence_hi();
}; // end of class percolation_stats prototype

// perform T independent computational experiments on an N-by-N percolation
// grid
percolation_stats::percolation_stats(int N, int T) : threshold(T) {
  // check to see if N, T are in bounds that make sense
  if (N <= 0 || T <= 0) {
    std::cout << "Arguments must be positive. Exiting... " << std::endl;
    exit(1);
  }
  for (int iter = 0; iter < T; iter++) {
    percolation perc(N);
    int count = 0;
    while (!perc.percolates()) {
      int i = random::uniform(1, N + 1);
      int j = random::uniform(1, N + 1);
      if (!perc.is_open(i, j)) perc.open(i, j);
      else continue;
      count++;
    }
    threshold[iter] = (double) count / (N * N);
  }
}

// sample mean of percolation threshold over T simulations
double percolation_stats::mean() {
  return stats::mean(threshold);
}

// sample standard deviation of percolation threshold over T simulations
double percolation_stats::stddev() {
  return stats::stddev(threshold);
}

// returns lower bound on the 95% confidence interval
double percolation_stats::confidence_lo() {
  return mean() - 1.96 * stddev() / threshold.size();
}

// returns upper bound on the 95% confidence interval
double percolation_stats::confidence_hi() {
  return mean() + 1.96 * stddev() / threshold.size();
}

// main
int main() {
  int N;
  int T;
  long num_sims;
  int seed;
  std::cout << "Enter the dimension of the percolation grid: ";
  std::cin >> N;
  std::cout << "Enter the number of simulations you want to run: ";
  std::cin >> num_sims;
  std::cout << "Enter the number of simulations between sampling RVs: ";
  std::cin >> T;
  std::cout << "Enter a seed for the random number generator " 
	    << "(Enter -1 to use the clock): ";
  std::cin >> seed;
  if (seed == -1) srand(time(NULL));
  else            srand(seed);
  int num_outer = num_sims / T;
  double avg = 0.0;
  for (long oitter = 0; oitter < num_outer; oitter++) {
    std::cout << "iteration = " << oitter * T + 1 << std::endl;
    percolation_stats perc_stats(N, T);
    std::cout << "mean                    = " << perc_stats.mean() << std::endl;
    std::cout << "stddev                  = " << perc_stats.stddev() 
	      << std::endl;
    std::cout << "95% confidence interval = " << perc_stats.confidence_lo() 
	      << ", " << perc_stats.confidence_hi() << std::endl;
    avg += perc_stats.mean();
  }
  std::cout << "overall mean threshold value: " << avg / num_outer
	    << std::endl;
  return 0;
}

