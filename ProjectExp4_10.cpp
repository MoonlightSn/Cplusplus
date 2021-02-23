#include <iostream>
using namespace std;

enum Level {
    freshman,
    sophomore,
    junior,
    senior
}

;

enum Grade {
    A,
    B,
    C,
    D
}

;

class Student {

  public:
    Student(unsigned number, Level level, Grade grade)
        : number(number), level(level), grade(grade){};
    void show();

  private:
    unsigned number : 27;
    Level level : 2;
    Grade grade : 2;
}

;

void Student::show() {
    cout << "Number: " << number << endl;
    cout << "Level: ";

    switch (level) {
    case freshman:
        cout << "freshman";
        break;
    case sophomore:
        cout << "sophomore";
        break;
    case junior:
        cout << "junior";
        break;
    case senior:
        cout << "senior";
        break;
    }

    ;
    cout << endl;
    cout << "Grade: ";

    switch (grade) {
    case A:
        cout << "A";
        break;
    case B:
        cout << "B";
        break;
    case C:
        cout << "C";
        break;
    case D:
        cout << "D";
        break;
    }

    ;
    cout << endl;
}

int main() {
    cout << "Size of student" << sizeof(Student) << endl;
    Student feng(123456, sophomore, A);
    feng.show();
    system("pause");
    return 0;
}