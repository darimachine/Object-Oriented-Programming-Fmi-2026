        // #include  <iostream>
        // #include  <fstream>
        // using namespace std;
        //
        // bool isPrime(int number)
        // {
        //     if (number == 2) return true;
        //     if (number % 2 ==0) return false;
        //
        //     for (int i = 3 ; i <= number / 2; i++)
        //     {
        //         if (number % i ==0)
        //         {
        //             return  false;
        //         }
        //     }
        //     return  true;
        // }
        // void proccessFile(const char* fileName)
        // {
        //     ifstream inFile(fileName, ios::binary);
        //
        //     if (!inFile.is_open())
        //         return;
        //
        //     ofstream writePrime("prime.dat", ios::binary);
        //     ofstream writeCompelex("complex.dat", ios::binary);
        //
        //     if (!writeCompelex.is_open() || !writePrime.is_open())
        //     {
        //         inFile.close();
        //         return;
        //     }
        //
        //     int number;
        //     while (inFile.read((char*)&number, sizeof(int)))
        //     {
        //         if (number == 0 || number == 1)
        //             continue;
        //
        //         if (isPrime(number))
        //         {
        //             writePrime.write((const char*)&number, sizeof(int));
        //         }
        //         else
        //         {
        //             writeCompelex.write((const char*)&number, sizeof(int));
        //         }
        //     }
        //     inFile.close();
        //     writeCompelex.close();
        //     writePrime.close();
        // }
        // int main()
        // {
        //     ofstream out("numbers.dat", ios::binary);
        //     for (int i = 2; i <= 20; i++) {
        //         out.write((const char*)&i, sizeof(int));
        //     }
        //     out.close();
        //
        //     proccessFile("numbers.dat");
        //
        //     ifstream inPrime("prime.dat", ios::binary);
        //     int p;
        //     cout << "Primes found: ";
        //     while(inPrime.read((char*)&p, sizeof(int))) {
        //         cout << p << " ";
        //     }
        //     inPrime.close();
        //     return  0;
        // }