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

        int getStudentNumber() {
            return studentNumber;
        }

        string getStudentName() {
            return studentName;
        }

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

        bool operator==(MathStudent other) {  // Quality operator, won't work unless there is a quality operator in the Student class too,
            return (student == other.student);  // due to that it uses Student objects.
        }

        bool operator>(MathStudent other) {
            return (addMarks() > other.addMarks());
        }
};

// Copying object values -> objects are independent of each other.
#if 0
int main() {
    Student james(123456, "James Hills");
    Student another = james;

    james.setStudentNumber(654321);

    cout << "Jame's student number is: " << james.getStudentNumber() << endl;
    cout << "Another's student number is: " << another.getStudentNumber() << endl;

    return 0;
}
#endif

// Object taking another object as a parameter.
#if 0
int main() {
    Student cait(767843, "Caitlyn Bore");

    MathStudent cait_M(cait);

    cait_M.setMark(0, 4.7);
    cait_M.setMark(1, 5.3);

    cout << cait.getStudentName() << "'s overall mark is: " << cait_M.addMarks() << endl;

    return 0;
}
#endif

//  Comparing objects using the quality operator.
#if 1
int main() {
    Student ivan(767843, "Ivan Williams");
    Student anotherIvan = ivan;
    Student denis(432543, "Denis Kira");

    anotherIvan.setStudentNumber(123456); // There is no cascading quality through object interactions!!!!

    MathStudent ivan_M(ivan);
    MathStudent anotherIvan_M(anotherIvan); // This object will not detect the change in student number unless it is done before the assignment.
    MathStudent denis_M(denis);

    ivan_M.setMark(0, 4.7);
    ivan_M.setMark(1, 5.3);

    anotherIvan_M.setMark(0, 6.0);
    anotherIvan_M.setMark(1, 5.7);

    denis_M.setMark(0, 3.2);

    if (ivan_M == anotherIvan_M) {
        cout << "They are the same person!" << endl;
    }

    cout << ivan.getStudentName() << "'s overall mark is: " << ivan_M.addMarks() << endl;
    cout << anotherIvan.getStudentName() << "'s overall mark is: " << anotherIvan_M.addMarks() << endl;

    if (ivan_M == denis_M) {
        cout << "They are the same person!" << endl;
    }

    if (ivan_M > denis_M) {
        cout << "Ivan has a better overall mark compared to Denis." << endl;
    }

    return 0;
}
#endif