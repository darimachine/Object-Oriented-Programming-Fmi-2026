#include <iostream>
using std::cout;
using std::cin;
using std::endl;

constexpr int VECTOR_DIMENSION = 3;
struct Vector {
    int arr[VECTOR_DIMENSION];
};
Vector sum(const Vector& v1, const Vector& v2) {
    Vector result;
    for (int i = 0; i < VECTOR_DIMENSION; i++) {
        result.arr[i] = v1.arr[i] + v2.arr[i];
    }
    return result;
    
}
void printCoordinate(const Vector& v1) {
    for (int i = 0; i < VECTOR_DIMENSION; i++) {
        cout << v1.arr[i] << " ";
    }
}
bool isLinearDepence(const Vector& v1, const Vector& v2) {
    bool isCheckedOnce = false;
    double divided=0;
    int i = 0;
    for (; i < VECTOR_DIMENSION; i++) {
        if (v2.arr[i] == 0 && v1.arr[i] != 0) {
            return false;
        }
        else if (v2.arr[i] == 0 && v1.arr[i] == 0) {
            continue;
        }
        else {
            divided = (double)v1.arr[i] / v2.arr[i];
            isCheckedOnce = true;
            break;
        }

    }
    i++;
    for (; i < VECTOR_DIMENSION; i++) {
        if (v2.arr[i] == 0 && v1.arr[i] != 0) {
            return false;
        }
        else if (v2.arr[i] == 0 && v1.arr[i] == 0) {
            continue;
        }
        double currDivided = (double)v1.arr[i] / v2.arr[i];
        if (abs(divided - currDivided) > 0.0001) {
            return false;
        }
    }
    return isCheckedOnce;
}
int main()
{
    Vector v1 = { {0,8,3} };
    Vector v2 = { {0,0,3} };
    cout<<isLinearDepence(v1, v2);
}