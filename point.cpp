#include <cstdlib>
#include <iostream>
#include <cmath>

#include "point.hpp"

using namespace std;


// Empty Constructor
Point::Point()
{
    Point(NULL, NULL);
}

Point::Point (int x, int y)
{
    this->x = x;
    this->y = y;
}

// Deconstructor
Point::~Point()
{
}

// Getters
int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

// Setters
void Point::setX(int x)
{
    this->x = x;
}

void Point::setY(int y)
{
    this->y = y;
}

// Negate a point by flipping the sign of y value of the point
void Point::negate(){
    this->y = -(this->y);
}