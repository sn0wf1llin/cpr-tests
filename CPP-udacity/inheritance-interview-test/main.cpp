#include "main.hpp"

int main() {
  Base *e = new Base;
  e = new A;
  e->ordMethod();
  e->method();

  return 0;
}
