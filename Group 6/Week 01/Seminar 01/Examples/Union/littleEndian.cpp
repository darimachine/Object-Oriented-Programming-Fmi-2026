#include <iostream>
using std::cout;
bool isLittleEndian() {
	union LittleEndian {
		int n = 1;
		unsigned char bytes[4];
	} instance;
	return instance.bytes[0];
}
int main() {
	cout << isLittleEndian();
}