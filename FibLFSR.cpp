#include <iostream>
#include <sstream>
#include <string>
#include "FibLFSR.hpp"

// constructor to implement file for class
FibLFSR::FibLFSR(std::string seed, int t)
{
  //to set initial seed and tap position

  bits = seed;
  tap = t;
}

int FibLFSR::step()
{
  // to find index of tap position
  int tap_pos = bits.length() - tap - 1;

  // XOR the tap position with the left most bit
  int res = bits[0] ^ bits[tap_pos];

  // shift all the bits to left
  std::string::size_type i;
  std::ostringstream ostring;   

  // to shift everything left.
  for(i = 0; (unsigned)i < bits.length() - 1; i++)
  {
    ostring << bits[i + 1];
  }

  // to append the XOR result
  ostring << res;

  // Save the updated string - ostring.str() converts

 bits = ostring.str();

  // Return the XOR result bit
  return res;
}


// simulates k steps
int FibLFSR::generate(int k)
{
  // Intialize variable to zero.
  int x = 0;

  for(int i = 0; i < k; i++)
  {
    x = (x * 2) + step();
  }

  return x;
}


// returns a string rep. of the FibLFSR
std::ostream& operator<< (std::ostream &out, FibLFSR &cLFSR)
{
  out << cLFSR.bits;
  return out;
}
