// a test client for percolation class

// system includes 
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
// local includes
#include "percolation.h"
#include "random.h"

int main() {
  std::cout << "Enter grid size: ";
  int N;
  std::cin >> N;
  std::cout << "Enter a seed for the random number generator (-1 for clock): ";
  long seed;
  std::cin >> seed;
  if (seed == -1)
    srand(time(NULL));
  else 
    srand(seed);
  std::ofstream out("sample.txt");
  percolation perc(N);
  int count = 0;
  while (!perc.percolates()) {
    int i = random::uniform(1, N + 1);
    int j = random::uniform(1, N + 1);
    if (!perc.is_open(i, j)) {
      perc.open(i, j); 
      out << i << " " << j << "\n";
    }
    else continue;
    count++;
  }
  double threshold = (double) count / (N * N);
  std::cout << "threshold = " << threshold << std::endl;
  return 0;
}
