#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


class Student{
public:
  string name;
  int id;
  double gpa;
  void printStudent() {
    cout << name << ", " << id << ", " << gpa << endl;
  }

};


int main() {
  Student *sArr; // array of student
  Student *current; // used to access array of students
  int numStudents; // number of students in array

  //get number of students and fill array with info
  cout << "Enter number of students: ";
  cin >> numStudents;
  sArr = new Student[numStudents];
  cout << fixed << setprecision(2);
  for (int i=0;i<numStudents;i++) {
    current = sArr + i;
    cout << "Enter Student " << i << " name: ";
    cin.ignore();
    getline(cin, (current->name));
    cout << "Enter Student " << i << " ID: ";
    cin >> current->id;
    cout << "Enter Student " << i << " GPA: ";
    cin >> current->gpa;
    //    current->printStudent(); //for debugging
  }

  Student *Fall15Best;
  Fall15Best = new Student;
  Fall15Best->gpa = 0.0;

  cout << endl << "Student List:" << endl;
  for (int i=0;i<numStudents;i++){
    if (sArr[i].gpa > Fall15Best->gpa)
      *Fall15Best = sArr[i];
    sArr[i].printStudent();    
  }

  delete [] sArr;
  cout << "Array deleted..." << endl << endl;
  cout << "Best for Fall 15: " << endl;
  //print best student info
  Fall15Best->printStudent();
  delete Fall15Best;
}
