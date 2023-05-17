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

void Point::print(){
    cout << "(" << plain_x << ", " << plain_y << ")";
}

Point Point::moveTowards(Point origin, Point destination, double distance) {
    // Calculate the direction vector from origin to destination
    double dx = destination.plain_x - origin.plain_x;
    double dy = destination.plain_y - origin.plain_y;
    
    // Calculate the distance between origin and destination
    double dist = sqrt(dx*dx + dy*dy);
    
    // Normalize the direction vector
    double directionX = dx / dist;
    double directionY = dy / dist;
    
    // Calculate the point that is closest to the destination within the radius
    Point closest_point(origin.plain_x + directionX * distance,origin.plain_y + directionY * distance);
    
    return closest_point;
}

double Point::getX(){
    return plain_x;
}
double Point::getY(){
    return plain_y;
}


