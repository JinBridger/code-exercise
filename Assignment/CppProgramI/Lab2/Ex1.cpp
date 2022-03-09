#include <iostream>
#include <string>
using namespace std;


class GradeBook {
    public:
    GradeBook(string newClassName, string newTeacherName): className(newClassName), teacherName(newTeacherName) { }
    GradeBook() {}

    void displayMessage() {
        cout << "Welcome to the grade book for" << endl;
        cout << className << endl;
        cout << "This course is presented by: " << teacherName << endl;
    }

    void setTeacherName() {
        string newTeacherName;
        cout << "Changing instructor name to: ";
        cin >> newTeacherName;
        teacherName = newTeacherName;
    }
    string getTeacherName() {
        return teacherName;
    }

    private:
    string className, teacherName;
};
int main() {
    GradeBook book1("CS101 Introduction to C++ Programming!", "Sam Smith");
    book1.displayMessage();
    book1.setTeacherName();
    book1.displayMessage();
    return 0;
}