/*---------------------------------------------------------------------------
 | Michael James Gilbert
 | michael.james.gilbert@gmail.com
 | Last Updated: 9/24/2013 6:38 AM GMT
 | 
 | random.h is a class of static methods to generate pseudo-random numbers
 | from different distributions.  
 |---------------------------------------------------------------------------*/

#ifndef __RANDOM__HH
#define __RANDOM__HH

class random {
 private: 
  static long seed;
  
 public:
  // prototypes
  static void   set_seed(long s);
  static long   get_seed();
  static double uniform();
  static int    uniform(int N);
  static double uniform(double a, double b);
  static double uniform(int a, int b);
  static int    uniform_int(int a, int b);
  static bool   bernoulli(double p);
  static bool   bernoulli();
  static double gaussian();
  static double gaussian(double mean, double stddev);
  static int    geometric(double p);
  static int    poisson(double lambda);
  static double pareto(double alpha);
  static double cauchy();
  static int    discrete(std::vector<double> a);
  static double exponential(double lambda);
  template <class T>
  static void   shuffle(std::vector<T>& a);
  static void   shuffle(double a[]);
  static void   shuffle(int * a);
  template <class T>
  static void   shuffle(std::vector<T>& a, int lo, int hi);
  static void   shuffle(double * a, int lo, int hi);
  static void   shuffle(int * a, int lo, int hi);
}; // end of class prototypes


#endif
