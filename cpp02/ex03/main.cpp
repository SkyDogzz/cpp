#include "Point.hpp"

#include <iostream>

int main(void) {
	Point a(0, 0);
	Point b(0, 10);
	Point c(10, 0);

	Point p1(2, 2);
	Point p2(1, 5);
	Point p3(3, 3);
	Point p4(5, 6);
	Point p5(0, 11);
	Point p6(11, 0);

	std::cout << "p1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4: " << bsp(a, b, c, p4) << std::endl;
	std::cout << "p5: " << bsp(a, b, c, p5) << std::endl;
	std::cout << "p6: " << bsp(a, b, c, p6) << std::endl;

	return 0;
}
