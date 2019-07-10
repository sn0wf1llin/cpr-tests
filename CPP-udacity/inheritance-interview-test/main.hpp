#include <iostream>

class Base {
  public:
    Base();
    ~Base();
    virtual void method();
    void ordMethod();
};
Base::Base() {
  std::cout << "constructor Base" << std::endl;
}

Base::~Base() {
  std::cout << "destructor Base" << std::endl;
}

void Base::method() {
  std::cout << "method from Base" << std::endl;
}

void Base::ordMethod() {
  std::cout << "ordinary from Base" << std::endl;
}


class A : public Base {
  public:
    A();
    ~A();
    void method();
    void ordMethod();
};
void A::ordMethod(){
  std::cout << " overlapping ordMethod in A ... " << std::endl;
}

A::A(){
  std::cout << " -- constructor A" << std::endl;
  ordMethod();
}

A::~A(){
  std::cout << " -- destructor A" << std::endl;
  method();
}

void A::method() {
  std::cout << " -- method from A " << std::endl;
}
