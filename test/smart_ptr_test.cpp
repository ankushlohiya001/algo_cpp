#include "smart_ptr.hpp"
#include <iostream>

struct Test {
public:
  Test() { std::cout << "created!!\n"; }

  ~Test() { std::cout << "deleted!!\n"; }
};

int main() {
  {
    unique_ptr<Test> t1;
    std::cout << "block started!!\n";
    t1 = unique_ptr<Test>(new Test);
    std::cout << "block ended!!\n";
  }

  std::cout << "prog ended\n";
  return 0;
}
