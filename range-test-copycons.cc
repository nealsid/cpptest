#include <iostream>
#include <algorithm>
#include <ranges>
#include <print>
#include <vector>
#include <execution>

using namespace std;

// #define STRING2(x) #x
// #define STRING(x) STRING2(x)
// #pragma message "var = " STRING(_LIBCPP_STD_VER)
class MyObj {
public:
  MyObj(int a) :
    foo(a) {
    //    std::println("Construct {}", foo);
  }

  MyObj& operator=(const MyObj& other){
    this->foo = other.foo;
    return *this;
  }

  MyObj(const MyObj& myObj) {
    //    std::println("Copy construct {}", myObj.foo);
    this->foo = myObj.foo;
  }

  MyObj(MyObj&& myObj) noexcept {
    std::println("Move construct {}", myObj.foo);
    this->foo = myObj.foo;
  }

  int foo;
};

int main() {
  int numElements = 500000000;
  vector<MyObj> v;
  v.reserve(numElements);
  for (int i = 0 ; i < numElements; ++i) {
    v.emplace_back(i);
  }

  auto is_odd = [&](const auto& obj) {
    return obj.foo % 2 == 1;
  };

  auto new_obj_double_foo = [&](const auto& obj) {
    return MyObj{obj.foo*2};
  };

  vector<MyObj> out;
  out.reserve(numElements);
  using std::execution::par;
  std::transform(execution::par,
		 v.begin(),
		 v.end(),
		 out.begin(),
		 new_obj_double_foo);
  // for (const auto a : v |
  // 	 views::filter(is_odd) |
  // 	 views::transform(new_obj_double_foo)) {
  //   println("{}", a.foo);
  // }
}

  
