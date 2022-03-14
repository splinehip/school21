#include <iostream>
#include <stdlib.h>

#include "Point.hpp"

int	main(int argc, char **argv)
{
	Point	a(0, 0);
	Point	b(20, 0);
	Point	c(10, 30);
	Point	*to_check;

	if (argc == 3)
		to_check = new Point(atoi(argv[1]), atoi(argv[2]));
	else
		to_check = new Point(10, 20);
	std::cout << "Triangle has vertices:" << std::endl
		<< " a(" << a.get_x() << ", " << a.get_y() << ")" << std::endl
		<< " b(" << b.get_x() << ", " << b.get_y()<< ")" << std::endl
		<< " c(" << c.get_x() << ", " << c.get_y()<< ")" << std::endl;
	std::cout << "Point to check x: " << to_check->get_x()
		<< ", y: " << to_check->get_y() << std::endl;
	std::cout << "Point is in the triangle: "
		<< std::boolalpha << bsp(a, b, c, *to_check) << std::endl;
	return 0;
}
