class Point
{
    public:
        Point();
        Point(int x, int y);
        // Point(Point &&) = default;
        // Point(const Point &) = default;
        // Point &operator=(Point &&) = default;
        // Point &operator=(const Point &) = default;
        ~Point();
        // Getters
        int getX();
        int getY();

        // Setters
        void setX(int x);
        void setY(int y);

        // Negate a point by changing the sign of y value
        void negate();

        // ostream handler: print this point
        friend std::ostream& operator <<(std::ostream& os, const Point& p);

    private:
        int x;
        int y;
};

