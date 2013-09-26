/*----------------------------------------------------------------------------
 | Michael James Gilbert
 | michael.james.gilbert@gmail.com
 | 
 | union_find.cpp : implements a union-find algorithm weighted by tree height
 | test with client uf_test.cpp
 |---------------------------------------------------------------------------*/


#ifndef __UNION_FIND_HH
#define __UNION_FIND_HH

class union_find {
  private:
    int * id;               // id[i] = parent of object i
    int * ht;               // ht[i] = height of subtree rooted at i
    int count;              // number of components

  public:
    union_find(int N);
    ~union_find();
    int num_components();
    int find(int &p);
    bool connected(int p, int q);
    void unite(int p, int q);

}; // end of class prototype
    

#endif
