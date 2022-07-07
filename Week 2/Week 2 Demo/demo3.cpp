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

        Student(const Student & other)
            : studentNumber(other.studentNumber), studentName(other.studentName) {

            cout << "Copied a Student: " << studentName << ", " << studentNumber << endl; 
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

        Student & operator=(const Student & other) {
            studentName = other.studentName;
            studentNumber = other.studentNumber;

            return *this;
        }
};

ostream & operator<<(ostream & o, const Student & toPrint) {
    o << toPrint.getStudentName() << " (" << toPrint.getStudentNumber() << ")";
    return o;
}

// USSING VECTORS..
class MathStudent {
    private:
        Student student;
        double * marks;
        int markSize;
    
    public:
        MathStudent(const Student & studentIn)
            : student(studentIn), marks(new double[10]), markSize(10) {
            
            for (int i = 0; i < markSize; ++i) {
                marks[i] = 0;
            }

            cout << "The student: " << student.getStudentName() << " is now Math student." << endl;
        }

        MathStudent(const MathStudent & other)
            : student(other.student), 
            //   marks(other.marks),
            marks(new double [other.markSize]),
            markSize(other.markSize) {
            
            for (int i = 0; i < markSize; ++i) {
                marks[i] = other.marks[i];
            }

            cout << "Copied a MathStudent: " << student << endl;
        }

        void setMark( const int assignmentNumber, const double mark) {
            marks[assignmentNumber] = mark;
        }

        double addMarks() const{
            double sum = 0.0;

            for (int i=0; i < markSize; ++i) {
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

        MathStudent & operator=(const MathStudent & other) {
            student = other.student;

            delete [] marks;        // Make sure we delete the old one before creating a new!!!!

            marks = new double [other.markSize];
            markSize = other.markSize;

            for (int i = 0; i < markSize; ++i) {
                marks[i] = other.marks[i];
            }

            return *this;
        }

        void write(ostream & o) const {
            o << student << " [";

            for (int i=0; i < markSize; ++i) {
                o << " " << marks[i];
            }

            o << " ]";
        }

        ~MathStudent() {
            delete [] marks;
        }
};

ostream & operator<<(ostream & o, const MathStudent & toPrint) {
    toPrint.write(o);
    return o;
}

#if 1
int main() {
    Student sally(4243531, "Sally Mich");
    Student ivan(2343122, "Ivan Willams");
    Student denny(2363122, "Denny Horht");

    MathStudent sally_M(sally);
    MathStudent ivan_M(ivan);

    sally_M.setMark(0,7);
    ivan_M.setMark(0,10);

    cout << sally_M << endl;
    cout << ivan_M << endl;

    MathStudent horry_M = sally_M;      // Copy of sally

    horry_M.setMark(0,8);               // Thus ends up changing sally!!!
                                        // Due to the copy constructor => It needs to create a new array there too!
    cout << sally_M << endl;
    cout << ivan_M << endl;
    cout << horry_M << endl;

    MathStudent denny_M(denny);

    denny_M = ivan_M;

    cout << denny_M << endl;

    return 0;
}
#endif