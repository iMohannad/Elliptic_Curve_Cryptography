#include <cstdlib>
#include <iostream>
#include <cmath>


using namespace std;

class Point
{
    public:
        Point();
        Point(int x, int y);
        Point(Point &&) = default;
        Point(const Point &) = default;
        Point &operator=(Point &&) = default;
        Point &operator=(const Point &) = default;
        ~Point();
        // Getters
        int getX();
        int getY();

        // Setters
        void setX(int x);
        void setY(int y);

    private:
        int x;
        int y;
};

// Empty Constructor
Point::Point()
{
}

// Deconstructor
Point::~Point()
{
}
