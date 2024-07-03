#include <iostream>
using namespace std;

// syntax of class declaration

class Teacher
{
private:
    double salary;

    // properties of class is accessed by dot operator
public:
    // data members /attributes  / properties
    string name;
    string dept;
    string subject;

    // member function / methods

    void changeDept(string newDept)
    {
        this->dept = newDept;
    }

    // function for printing the data member of teacher
    void print()
    {
        cout << this->name << endl;
        // cout << this->dept << endl;
        cout << (*this).dept << endl;
        cout << this->subject << endl;
        cout << this->salary << endl;
    }

    // concept of getter and setter
    void setSalary(double s)
    {
        this->salary = s;
    }

    double getSalary()
    {
        return this->salary;
    }

    // constructor (default )

    Teacher()
    {
        cout << "This is default constructor " << endl;
    }

    // user defined copy constructor
    Teacher(Teacher &t2)
    {
        cout << "\nThis is user defined copy constructor which is called " << endl;
        this->name = t2.name;
        this->dept = t2.dept;
        this->salary = t2.salary;
        this->subject = t2.subject;
    }
    Teacher(string n, string d, string sub, double sal)
    {

        // this pointer logic
        this->name = n;
        this->dept = d;

        this->subject = sub;
        this->salary = sal;

        cout << "Parameterised constructor is called " << endl;
    }
};

// shallow copy implementation
class Student
{
public:
    string name;
    int rollNo;

    Student(string name, int rollNo)
    {
        this->name = name;
        this->rollNo = rollNo;
    }

    void getInfo()
    {
        cout << "(" << this->name << "," << this->rollNo << ")" << endl;
    }
};

// deep copy implementation using the concept of dynamic memory allocation
class Mentor
{
public:
    string *name;
    string *subject;
    int *phoneNO;

    Mentor(string n, string sub, int phone)
    {
        name = new string[n.size()];
        subject = new string[sub.size()];
        phoneNO = new int;
        *phoneNO = phone;
        *name = n;
        *subject = sub;
    }

    void getInfo()
    {
        cout << "Details: " << endl;
        cout << *(this->name) << endl;
        cout << *(this->subject) << endl;
        cout << *(this->phoneNO) << endl;
        cout << endl;
    }
};
int main()
{

    // object of class creation
    Teacher T1("mukesh", "computer science", "data structures ", 20000);

    // assigning some values to a object

    T1.print();

    cout << T1.name << "," << T1.dept << "," << T1.subject << "," << endl;
    cout << "The salary is : " << T1.getSalary();

    Teacher t2(T1); // default copy construtor

    t2.print();

    // shallow coply implementing using the student class
    Student s1("ramesh", 420);
    s1.getInfo();
    Student s2(s1);
    s2.getInfo();

    s2.rollNo = 100;
    s2.getInfo(); // only the details of s2 object is changed which is due to the shallow copy concept
    s1.getInfo();

    // deep copy implementation
    Mentor m1("chandan", "maths", 32902308);
    m1.getInfo();
    Mentor m2(m1);
    m2.getInfo();
    *(m2.phoneNO) = 100;
    m2.getInfo(); // now phoneNO attributes of both objects m1 and m2 are now changed
    m1.getInfo();

    return 0;
}