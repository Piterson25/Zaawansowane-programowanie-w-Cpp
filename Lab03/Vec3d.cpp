#include <iostream>

class Vec3d {
public:
	int _x = 0;
	int _y = 0;
	int _z = 0;

	Vec3d(int x, int y, int z) : _x(x), _y(y), _z(z) {}

	Vec3d operator + (const Vec3d& vector) const {
		return Vec3d(this->_x + vector._x, this->_y + vector._y, this->_z + vector._z);
	}

	Vec3d operator - (const Vec3d& vector) const {
		return Vec3d(this->_x - vector._x, this->_y - vector._y, this->_z - vector._z);
	}

	Vec3d& operator ++ () {
		this->_x++;
		this->_y++;
		this->_z++;

		return *this;
	}

	Vec3d operator * (const Vec3d& vector) const {
		return Vec3d(this->_y * vector._z - this->_z * vector._y, this->_z * vector._x - this->_x * vector._z, this->_x * vector._y - this->_y * vector._x);
	}

	bool operator == (const Vec3d& vector) const {
		return this->_x == vector._x && this->_y == vector._y && this->_z == vector._z;
	}

	bool operator != (const Vec3d& vector) const {
		return this->_x != vector._x && this->_y != vector._y && this->_z != vector._z;
	}

	void print() {
		std::cout << "X:" << this->_x << ", Y:" << this->_y << ", Z:" << this->_z << '\n';
	}

};

int main()
{
	Vec3d vec1(5, 4, 3);
	Vec3d vec2(2, 1, 6);

	Vec3d vec3 = vec1 + vec2;
	Vec3d vec4 = vec1 - vec2;
	Vec3d vec5 = ++vec1;
	Vec3d vec6 = vec1 * vec2;

	std::cout << "vec3 = ";
	vec3.print();
	std::cout << "vec4 = ";
	vec4.print();
	std::cout << "vec5 = ";
	vec5.print();
	std::cout << "vec6 = ";
	vec6.print();

	if (vec1 == vec2) {
		std::cout << "vec1 i vec2 sa rowne\n";
	}
	else {
		std::cout << "vec1 i vec2 nie sa rowne\n";
	}

	if (vec1 != vec2) {
		std::cout << "vec1 i vec2 nie sa rowne\n";
	}
	else {
		std::cout << "vec1 i vec2 sa rowne\n";
	}

	return 0;
}