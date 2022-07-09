#include <iostream>
#include <memory>
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

        virtual ~Student() {
            cout << "Destroyed a student!" << endl;
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

        virtual void write(ostream & o) const {
            o << studentName << " (" << studentNumber << ")";
        }
};

ostream & operator<<(ostream & o, const Student & toPrint) {
    toPrint.write(o);
    return o;
}

class MathStudent : public Student {
    private:
        vector<double> marks;
    
    public:
        MathStudent(const int studentNumberIn, 
                    const string & studentNameIn)
        : Student(studentNumberIn, studentNameIn), marks(10) {
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

        virtual void write(ostream & o) const override {
            Student :: write(o);
            o << " [";

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


void printStudent(const Student & s) {
    cout << s << endl;
}

#if 0
int main() {
    Student sally(4321, "Sally Mich");

    printStudent(sally);

    MathStudent sally_M(4321, "Sally Mich");

    sally_M.setMark(0, 4.7);

    // Without using virtual functions this will use the << write function
    // of the Student class.
    printStudent(sally_M);

    return 0;
}
#endif

#if 1
int main() {
    Student sally(4321, "Sally Mich");

    MathStudent sally_M(4321, "Sally Mich");

    // Restricted to only Student objs.
    vector<unique_ptr<Student>> students;

    students.emplace_back(new Student(sally));
    students.emplace_back(new MathStudent(sally_M));

    for (auto & s : students) {
        cout << *s << endl;
    }

    return 0;
}
#endif