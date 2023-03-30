#include <iostream>

class Vec3d {
public:
	void setX(const int& X) {
		this->_x = X;
	}
	void setY(const int& Y) {
		this->_y = Y;
	}
	void setZ(const int& Z) {
		this->_z = Z;
	}

	const int getX() const {
		return this->_x;
	}
	const int getY() const {
		return this->_y;
	}
	const int getZ() const {
		return this->_z;
	}

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

	Vec3d operator * (int scalar) const {
		return Vec3d(this->_x * scalar, this->_y * scalar, this->_z * scalar);
	}

	Vec3d operator / (int scalar) const {
		try {
			if (scalar == 0) {
				throw std::exception("Nie mozna dzielic przez 0!");
			}
			return Vec3d(this->_x / scalar, this->_y / scalar, this->_z / scalar);
		}
		catch (const std::exception& error) {
			std::cout << error.what() << '\n';
			throw;
		}
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
private:
	int _x = 0;
	int _y = 0;
	int _z = 0;

};

std::istream& operator >> (std::istream& in, Vec3d& vector) {
	std::cout << "Podaj X: ";
	int a;
	in >> a;
	vector.setX(a);
	std::cout << "Podaj Y: ";
	in >> a;
	vector.setY(a);
	std::cout << "Podaj Z: ";
	in >> a;
	vector.setZ(a);

	return in;
}

std::ostream& operator << (std::ostream& out, const Vec3d& vector) {
	return out << "X:" << vector.getX() << ", Y:" << vector.getY() << ", Z:" << vector.getZ() << '\n';;
}

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

	Vec3d vec7(0, 0, 0);
	std::cin >> vec7;
	std::cout << vec7;

	Vec3d vec8(3,5,6);
	Vec3d vec9 = vec8 * 5;
	Vec3d vec10 = vec8 / 2;
	Vec3d vec11 = vec8 / 0;

	return 0;
}