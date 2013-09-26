// stats.cpp: 

// system includes
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <climits>
#include <limits>
#include <cfloat>
// local includes
#include "stats.h"

stats::stats() {}
stats::~stats() {}

// returns the maximum value in the array a[]
double stats::max(std::vector<double> a) {
  double maxx = DBL_MIN;
  for (unsigned int i = 0; i < a.size(); i++) 
    maxx = (maxx < a[i] ? a[i] : maxx);
  return maxx;
}


// returns the maximum value in the subarray a[lo...hi]
double stats::max(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  double maxx = DBL_MIN;
  for (unsigned int i = lo; i <= hi; i++)
    maxx = (maxx < a[i] ? a[i] : maxx);
  return maxx;
}

int stats::max(std::vector<int> a) {
  int maxx = INT_MIN;
  for (unsigned int i = 0; i < a.size(); i++) 
    maxx = (maxx < a[i] ? a[i] : maxx);
  return maxx;
}

int stats::max(std::vector<int> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  int maxx = INT_MIN;
  for (unsigned int i = lo; i <= hi; i++)
    maxx = (maxx < a[i] ? a[i] : maxx);
  return maxx;
}

// returns the minimum value in the array a[]
double stats::min(std::vector<double> a) {
  double minn = DBL_MAX;
  for (unsigned int i = 0; i < a.size(); i++)
    minn = (minn < a[i] ? minn : a[i]);
  return minn;
}

// returns the minimum value in the subarray a[lo...hi]
double stats::min(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  double minn = DBL_MAX;
  for (unsigned int i = lo; i <= hi; i++) 
    minn = (minn < a[i] ? minn : a[i]);
  return minn;
}

int stats::min(std::vector<int> a) {
  int minn = INT_MAX;
  for (unsigned int i = 0; i < a.size(); i++) 
    minn = (minn < a[i] ? minn : a[i]);
  return minn;
}

int stats::min(std::vector<int> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  int minn = INT_MAX;
  for (unsigned int i = lo; i <= hi; i++) 
    minn = (minn < a[i] ? minn : a[i]);
  return minn;
}

// returns the mean, or average, of the values in a[]
double stats::mean(std::vector<double> a) {
  double meann = 0.0;
  for (unsigned int i = 0; i < a.size(); i++)
    meann += a[i];
  return meann / a.size();
}

// returns the mean, or average, of the values in the subarray a[lo...hi]
double stats::mean(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  double meann = 0.0;
  for (unsigned int i = lo; i <= hi; i++) 
    meann += a[i];
  return meann / (hi - lo + 1);
}

double stats::mean(std::vector<int> a) {
  if (a.size() == 0) return std::numeric_limits<double>::quiet_NaN();
  double meann =0.0;
  for (unsigned int i = 0; i <= a.size(); i++) 
    meann += a[i];
  return  (double) meann / a.size();
}

double stats::mean(std::vector<int> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  if (a.size() == 0) return std::numeric_limits<double>::quiet_NaN();
  double meann = 0;
  for (unsigned int i =lo; i <= hi; i++) 
    meann += a[i];
  return (double) meann / (hi - lo + 1);
}

// returns the sample variance in the array a[]
double stats::var(std::vector<double> a) {
  if (a.size() == 0) return std::numeric_limits<double>::quiet_NaN();
  double avg = mean(a);
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); i++) 
    sum += (a[i] - avg) * (a[i] - avg);
  return sum / (a.size() - 1);
}

// returns the sample variance in the subarray a[lo...hi]
double stats::var(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi > a.size() || lo > hi) {
    std::cout << "Subarray indices are out of bounds" << std::endl;
    exit(1);
  }
  if (a.size() == 0) return std::numeric_limits<double>::quiet_NaN();
  double avg = mean(a);
  double sum = 0.0;
  for (unsigned int i = lo; i <= hi; i++) 
    sum += (a[i] - avg) * (a[i] - avg);
  return sum / (a.size() - 1);
}

// returns the population variance in the array a[]. 
double stats::varp(std::vector<double> a) {
  if (a.size() == 0) return std::numeric_limits<double>::quiet_NaN();
  double avg = mean(a);
  double sum = 0.0;
  for (unsigned int i = 0; i < a.size(); i++) 
    sum += (a[i] - avg) * (a[i] - avg);
  return sum / a.size();
}

// returns the population variance in the subarray a[lo...hi]
double stats::varp(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi >= a.size() || lo > hi) {
    std::cout << "Subarray indices out of bounds" << std::endl;
    exit(1);
  }
  if (hi - lo + 1 == 0) return std::numeric_limits<double>::quiet_NaN();
  double avg = mean(a, lo, hi);
  double sum = 0.0;
  for (unsigned int i = lo; i <= hi; i++) 
    sum += (a[i] - avg) * (a[i] - avg);
  return sum / (hi - lo + 1);
}

// returns the sample standard deviation in the array a[]
double stats::stddev(std::vector<double> a) {
  return sqrt(var(a));
}

// returns the sample standard deviation in the subarray a[lo...hi]
// returns NaN if there is no such number
double stats::stddev(std::vector<double> a, unsigned int lo, unsigned int hi) {
  return sqrt(var(a, lo, hi));
}

//double stats::stddev(std::vector<int> a) {
//  return sqrt(var(a));
//}

// returns the population standard deviation in the array a[]. Returns 
// NaN if no such number
double stats::stddevp(std::vector<double> a) {
  return sqrt(varp(a));
}

// returns the population standard deviation in the subarray a[lo...hi]
double stats::stddevp(std::vector<double> a, unsigned int lo, unsigned int hi) {
  return sqrt(varp(a, lo, hi));
}

// returns the sum of all the values in the array a[]
double stats::sum(std::vector<double> a) {
  double sum = 0.0;
  for (unsigned int i =0; i < a.size(); i++) 
    sum += a[i];
  return sum;
}

// returns the sum of all the values in the subarray a[lo...hi]
double stats::sum(std::vector<double> a, unsigned int lo, unsigned int hi) {
  if (lo < 0 || hi >= a.size() || lo > hi) {
    std::cout << "Subarray indices out of bounds" << std::endl;
    exit(1);
  }
  double sum = 0.0;
  for (unsigned int i = lo; i <= hi; i++)
    sum += a[i];
  return sum;
}

int stats::sum(std::vector<int> a) {
  int sum = 0;
  for (unsigned int i = 0; i < a.size(); i++)
    sum += a[i];
  return sum;
}

// writes points to a file currently called output.txt. Will have to 
// revise this at a later time
void stats::plot(std::vector<double> a) {
  unsigned int N = a.size();
  std::ofstream out("output.txt");
  for (unsigned int i = 0; i < N; i++) 
    out << i << " " << a[i] << "\n";
}

  


	 
  
	       
