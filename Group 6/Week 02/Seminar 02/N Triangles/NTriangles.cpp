
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <print>
#include <algorithm>

using namespace std;
namespace Points {
    
    struct Point {
        int x;
        int y;
    };
    void readPoint(Point& p) {
        cin >> p.x >> p.y;
    }

    void printPoint(const Point& p) {
        std::print("( {} {} )", p.x, p.y);
    }
    double getDist(const Point& p1, const Point& p2) {
        int dx = p2.x - p1.x;
        int dy = p2.y - p1.y;
        return sqrt(dx * dx + dy * dy);
    }

}
namespace Figures {
    using namespace Points;
    
    struct Side {
        double a;
        double b;
        double c;
    };

    constexpr int TRIANGLE_NAME_MAX_SIZE = 50;
    struct Triangle {
        char name[TRIANGLE_NAME_MAX_SIZE];
        Point p1, p2, p3;
        Side side;
        
    };

    double getPer(const Triangle& tr) {

        return tr.side.a + tr.side.b + tr.side.c;
    }

    double getArea(const Triangle& tr) {
        
        double halfPer = getPer(tr) / 2.00;

        return sqrt(halfPer * (halfPer - tr.side.a) * (halfPer - tr.side.b) * (halfPer - tr.side.c));
    }
   
    void sort(Triangle* triangles, int size, double (*calcMetric) (const Triangle&) ) {

        double* values = new double[size];
        for (int i = 0; i < size; i++)
        {
            values[i] = calcMetric(triangles[i]);
        }

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < size; j++) {
                if (values[minIndex] > values[j]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                std::swap(triangles[minIndex], triangles[i]);
                std::swap(values[minIndex], values[i]);
            }
        }
        delete[] values;
    }

    void computeSides(Triangle& tr) {
        tr.side.a = getDist(tr.p1, tr.p2);
        tr.side.b = getDist(tr.p1, tr.p3);
        tr.side.c = getDist(tr.p2, tr.p3);
    }
    void readTriangle(Triangle& tr) {
        readPoint(tr.p1);
        readPoint(tr.p2);
        readPoint(tr.p3);
        computeSides(tr);
    }
    void printTriangle(const Triangle& tr) {
        cout << tr.name<<"  ";
        printPoint(tr.p1);
        printPoint(tr.p2);
        printPoint(tr.p3);
        cout << " Area: " << getArea(tr);
        cout << "  Per:  " << getPer(tr)<<endl;
    }
}
/*
3
0 0 5 0 2 4
0 0 3 0 0 2
0 0 10 0 0 1
*/
/*
3
0 0 5 0 2 4  - Triangle 1 per=14.47, area = 10
0 0 3 0 0 2  - Triangle 2 per=8.61, area = 3
0 0 10 0 0 1 - Triangle 3 per=21.05, area = 5
*/
int main()
{
    int n;
    cin >> n;

    Figures::Triangle* triangles = new Figures::Triangle[n];
    for (int i = 0; i < n; i++)
    {
        Figures::readTriangle(triangles[i]);
        char id[20];
        _itoa(i + 1, id, 10);
        strcpy(triangles[i].name, "Triangle ");
        strcat(triangles[i].name, id);
    }
    /*double getPer(const Triangle & tr) {

        return tr.side.a + tr.side.b + tr.side.c;
    }*/
    Figures::sort(triangles, n, Figures::getPer);
    
    /*std::sort(triangles, triangles + n, [](const Figures::Triangle& tr1, const Figures::Triangle& tr2)-> bool {
        return Figures::getPer(tr1) > Figures::getPer(tr2);
        });*/

    for (int i = 0; i < n; i++)
    {
        Figures::printTriangle(triangles[i]);
    }
    delete[] triangles;

    
}


