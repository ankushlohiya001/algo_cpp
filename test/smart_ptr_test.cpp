#include "unique_ptr.hpp"
#include <iostream>

struct Test {
public:
  Test() { std::cout << "created!!\n"; }

  ~Test() { std::cout << "deleted!!\n"; }

  // deleter for Test
  struct Deleter {
    void operator()(Test *ref) {
      std::cout << "freeing!!\n";
      delete ref;
    }
  };
};

int main() {
  {
    unique_ptr<Test, Test::Deleter> t1;
    std::cout << "start block\n";
    t1 = make_unique<Test, Test::Deleter>();

    std::cout << "end block\n";
  }
  std::cout << "end"
            << "\n";
  return 0;
}
