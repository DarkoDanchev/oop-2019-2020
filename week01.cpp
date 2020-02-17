#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    int x;
    int y;

    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }

    void scalar(int k)
    {
        x *= k;
        y *= k;
    }
    void create(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    double distance(Point other)
    {
        return sqrt(pow((other.x - x),2) + pow((other.y - y),2));
    }
};

struct Triangle
{
    Point first;
    Point second;
    Point third;

    double firstLength;
    double secondLength;
    double thirdLength;

    void print()
    {
        first.print();
        second.print();
        third.print();
    }

    void create(Point _first, Point _second, Point _third)
    {
        first = _first;
        second = _second;
        third = _third;
        firstLength = first.distance(second);
        secondLength = second.distance(third);
        thirdLength = first.distance(third);
    }

    double area()
    {
        double s = length() / 2;
        double returnedArea = sqrt(s * (s- firstLength)*(s - secondLength) * (s - thirdLength));
        return returnedArea;
    }

    double length()
    {
        return (firstLength + secondLength + thirdLength);
    }
};

Point scalar(Point p1, int k)
{
   Point p;
   p.x = p1.x * k;
   p.y = p1.y * k;

   return p;
}

int main()
{
    Point p1,p2,p3;
    p1.create(0,0);
    p2.create(1,0);
    p3.create(0,1);
    Triangle t1;
    t1.create(p1,p2,p3);
    t1.print();
    double area = t1.area();
    cout<<area<<endl;
}
