#include <iostream>
#include "Point.h"

int main()
{
	Point point1;
	std::cout << point1.toString() << '\n';
	point1.set_xy(1, 1);
	std::cout << point1.toString() << '\n';

	std::cout << "------------------------------\n";

	Point point2(4, 7);
	std::cout << point2.toString() << '\n';
	point2.set_xy(14, 17);
	std::cout << point2.toString() << '\n';

	std::cout << "------------------------------\n";

	Point point3 = point2;
	std::cout << point3.toString() << '\n';
	point3.set_xy(34, 37);
	std::cout << point2.toString() << '\n';
	std::cout << point3.toString() << '\n';

	std::cout << "------------------------------\n";

	Point point4;
	point4 = point3;
	std::cout << point4.toString() << '\n';
	point4.set_xy(24, 27);
	std::cout << point3.toString() << '\n';
	std::cout << point4.toString() << '\n';

	std::cout << "------------------------------\n";

	Point point5(std::move(point4));
	std::cout << point5.toString() << '\n';

	std::cout << "------------------------------\n";


	return 0;
}