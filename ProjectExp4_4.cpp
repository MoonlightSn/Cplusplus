# include <iostream>
# include <math.h>
using namespace std;
class Point {
public:
	Point(int xx = 0, int yy = 0) {
		//cout << "调用Point类的构造函数" << endl;
		x = xx;
		y = yy;
	}
	Point(Point &p);
	double getX() { return x; }
	double getY() { return y; }
private:
	double x, y;
};
Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	//cout << "调用Point类的复制构造函数" << endl;
}
class Line {
public:
	Line(Point xp1, Point xp2);
	Line(Line &l);
	double getLen() { return len; };
private:
	Point p1, p2;
	double len;
};
Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2) {
	//cout << "调用Line类的构造函数"<<endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}
Line::Line(Line &l) :p1(l.p1), p2(l.p2) {
	//cout << "调用Line类的复制构造函数" << endl;
	len = l.len;
}
int main() {
	Point myp1(1);
	Point myp2(4);
	Line line1(myp1, myp2);
	Line line2 = line1;
	cout << "length of line1: " << line1.getLen() << endl;
	cout << "length of line2: " << line2.getLen() << endl;
    //cout<<Line((Point)1,(Point)4).getLen()<<endl;
    //cout<<Line(1,4).getLen()<<endl;
    system("pause");
	return 0;
}