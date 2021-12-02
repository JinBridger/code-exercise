#include <iostream>
#include <string>
using namespace std;


class Employee {
    public:
    Employee(string newFirstName, string newLastName, int newSalary): firstName(newFirstName), lastName(newLastName), salary(newSalary?newSalary:0) {}
    Employee() {};

    void setFirstName(string newFirstName) {firstName = newFirstName;}
    void setLastName(string newLastName) {lastName = newLastName;}
    void setSalary(int newSalary) {salary = newSalary;}

    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}
    int getSalary() {return salary;}

    void showYearlySalary() {
        cout << "Name: " << firstName << " " << lastName << "; ";
        cout << "YearlySalary: " << salary * 12 << endl;
    }
    void increaseSalary() {
        salary *= 1.1;
    }
    private:
    string firstName, lastName;
    int salary;
};
int main() {
    Employee a("Bob", "Jones", 2875);
    Employee b("Susan", "Baker", 3150);
    
    a.showYearlySalary();
    b.showYearlySalary();
    
    cout << "Increase employee salaries by 10%" << endl;
    a.increaseSalary();
    b.increaseSalary();

    a.showYearlySalary();
    b.showYearlySalary();
    return 0;
}