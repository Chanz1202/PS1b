#ifndef FibLFSR_HPP
#define FibLFSR_HPP
#include <iostream>
class FibLFSR 
{
public:
  FibLFSR(std::string seed, int t);    
  int step();                       
  int generate(int k);              

  friend std::ostream& operator<< (std::ostream &out, FibLFSR &cLFSR);

private:
  std::string bits; // holds FibLFSR bits               
  int tap;
};

#endif
