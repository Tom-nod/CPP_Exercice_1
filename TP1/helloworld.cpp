#include <iostream>

int add(int a, int b) {
  return a + b;
}

void add_to(int& a, int b) {
  a += b;
}

int main() {
    std::string name;
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;

    const int x{10};
    int y = add(x, x);
    add_to(y, 22);
    std::cout << y << std::endl;
    return 0;
}