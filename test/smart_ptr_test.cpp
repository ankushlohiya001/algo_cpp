#include "unique_ptr.hpp"
#include <iostream>

struct Test {
  int val;

public:
  Test(int v) : val(v) { std::cout << "created #" << val << "!!\n"; }

  ~Test() { std::cout << "deleted #" << val << "!!\n"; }

  // deleter for Test
  struct Deleter {
    void operator()(Test *ref) {
      std::cout << "freeing!!\n";
      delete ref;
    }
  };

  void test() { std::cout << "working!!\n"; }
};

int main() {
  unique_ptr<Test> t1(new Test(1));
  {
    t1 = unique_ptr<Test>(new Test(2));
    /* unique_ptr<Test> t2 = t1; */
    /* t1 = t2; */
    std::cout << "start block\n";
    std::cout << "end block\n";
  }
  std::cout << "end"
            << "\n";
  return 0;
}
