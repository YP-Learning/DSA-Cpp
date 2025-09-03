/*
# R-2.12
Generalize the Person-Student class hierarchy to include classes Faculty,
UndergraduateStudent, GraduateStudent, Professor, Instructor. Explain
the inheritance structure of these classes, and derive some appropriate
member variables for each class
*/

#include <string>
using namespace std;

class Person { // Person (base class)
    private:
        string name; // name
        string idNum; // university ID number
    public:
    // . . .
        virtual void print(); // print information
        string getName(); // retrieve name
};

class Student : public Person { // Student (derived from Person)
    private:
        string major; // major subject
        int gradYear; // graduation year
    public:
    // . . .
        virtual void print(); // print information
        void changeMajor(const string& newMajor); // change major
};

class UndergradStudent : public Student {
    private:
        bool honors;
        string bachlorsType;
    public:
        void changeBachlorsType(const string& newType);
        bool getHonors();
};

class GraduateStudent : public Student {
    private:
        string bachlorsIn;
        bool partTime;
    public:
        void setBachlorsIn(const string& bachlors);
        bool isPartTime();
};

class Faculty : public Person {
    private:
        string dept;
        string joiningDate;
    public:
        string getDept();
};

class Instructor : public Faculty {
    private:
        string subjects[5];
    public:
        string* getSubjects();
};

class Professor : public Faculty {
    private:
        string specialization;
    public:
        void changeSpecialization(const string& spec);
};
