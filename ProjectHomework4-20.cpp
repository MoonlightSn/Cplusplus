#include <iostream>
using namespace std;

class Complex {
  public:
    Complex(double x) : x(x), y(0){}; //目前我的vs code貌似不支持默认参数的构造函数，未知如何解决
    Complex(double x, double y) : x(x), y(y){};
    Complex(Complex &num) : x(num.x), y(num.y){};
    double getX() { return x; };
    double getY() { return y; };
    void show();
    void add(Complex &x1);

  private:
    double x = 0, y = 0;
};

void Complex::show() {
    cout << "the complex number is " << x << "+ " << y << "i" << endl;
};

void Complex::add(Complex &x1) {
    x += x1.getX();
    y += x1.getY();
};

int main() {
    Complex c1(3, 5);
    Complex c2(4.5); // 练习题是Complex c2=4.5 隐式类型转换？ vs可以运行但vs code不行，目前未知如何解决。
    c1.add(c2);
    c1.show();
    system("pause");
    return 0;
}