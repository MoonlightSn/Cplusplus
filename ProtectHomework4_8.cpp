#include <iostream>
using namespace std;

class Dog {
  public:
    Dog(int age = 0, double weight = 0) : age(age), weight(weight){};
    Dog(Dog &dog):age(dog.age), weight(dog.weight){};
    int getAge() { return age; };
    double getWeight() { return weight; };

  private:
    int age;
    double weight;
};
int main() {
    Dog niuniu(2, 12);
    Dog huahua = niuniu;
    cout << "niuniu's age is " << niuniu.getAge() << endl;
    cout << "niuniu's weight is " << niuniu.getWeight() << endl;
    cout << "huahua's age is " << huahua.getAge() << endl;
    cout << "huahua's weight is " << huahua.getWeight() << endl;
    system("pause");
    return 0;
}