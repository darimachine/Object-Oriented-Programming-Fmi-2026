// #include  <iostream>
// #include  <cstring>
// #include  <print>
//
// const int maxNameLen = 30;
// const int MIN_AGE = 30;
// const int MIN_YEARS_OF_EXPERIENCE = 0;
// class Teacher {
//     private:
//         char name[maxNameLen + 1];
//         int age;
//         int yearsOfExperience;
//
// public:
//         Teacher(const char *inputedName, int inputedAge, int inputedYExperience)
//         {
//             setName(inputedName);
//             setAge(inputedAge);
//             setYExperience(inputedYExperience);
//         }
//         void setName(const char* inputedName)
//         {
//             if (!inputedName)
//             {
//                 std::println("You inputed an empty name!");
//                 return;
//             }
//
//             int inputedNameLen = strlen(inputedName);
//             if (inputedNameLen > maxNameLen) {
//                 std::println("The netered name is way too long");
//                 return;
//             }
//
//             strncpy(name, inputedName, inputedNameLen);
//             name[inputedNameLen] = '\0';
//         }
//
//         const char * getName() const{
//             return this->name;
//         }
//
//         void setAge(int age) {
//             if (age < MIN_AGE) {
//                 std::println("The inputed age does not meet the requirements!");
//                 return;
//             }
//
//             this->age = age;
//         }
//
//         int getAge() const {
//             return this->age;
//         }
//
//         void setYExperience(int inputedYearsExp) {
//             if (inputedYearsExp < MIN_YEARS_OF_EXPERIENCE) {
//                 std::print("The years of experience can not be a negative number!");
//                 return;
//             }
//
//             yearsOfExperience = inputedYearsExp;
//         }
//
//         int getYExperience() const {
//             return yearsOfExperience;
//         }
//
//
//
// };
//
// int main ()
// {
//     Teacher myTeacher("Yankova", 50, 15);
//     int myTYears = myTeacher.getAge();
//     int myTExp = myTeacher.getYExperience();
//     const char *myTName = myTeacher.getName();
//     std::println("Teacher's name is {}, their age is {} with experience of {}", myTName, myTYears, myTExp);
//
//     return  0;
// }