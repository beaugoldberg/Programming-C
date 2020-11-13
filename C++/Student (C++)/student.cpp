#include <iostream>
#include <string>
using namespace std;

class Student {
    public :
      void getData();
      void showData();

    private:
      int rollno;
      string name;
      int alg, datastruct, architect, proglang;
      char grade;
      float average;
}

Student::Student() {
    name = "NoName";
    rollno, alg, datastruct, architect, proglang = 0;
    grade = '';
    average = 0.0;
}

void getData(Student s) {
    cout << "Enter student info: " << endl;
    cout << "Roll number?" << endl;
    cin >> s.rollno;
    cout << "First and last name?" << endl;
    getline(cin, s.name);
    cout << "Grade in Algorithms: " << endl;
    cin >> s.alg;
    cout << "Grade in Data Structures: " << endl;
    cin >> s.datastruct;
    cout << "Grade in Architecture: " << endl;
    cin >> s.architect;
    cout << "Grade in Programming Languages: " << endl;
    cin >> s.proglang;
    s.avg = (s.alg + s.datastruct + s.architect + s.proglang)/4
    if (s.avg > 90.0) s.grade = 'A';
    if (s.avg < 90.0 && s.avg > 80.0) s.grade = 'B';
    if (s.avg < 80.0 && s.avg > 70.0) s.grade = 'C';
    if (s.avg < 70.0 && s.avg > 60.0) s.grade = 'D';
    if (s.avg < 60.0) s.grade = 'F';
}

void showData(Student s) {
    cout << "Roll number of student: " << s.rollno << endl;
    cout << "Name of student: " << s.name << endl;
    cout << "Percentage of student is: " << s.avg << endl;
    cout << "Grade of student is: " << s.grade;

}

int main() {
    int classSize;
    int valid = 0;
    while (valid == 0) {
        cout << "Enter size of class: " << endl;
        cin >> classSize;
        if (classSize > 0) valid = 1;
    }

    for (int i = 0; i < classSize; i++) {
        Student student;
        getData(student);
        showData(student);
    }
}