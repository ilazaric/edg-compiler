#include <initializer_list>

template<auto N>
void fn() {
  for (auto x : {N, N, N});
/////...../////...../////...../////.....
}

int main() {
  fn<1>();
  // fn<2>();
}
