// random.cpp

//system includes
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
// local includes 
#include "random.h"

#define PI 3.14159265359

long random::seed = time(NULL);

void random::set_seed(long n) {
  seed = n;
  srand(seed);
}

long random::get_seed() {
  return seed;
}

// generates a uniform random number in [0, 1)
double random::uniform() {
  return (double) rand() / ( (long) RAND_MAX + 1);
}

// returns a random integer between 0 (inclusive) and N (exclusive)
int random::uniform(int N) {
  return rand() % N;
}

// returns a random number in [a, b)
double random::uniform(double a, double b) {
  return a + uniform() * (b - a);
}

double random::uniform(int a, int b) {
  return a + uniform() * (b - a);
}

int random::uniform_int(int a, int b) {
  return a + uniform(b - a);
}

// returns true with probability p, and false otherwise
bool random::bernoulli(double p) {
  return uniform() < p;
}

// returns true with probability 0.5. 
bool random::bernoulli() {
  return bernoulli(0.5);
}

// return a real number with a standard gaussian distribution
double random::gaussian() {
  double r, x, y;
  // Polar form of the Box-Muller transform
  // have to execute the transform at least once
  do {
    x = uniform(-1.0, 1.0);
    y = uniform(-1.0, 1.0);
    r = x * x + y * y;
  } while (r >= 1 || r == 0);
  return x * sqrt(-2 * log(r) / r);
}

// standard method for returning a Gaussian with mean and stddev
double random::gaussian(double mean, double stddev) {
  return mean + stddev * random::gaussian();
}


// return an integer with a geometric distribution with mean 1/p
int random::geometric(double p) {
  return (int) ceil(log(uniform()) / log(1.0 - p));
}

// return a real number with a Pareto distribution with parameter alpha
double random::pareto(double alpha) {
  return pow(1 - uniform(), -1.0 / alpha) - 1.0;
}

// return a real number with a Cauchy distribution
double random::cauchy() {
  return tan(PI * uniform() - 0.5);
}

int random::discrete(std::vector<double> a) {
  double EPSILON = 1E-14;
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); i++) {
    if (a[i] < 0.0) { 
      std::cout << "array entry " << i << " is negative: " << a[i] << "\n";
      std::cout << "Exiting..." << std::endl;
      exit(1);
    }
    sum += a[i];
  }
  if (sum > 1.0 + EPSILON || sum < 1.0 - EPSILON) {
    std::cout << "sum of array entries not equal to one: " << sum << "\n";
    std::cout << "Exiting..." << std::endl;
    exit(1);
  }
  
  while (true) {
    double r = uniform();
    sum = 0.0;
    for (unsigned int i = 0; i < a.size(); i++) {
      sum += a[i];
      if (sum > r) return i;
    }
  }
}

// return a real number from an exponential distribution with rate lambda
double random::exponential(double lambda) {
  return log(1.0 - uniform()) / lambda;
}

// A very elegent shuffling algorithm
template <class T>
void random::shuffle(std::vector<T>& a) {
  int N = a.size();
  for (int i =0; i < N; i++) {
    int j = i + uniform(N - i);
    T swap = a[i];
    a[i] = a[j];
    a[j] = swap;
  }
}

template <class T>
void random::shuffle(std::vector<T>& a, int lo, int hi) {
  if (lo < 0 || lo > hi || hi >= a.size()) {
    std::cout << "Illegal subarray range" << std::endl;
    exit(1);
  }
  for (int i = lo; i <= hi; i++) {
    int j = i + uniform(hi - i + 1);  // uniform between i and hi
    T swap = a[i];
    a[i] = a[j];
    a[j] = swap;
  }
}
