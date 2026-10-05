struct S { int x, y, z; };

int main() {
  auto [...xs] = S{};
  // "ex3.cpp", line 4: error: a structured binding pack can only be declared inside
  //          a template
  // ec_non_template_structured_binding_pack
  
}
