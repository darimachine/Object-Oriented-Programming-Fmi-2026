
#include <iostream>
//#include "h1.h"
#include "h1.cpp"
//!!! NE MOJE DA IMA 2 Implementacii NA FUNKCIQ S EDNO I SUSHTO IME V razlichni cpp failove
// chupi se edinnata kompilacionna edinica trqbva da se sloji static ili anonimen namespace

//! IMAM IMPLEMENTACIQ Õ¿ f() VUV MAIN.CPP I VUV h3.cpp(v h3.cpp idva kato includa-vame h3.h)
//!! Moje da slojim samo deklariq v h3.h i da implementirame f() v h3.cpp,
// togava shte imame f() v main.cpp i f() v h3.cpp otnovo i shte grumne s LINKING greshka
void f() {
	std::cout << "obj";
}


int main() {
	std::cout << "eee";
	//f();
}