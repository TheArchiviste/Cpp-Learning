#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    private:
        int studentNumber;
        string studentName;

    public:
        Student(const int studentNumberIn, const string & studentNameIn)            // Makes sure the constructor does not accidentally change the member field.
            : studentNumber(studentNumberIn), studentName(studentNameIn) {
            
            cout << "Made a Student: " << studentName << ", " << studentNumber << endl;
        }

        int getStudentNumber() const {
            return studentNumber;
        }

        const string & getStudentName() const{
            return studentName;
        }

        void setStudentNumber(const int newStudentNumber) {     // Guarantees that we are not accidentally going to change the value of n instead of the member variable.
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
    Student sally(42, "Sally Mich");

    MathStudent sally_M(sally);
    sally_M.setMark(0, 4.7);
    sally_M.setMark(1, 5.3);

    cout << "The selected student is: " << sally << endl;

    cout << "The marks of: " << sally_M << endl;
    
    return 0;
}
#endif