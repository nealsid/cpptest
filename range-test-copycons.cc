#include <iostream>
#include <algorithm>
#include <ranges>
#include <print>
#include <vector>

using namespace std;

class MyObj {
public:
  MyObj(int a) :
    foo(a) {
    std::println("Construct {}", foo);
  }

  MyObj(const MyObj& myObj) {
    std::println("Copy construct {}", myObj.foo);
    this->foo = myObj.foo;
  }

  MyObj(MyObj&& myObj) noexcept {
    std::println("Move construct {}", myObj.foo);
    this->foo = myObj.foo;
  }

  int foo;
};

int main() {
  vector<MyObj> v;
  v.reserve(10);
  for (int i = 0 ; i < 10; ++i) {
    v.emplace_back(i);
  }

  auto is_odd = [&](const auto& obj) {
    return obj.foo % 2 == 1;
  };

  auto new_obj_double_foo = [&](const auto& obj) {
    return MyObj{obj.foo*2};
  };

  for (const auto a : v |
	 views::filter(is_odd) |
	 views::transform(new_obj_double_foo)) {
    println("{}", a.foo);
  }
}

  
