#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    private:
        int studentNumber;
        string studentName;

    public:
        Student(int studentNumberIn, string studentNameIn)
            : studentNumber(studentNumberIn), studentName(studentNameIn) {
            
            cout << "Made a Student: " << studentName << ", " << studentNumber << endl;
        }

        int getStudentNumber() {        // It is fine not to be a reference -> the amount of memory that it consumes is negligible.
            return studentNumber;
        }

        const string & getStudentName() const{     // Add & // Coppying a string is a lot more expensive => It should return a reference to a string and not a copy of it.
            return studentName;                    // Add first const // To avoud unwanted changes to the member variable we make it read only.
        }                                          // Add second const // This object can be used with const functions. The function works only on const obj.

        void setStudentNumber(int newStudentNumber) {
            studentNumber = newStudentNumber;
        } 

        void setStudentName(string newStudentName) {
            studentName = newStudentName;
        }

        bool operator==(Student other) {
            return (studentNumber == other.studentNumber);
        }
};

class MathStudent {
    private:
        Student student;
        vector<double> marks;
    
    public:
        MathStudent(Student studentIn)
            : student(studentIn), marks(10) {
        }

        void setMark(int assignmentNumber, double mark) {
            marks[assignmentNumber] = mark;
        }

        double addMarks() {
            double sum = 0.0;

            for (int i=0; i < marks.size(); ++i) {
                sum += marks[i];
            }

            return sum;
        }

        bool operator==(MathStudent other) {
            return (student == other.student);
        }

        bool operator>(MathStudent other) {
            return (addMarks() > other.addMarks());
        }
};

// Copies
// Changes will not cascade to copies!!!
#if 0
void printName(Student a) {     // The function will make a copy of the parameter object.
    cout << "Their name is: " << a.getStudentName() << endl;
}

int main() {
    Student cait(654321, "Caitlyn Vermilion");

    printName(cait);        

    return 0;
}
#endif

// Reference are not protecting the object of suffering unwanted/accidental changes.
// Becuase we secured the class method with const this will give an error.
#if 0
int main() {
    Student james(123456, "James Borel");

    cout << "Student name: " << james.getStudentName() << endl;

    string & tmp = james.getStudentName();      // tmp is just another name for studenName memeber variable. Even though the use of this
    // Remove all character of the string           assignment is "getter", it can end up being used as "setter".
    tmp.clear();                                

    cout << "Student name: " << james.getStudentName() << endl;

    return 0;
}
#endif

// Constants
#if 1
void printName(const Student & a) {                                   // The first const guarantees there will be no changes onto the Student obj.
    cout << "Their name is: " << a.getStudentName() << endl;          // The function will a reference of the object as a parameter.
}

int main() {
    Student james(123456, "James Borel");

    cout << "Student name: " << james.getStudentName() << endl;

    const string & tmp = james.getStudentName();        // Const variable should be matching each other.                           
    // We cannot write any code that will mutate the
    // variable from this point onwards. It will be caught
    // by the compiler.

    cout << "Student name: " << james.getStudentName() << endl;
    printName(james);

    return 0;
}
#endif