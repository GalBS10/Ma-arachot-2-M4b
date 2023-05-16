#ifndef POINT
#define POINT
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Point
{
private:
    double plain_x;
    double plain_y;
public:
    Point(double x_plain, double y_plain );
    double distance(Point other);
    friend ostream& operator<<(std::ostream& os, const Point& point);
    Point moveTowards(Point origin, Point destination, double distance);
    double getX();
    double getY();
};
#endif


