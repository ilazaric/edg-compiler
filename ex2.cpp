#include <initializer_list>

template<auto... N>
void fn() {
  for (auto x : {1, N..., 3});
/////...../////...../////...../////.....
}

int main() {
  fn<6, 7>();
  // fn<2>();
}
