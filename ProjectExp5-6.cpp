# include <iostream>
# include "math.h"
using namespace std;

class Point {
public:
	Point(double x, double y) :x(x), y(y) {};
	Point(Point& p) :x(p.x), y(p.y) {};
	friend double dist(Point& p1, Point& p2);
	~Point() {};
private:
	double x, y;
};

double  dist(Point& p1, Point& p2) {
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};

int main() {
	Point p1(1, 2);
	Point p2(3, 4);
	cout << dist(p1, p2);
    system("pause");
	return 0;
}