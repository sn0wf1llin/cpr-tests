#include "factorial.h"

int Factorial(std::string s, int n) {
  if ( n == 1 ) {
    return 1;
  } else {
    return n * Factorial( s, n - 1 );
  }
}
