#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    private:
        int studentNumber;
        string studentName;

    public:
        Student(const int studentNumberIn, const string & studentNameIn)
            : studentNumber(studentNumberIn), studentName(studentNameIn) {
            
            cout << "Made a Student: " << studentName << ", " << studentNumber << endl;
        }

        int getStudentNumber() const {
            return studentNumber;
        }

        const string & getStudentName() const{
            return studentName;
        }

        void setStudentNumber(const int newStudentNumber) {
            studentNumber = newStudentNumber;
        } 

        void setStudentName(string newStudentName) {
            studentName = newStudentName;
        }

        bool operator==(const Student & other) const {
            return (studentNumber == other.studentNumber);
        }
};

ostream & operator<<(ostream & o, const Student & toPrint) {
    o << toPrint.getStudentName() << " (" << toPrint.getStudentNumber() << ")";
    return o;
}

class MathStudent {
    private:
        Student student;
        vector<double> marks;
    
    public:
        MathStudent(const Student & studentIn)
            : student(studentIn), marks(10) {
        }

        void setMark( const int assignmentNumber, const double mark) {
            marks[assignmentNumber] = mark;
        }

        double addMarks() const{
            double sum = 0.0;

            for (int i=0; i < marks.size(); ++i) {
                sum += marks[i];
            }

            return sum;
        }

        bool operator==(const MathStudent & other) const{
            return (student == other.student);
        }

        bool operator>(const MathStudent & other) const{
            return (addMarks() > other.addMarks());
        }

        void write(ostream & o) const {
            o << student << " [";

            for (int i=0; i < marks.size(); ++i) {
                o << " " << marks[i];
            }

            o << " ]";
        }
};

ostream & operator<<(ostream & o, const MathStudent & toPrint) {
    toPrint.write(o);
    return o;
}

void printStudentName (const Student * student) {
    cout << "The student's name is: " << student->getStudentName() << endl;
}

#if 0
int main() {
    Student sally(4243531, "Sally Mich");
    Student sally1(4243531, "Sally Mich");

    Student * ivan = new Student(2343122, "Ivan Willams");
    Student * ivan1 = new Student(2343122, "Ivan Willams");

    cout << sally << endl;
    cout << ivan << endl;       // Returns the hexadecimal representation of where it lives in memory.
    cout << *ivan << endl;
    cout << &ivan << endl;
    cout << &sally << endl;     // Prints where the object is being stored in memory.

    if (sally == sally1) {
        cout << "Sally is Sally1" << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    if (ivan == ivan1) {                    // Compares memory addresses not actual values.
        cout << "Ivan is ivan1" << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    if (*ivan == *ivan1) {
        cout << "Ivan is ivan1" << endl;
    }
    else {
        cout << "Wrong!" << endl;
    }

    delete ivan, ivan1;

    return 0;
}
#endif

#if 0
int main() {
    Student sally(4243531, "Sally Mich");
    Student * ivan = new Student(2343122, "Ivan Willams");

    printStudentName(ivan);
    printStudentName(&sally);
    
    delete ivan;

    return 0;
}
#endif

#if 1
int main() {
    for (int i = 0; i < 10000; ++i) {
         Student * ivan = new Student(2343122, "Ivan Willams");
         delete ivan;
    }

    return 0;
}
#endif
