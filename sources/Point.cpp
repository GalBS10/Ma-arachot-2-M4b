#include "Point.hpp"
#include "cmath"

using namespace std;

Point::Point(double x_plain, double y_plain ){
    plain_x = x_plain;
    plain_y = y_plain;
}

double Point::distance(Point other){
    return sqrt(pow(plain_x - other.getX(),2) + pow(plain_y - other.getY(),2));
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.plain_x << ", " << point.plain_y << ")";
    return os;
}

Point Point::moveTowards(Point origin, Point destination, double distance){

    //need to ask how to do
    return Point(0,0);
}

double Point::getX(){
    return plain_x;
}
double Point::getY(){
    return plain_y;
}


