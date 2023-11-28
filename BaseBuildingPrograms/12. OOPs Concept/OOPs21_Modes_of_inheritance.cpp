// VISIBILITY MODES IN INHERITANCE:

// Public:    Public members of a class are accessible from any part of the program,
//            including outside the class and its derived classes.

// Protected: Protected members of a class are accessible within the class and its derived classes,
//             restricting access from outside the class hierarchy.

// Private:   Private members are only accessible only within the class, ensuring the highest
//            level of encapsulation. Thus, private members of a class cannot be inherited by
//            any other class, whether it be outside the hierarchy or within the hierarchy.


#include <iostream>
using namespace std;

class Employee {
    private:
        int salary;
    protected:
        int emp_id;
    public:
        string name;
};

// If we don't specify any visibility mode, it will be set to default visibility mode, i.e. public.
class A: public Employee {
    // class A inherits all attributes and methods(if exists) of 'Employee' class, except 'salary'.
    // This class would look like this:-
    // protected:
    //     int emp_id;
    // public:
    //     string name;

    // Below are some user-made instance members of this class:
    public:
        void setEmp_id(int x) {
            emp_id = x;
        }

        void showEmployeeInfo() {
            cout << "Name: " << name << "\n" << "Roll no.: " << emp_id << "\n\n";
        }
};

class A_public: public A {
    // protected members ---> emp_id
    // public members ---> name, setEmp_id(), showEmployeeInfo()
};
class A_protected: protected A {
    // protected members ---> emp_id, name, setEmp_id(), showEmployeeInfo()
};
class A_private: private A {
    // private members ---> emp_id, name, setEmp_id(), showEmployeeInfo()
};

class B: protected Employee {
    // class B inherits all attributes and methods(if exists) of 'Employee' class, except 'salary'.
    // This class would look like this:-
    // protected:
    //     int emp_id;
    //     string name;

    // Below are some user-made instance members of this class:
    public:
        void setEmp_id(int x) {
            emp_id = x;
        }

        void setName(string str) {
            name = str;
        }

        void showEmployeeInfo() {
            cout << "Name: " << name << "\n" << "Emp_id: " << emp_id << "\n\n";
        }
};

class B_public: public B {
    // protected members ---> emp_id, name
    // public members ---> setEmp_id(), setName(), showEmployeeInfo()
};
class B_protected: protected B {
    // protected members ---> emp_id, name, setEmp_id(), setName(), showEmployeeInfo()
};
class B_private: private B {
    // private members ---> emp_id, name, setEmp_id(), setName(), showEmployeeInfo()
};

class C: private Employee {
    // class C inherits all attributes and methods(if exists) of 'Employee' class, except 'salary'.
    // This class would look like this:-
    // private:
    //     int emp_id;
    //     string name;

    // Below are some user-made instance members of this class:
    public:
        void setEmp_id(int x) {
            emp_id = x;
        }

        void setName(string str) {
            name = str;
        }

        void showEmployeeInfo() {
            cout << "Name: " << name << "\n" << "Emp_id: " << emp_id << "\n\n";
        }
};

class C_public: public C {
    // public ---> setEmp_id(), setName(), showEmployeeInfo()
};
class C_protected: protected C {
    // protected ---> setEmp_id(), setName(), showEmployeeInfo()
    
};
class C_private: private C {
    // private ---> setEmp_id(), setName(), showEmployeeInfo()
};


int main() {
    A obj1;
    obj1.setEmp_id(1);
    obj1.name = "Biku";
    obj1.showEmployeeInfo();

    B obj2;
    obj2.setEmp_id(2);
    obj2.setName("Gopi");
    obj2.showEmployeeInfo();

    C obj3;
    obj3.setEmp_id(3);
    obj3.setName("Sapil");
    obj3.showEmployeeInfo();
    
    return 0;
}