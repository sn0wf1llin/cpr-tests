#include <iostream>
#include "factorial.h"

int main(int argc, char* argv[]) {
  int N = 12;
  std::string test = "test";
  std::cout << "Value for testting = " << N << std::endl;
  std::cout << "Result = " << Factorial(test, N) << std::endl;
  return 0;
}
