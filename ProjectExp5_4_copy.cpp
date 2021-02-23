/*此段代码在vs code里又运行不了，但在vs里可以运行，感觉没啥错啊*/
#include <iostream>
using namespace std;

class Point {
  public:
    Point(int x = 0, int y = 0) : x(x), y(y) { count++; }
    Point(Point &p) : x(p.x), y(p.y) { count++; }
    void showCount() { cout << count << endl; }
    ~Point() {}

  private:
    int x, y;
    static int count;
};
int Point::count = 0;

int main() {
    Point p1(1, 1);
    p1.showCount();
    Point p2(2, 2);
    p1.showCount();
    Point p3 = p2;
    p1.showCount();
    system("pause");
    return 0;
}