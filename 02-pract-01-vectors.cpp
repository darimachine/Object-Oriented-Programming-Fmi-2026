#include <iostream>
#include <print>

struct Vector3D {
    int x;
	int y;
	int z;


	void print() const {
		std::println("({}, {}, {})", x, y, z);
	}
};

Vector3D add(const Vector3D& a, const Vector3D& b) {
	return {a.x + b.x, a.y + b.y, a.z + b.z};
}

bool areLinearDependent(const Vector3D& a, const Vector3D& b) {
	return a.x * b.y == a.y * b.x && a.x * b.z == a.z * b.x && a.y * b.z == a.z * b.y;
}

int main()
{
	Vector3D v1{ 1, 2, 3 };
	Vector3D v2{ 4, 5, 6 };
	Vector3D v3 = add(v1, v2);

	v1.print();
	v2.print();
	std::print("Sum of v1 and v2 is: ");
	v3.print();

	Vector3D v4{ 2, 4, 6 };
	v4.print();

	std::println("v1 and v4 are linear dependent: {}", areLinearDependent(v1, v4));
}