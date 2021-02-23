# include <string>
# include<iostream>
using namespace std;
class ExamInfo {
public:
	//三种构造函数，分别用等级、是否通过和百分制来初始化
	ExamInfo(string n, char g):name(n),mode(GRADE),grade(g)  {};
	ExamInfo(string name, bool pass) :name(name), mode(PASS), pass(pass) {};
	ExamInfo(string name, int percent) :name(name), mode(PERCENTAGE), percent(percent) {};
	void show();
private:
	string name;
	enum MODE {GRADE, PASS, PERCENTAGE};
	MODE mode;
	union {
		char grade;
		bool pass;
		int percent;
	};
};
void ExamInfo::show() {
	cout << name << ":";
	switch (mode) {
	case GRADE:
		cout << grade << endl;
		break;
	case PASS:
		cout << (pass ? "PASS" : "FALL") << endl;
		break;
	case PERCENTAGE:
		cout << percent << endl;
		break;
	};
}
int main() {
	ExamInfo course1("English", 'B');
	ExamInfo course2("Calculus", true);
	ExamInfo course3("C++Progamming", 85);
	course1.show();
	course2.show();
	course3.show();
    system("pause");
	return 0;
}
