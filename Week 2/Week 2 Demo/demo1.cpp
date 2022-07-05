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

#if 1
int main() {
    Student sally(4243531, "Sally Mich");

    Student * ivan = new Student(2343122, "Ivan");

    cout << sally << endl;
    cout << ivan << endl;       // Returns the hexadecimal representation of where it lives in memory.
    cout << *ivan << endl;
    cout << &ivan << endl;
    cout << &sally << endl;     // Prints where the object is being stored in memory.

    return 0;
}
#endif
