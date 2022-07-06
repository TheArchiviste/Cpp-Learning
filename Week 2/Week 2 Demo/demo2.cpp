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

        // The assignment operator being overloaded
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

class MathStudent {
    private:
        Student student;
        vector<double> marks;
    
    public:
        MathStudent(const Student & studentIn)
            : student(studentIn), marks(10) {

            cout << "The student: " << student.getStudentName() << " is now Math student." << endl;
        }

        MathStudent(const MathStudent & other)
            : student(other.student), marks(other.marks) {

            cout << "Copied a MathStudent: " << student << endl;
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

#if 0
int main() {
    Student sally(4243531, "Sally Mich");
    Student ivan(2343122, "Ivan Willams");

    Student copyOfSally(sally);

    ivan = sally;

    cout << ivan.getStudentName() << ", " << ivan.getStudentNumber() << endl;

    return 0;
}
#endif

#if 1
int main() {
    Student sally(4243531, "Sally Mich");

    MathStudent mSally(sally);

    MathStudent copyMSally(mSally);

    MathStudent copyMSally2 = mSally;

    return 0;
}
#endif