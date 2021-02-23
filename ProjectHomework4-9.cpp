# include <iostream>
# include <math.h>
using namespace std;

class Point {
  public:
    Point(double x = 0, double y = 0) : x(x), y(y){};
    Point(Point &p) : x(p.x), y(p.y){};
    double getX() { return x; }
    double getY() { return y; }

  private:
    double x, y;
};

class Rectangle {
  public:
    Rectangle(Point p1, Point p2) : p1(p1), p2(p2){};
    Rectangle(Rectangle &r) : p1(r.p1), p2(r.p2){};
    double area();

  private:
    Point p1;
    Point p2;
};

double Rectangle::area() {
    return abs((p1.getX() - p2.getX()) * ((p1.getY()) - p2.getY()));
};

int main() {
    cout << "please enter the coordinates of the first point separated by Spaces: " << endl;
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    cout << "please enter the coordinates of the second point separated by Spaces: " << endl;
    cin >> x2 >> y2;
    Point p1(x1, y1);
    Point p2(x2, y2);
    Rectangle r(p1, p2);
    Rectangle r2=r;
    cout <<"The area of rectangle created by the points was: "<<r.area()<< endl;
    cout<<r2.area()<<endl;
    system("pause");
    return 0;
}
