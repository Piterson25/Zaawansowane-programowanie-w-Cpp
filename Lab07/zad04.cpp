#include <iostream>
#include <vector>

class Vec {
public:
	Vec(const std::vector<int>& t_vec) : m_vec(t_vec) {};
	Vec(const int& num_dimensions) : m_vec(num_dimensions) {};
protected:
	std::vector<int> m_vec;

	void setValue(const int& value, const size_t& index) {
		try {
			this->m_vec[index] = value;
		}
		catch (const std::out_of_range& ex) {
			std::cout << ex.what() << '\n';
		}
	}

	const int getValue(const size_t& index) {
		try {
			return this->m_vec[index];
		}
		catch (const std::out_of_range& ex) {
			std::cout << ex.what() << '\n';
		}
	}

	Vec operator + (const Vec& vector) const {
		if (this->m_vec.size() != vector.m_vec.size()) {
			throw std::invalid_argument("Vectory roznych rozmiarow");
		}
		std::vector<int> temp = this->m_vec;

		for (int i = 0; i < temp.size(); ++i) {
			temp[i] += vector.m_vec[i];
		}
		return Vec(temp);
	}

	Vec operator - (const Vec& vector) const {
		if (this->m_vec.size() != vector.m_vec.size()) {
			throw std::invalid_argument("Vectory roznych rozmiarow");
		}
		std::vector<int> temp = this->m_vec;

		for (int i = 0; i < temp.size(); ++i) {
			temp[i] -= vector.m_vec[i];
		}
		return Vec(temp);
	}

	Vec& operator ++ () {
		for (auto& e : this->m_vec) {
			e++;
		}

		return *this;
	}

	Vec operator * (const Vec& vector) const {
		if (this->m_vec.size() != vector.m_vec.size()) {
			throw std::invalid_argument("Vectory roznych rozmiarow");
		}
		std::vector<int> temp(this->m_vec.size());
		for (int i = 0; i < temp.size(); ++i) {
			temp[i] = this->m_vec[i] * vector.m_vec[i];
		}
		return Vec(temp);
	}

	Vec operator * (const int& scalar) const {
		std::vector<int> temp = this->m_vec;

		for (int i = 0; i < temp.size(); ++i) {
			temp[i] *= scalar;
		}
		return Vec(temp);
	}

	Vec operator / (const int& scalar) const {
		try {
			if (scalar == 0) {
				throw std::exception("Nie mozna dzielic przez 0!");
			}
			std::vector<int> temp = this->m_vec;

			for (int i = 0; i < temp.size(); ++i) {
				temp[i] *= scalar;
			}
			return Vec(temp);
		}
		catch (const std::exception& error) {
			std::cout << error.what() << '\n';
		}
	}

	bool operator == (const Vec& vector) const {
		if (this->m_vec.size() != vector.m_vec.size()) {
			throw std::invalid_argument("Vectory roznych rozmiarow");
		}

		for (int i = 0; i < this->m_vec.size(); ++i) {
			if (this->m_vec[i] != vector.m_vec[i]) {
				return false;
			}
		}

		return true;
	}

	bool operator != (const Vec& vector) const {
		if (this->m_vec.size() != vector.m_vec.size()) {
			throw std::invalid_argument("Vectory roznych rozmiarow");
		}

		for (int i = 0; i < this->m_vec.size(); ++i) {
			if (this->m_vec[i] == vector.m_vec[i]) {
				return false;
			}
		}

		return true;
	}

	friend std::istream& operator >> (std::istream& in, Vec& vector) {
		char tab[3] = { 'X', 'Y', 'Z' };
		for (int i = 0; i < vector.m_vec.size(); ++i) {
			std::cout << "Podaj " << vector.m_vec[i] << ": ";
			int temp;
			in >> temp;
			vector.setValue(temp, i);
		}

		return in;
	}

	friend std::ostream& operator << (std::ostream& out, const Vec& vector) {
		char tab[3] = { 'X', 'Y', 'Z' };
		for (int i = 0; i < vector.m_vec.size(); ++i) {
			out << tab[i] << ':' << vector.m_vec[i] << " ";
		}
		out << '\n';
		return out;
	}

	void print() {
		char tab[3] = { 'X', 'Y', 'Z' };
		for (int i = 0; i < this->m_vec.size(); ++i) {
			std::cout << tab[i] << ':' << this->m_vec[i];
		}
		std::cout << '\n';
	}
};

class Vec1d : public Vec {
public:
	Vec1d(const std::vector<int>& t_vec) : Vec(1) {
		m_vec = t_vec;
	}
};

class Vec2d : public Vec {
public:
	Vec2d(const std::vector<int>& t_vec) : Vec(2) {
		m_vec = t_vec;
	}
};

class Vec3d : public Vec {
public:
	Vec3d(const std::vector<int>& t_vec) : Vec(3) {
		m_vec = t_vec;
	}
};

int main()
{
	Vec1d vec1d({ 1 });
	Vec2d vec2d({ 1, 2 });
	Vec3d vec3d({ 1, 2, 3 });

	std::cout << vec1d;
	std::cout << vec2d;
	std::cout << vec3d;

	return 0;
}