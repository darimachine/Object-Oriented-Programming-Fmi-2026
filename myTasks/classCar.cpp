// #include <iostream>
// #include<cstring>
// #include<print>
//
// const int MIN_MANUFACTURE_YEAR = 2000;
// const int MIN_MAX_SPEED = 10;
//
//
// struct Car
// {
//     private:
//     char *brand = nullptr;
//     int manifactYear = 0;
//     int maxSpeed = 0;
//     int * distance = nullptr;
//     int tripsCount = 0;
//
//     public:
//     Car()
//     {}
//
//     Car(const char* inpBrand, int inpManYear, int inpMaxSpeed,const int *inpDistance, int inpTripsCount)
//     {
//         setBrand(inpBrand);
//         setManufactureYear(inpManYear);
//         setMaxSpeed(inpMaxSpeed);
//         setDistance(inpDistance, inpTripsCount);
//     }
//
//     ~Car()
//     {
//         delete [] distance;
//         delete [] brand;
//     }
//     void setBrand(const char *inpBrand)
//     {
//         if (!inpBrand)
//         {
//             std::println("You have not entered a brand's name");
//             return;
//         }
//
//         delete [] brand;
//
//         size_t inpBrandLen = strlen(inpBrand);
//         brand  = new char[inpBrandLen + 1];
//         strcpy(brand, inpBrand);
//         brand[inpBrandLen] = '\0';
//     }
//
//     const char * getBrand() const
//     {
//         return this->brand;
//     }
//
//     void setManufactureYear(int manYear)
//     {
//         if (manYear < MIN_MANUFACTURE_YEAR)
//         {
//             std::println("The inputed manufacture year does not meet the requirements");
//             return;
//         }
//
//         this->manifactYear = manYear;
//     }
//
//     int getManYear() const
//     {
//         return manifactYear;
//     }
//
//     void setMaxSpeed(const int inpMaxSpeed)
//     {
//         if (inpMaxSpeed < MIN_MAX_SPEED)
//         {
//             std::println("The max speed of the car can not be less than 10 km/h");
//             return;
//         }
//         maxSpeed = inpMaxSpeed;
//     }
//
//     int getMaxSpeed() const
//     {
//         return maxSpeed;
//     }
//
//     void setDistance(const int * inpDistance, int size)
//     {
//         if (!inpDistance || size <0)
//         {
//             std::println("Empty array or invalid size");
//             return;
//         }
//
//         delete [] distance;
//
//         tripsCount = size;
//         distance = new int[tripsCount];
//
//         for (int i =0; i < size; i++)
//         {
//             distance[i] = inpDistance[i];
//         }
//     }
//
//     int totalDistanceTrips() const
//     {
//         int totalDistance = 0 ;
//
//         for (size_t i = 0; i<tripsCount; i++)
//         {
//             totalDistance += distance[i];
//         }
//
//         return totalDistance;
//     }
//
//     int longestTrip() const
//     {
//         if (!distance || tripsCount == 0 )
//             return 0;
//         int longestTrip = distance[0];
//
//         for (int i=1; i<tripsCount; i++)
//         {
//             if (longestTrip < distance[i])
//                 longestTrip = distance[i];
//         }
//
//         return longestTrip;
//     }
//
// };
// int main()
// {
//     int myTrips[] = {150, 420, 50, 1200, 300};
//     int tripsCount = 5;
//
//     Car myCar("Skoda", 2025, 200, myTrips, tripsCount);
//
//     if(myCar.getBrand())
//     {
//         std::println("Car: {} | Year: {} | Max speed: {}", myCar.getBrand(), myCar.getManYear(), myCar.getMaxSpeed());
//         std::println("Total distance driven: {} km", myCar.totalDistanceTrips());
//         std::println("Longest trip: {} km", myCar.longestTrip());
//     }
//
//     return 0;
// }