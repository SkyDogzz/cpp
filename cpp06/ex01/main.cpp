
#include "Serializer.hpp"

static void print_data(const std::string &label, Data *ptr) {
  std::cout << label << " pointer: " << ptr << std::endl;
  if (ptr) {
    std::cout << "  id    : " << ptr->id << std::endl;
    std::cout << "  name  : " << ptr->name << std::endl;
    std::cout << "  value : " << ptr->value << std::endl;
  }
}

static void basic_test() {
  std::cout << "===== Basic test =====" << std::endl;
  Data d;

  d.id = 1;
  d.name = "basic";
  d.value = 42.0;

  print_data("Original", &d);

  uintptr_t raw = Serializer::serialize(&d);
  std::cout << "Serialized uintptr_t: " << raw << std::endl;

  Data *restored = Serializer::deserialize(raw);
  print_data("Restored", restored);

  if (restored == &d)
    std::cout << "OK: Restored pointer matches original" << std::endl;
  else
    std::cout << "ERROR: Restored pointer does NOT match original" << std::endl;
}

static void multiple_objects_test() {
  std::cout << "\n===== Multiple objects test =====" << std::endl;

  Data a;
  Data b;
  Data c;

  a.id = 10;
  a.name = "alpha";
  a.value = 1.5;

  b.id = 20;
  b.name = "beta";
  b.value = -3.14;

  c.id = 30;
  c.name = "gamma";
  c.value = 0.001;

  Data *arr[3] = {&a, &b, &c};
  const char *labels[3] = {"A", "B", "C"};

  for (int i = 0; i < 3; ++i) {
    std::cout << "\n--- Object " << labels[i] << " ---" << std::endl;
    print_data("Original", arr[i]);
    uintptr_t raw = Serializer::serialize(arr[i]);
    std::cout << "Serialized: " << raw << std::endl;
    Data *restored = Serializer::deserialize(raw);
    print_data("Restored", restored);
    if (restored == arr[i])
      std::cout << "OK: pointer matches" << std::endl;
    else
      std::cout << "ERROR: pointer mismatch" << std::endl;
  }
}

static void dynamic_test() {
  std::cout << "\n===== Dynamic allocation test =====" << std::endl;

  Data *ptr = new Data;
  ptr->id = 999;
  ptr->name = "heap";
  ptr->value = 123.456;

  print_data("Original (heap)", ptr);

  uintptr_t raw = Serializer::serialize(ptr);
  std::cout << "Serialized: " << raw << std::endl;

  Data *restored = Serializer::deserialize(raw);
  print_data("Restored (heap)", restored);

  if (restored == ptr)
    std::cout << "OK: pointer matches" << std::endl;
  else
    std::cout << "ERROR: pointer mismatch" << std::endl;

  delete ptr;
}

int main() {
  basic_test();
  multiple_objects_test();
  dynamic_test();
  return 0;
}
