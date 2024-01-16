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
  int *dat = new int[]{3, 4};
  unique_ptr<int> t1(dat);
  {
    std::cout << "start block\n";
    std::cout << (t1[0]) << "\n";
    std::cout << "end block\n";
  }
  std::cout << "end"
            << "\n";
  return 0;
}
