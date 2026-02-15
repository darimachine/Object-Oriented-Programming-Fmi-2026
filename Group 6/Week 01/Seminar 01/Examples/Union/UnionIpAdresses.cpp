#include <iostream>
using namespace std;
union IpAddress
{
	/*
		This union allows us to represent an IPv4 address in two different ways:

		As a single 32-bit integer (uint32_t address).
		As four separate bytes (unsigned char octets[4]).
		This allows you to interpret the same memory as either a whole number or as individual octets of an IP address.
	*/
	uint32_t address;
	unsigned char octets[4];
};

int main()
{
	IpAddress myAddress;
	myAddress.address = 16777343; // IN HEX: 0100007F
	// SO we are working in Little Endian and in the memory it looks like this:
	// 7F|00|00|01|
	std::cout << (int)myAddress.octets[0] << "."
		<< (int)myAddress.octets[1] << "."
		<< (int)myAddress.octets[2] << "."
		<< (int)myAddress.octets[3];
}