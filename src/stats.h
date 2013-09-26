/*---------------------------------------------------------------------------
| Michael James Gilbert
| michael.james.gilbert@gmail.com
| Last Updated: 9/24/2013 3:11 PM GMT
|----------------------------------------------------------------------------

General statistics: a static library full of functions for calculating 
some important statistical quantities
*/

#ifndef __STATS__HH
#define __STATS__HH

class stats {
 private:
  stats();
  ~stats();
 public:
  static double max(std::vector<double> a);
  static double max(std::vector<double> a, unsigned int lo, unsigned int hi);
  static int    max(std::vector<int> a);
  static int    max(std::vector<int> a, unsigned int lo, unsigned int hi);
  static double min(std::vector<double> a);
  static double min(std::vector<double> a, unsigned int lo, unsigned int hi);
  static int    min(std::vector<int> a);
  static int    min(std::vector<int> a, unsigned int lo, unsigned int hi);
  static double mean(std::vector<double> a);
  static double mean(std::vector<double> a, unsigned int lo, unsigned int hi);
  static double mean(std::vector<int> a);
  static double mean(std::vector<int> a, unsigned int lo, unsigned int hi);
  static double var(std::vector<double> a);
  static double var(std::vector<double> a, unsigned int lo, unsigned int hi);
  static double var(std::vector<int> a);
  static double varp(std::vector<double> a);
  static double varp(std::vector<double> a, unsigned int lo, unsigned int hi);
  static double stddev(std::vector<double> a);
  static double stddev(std::vector<double> a, unsigned int lo, unsigned int hi);
  static double stddev(std::vector<int> a);
  static double stddevp(std::vector<double> a);
  static double stddevp(std::vector<double> a, unsigned int lo, unsigned int hi);
  static double sum(std::vector<double> a);
  static double sum(std::vector<double> a, unsigned int lo, unsigned int hi);
  static int    sum(std::vector<int> a);
  static void   plot(std::vector<double> a);
}; // end of class prototype

#endif
