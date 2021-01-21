#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Student class holding all information variables and fucntions
class Student {
        vector<int> scores; 
        int gradePercentage;
        char letterGrade;
    public:
        Student();
        string name;
        int ID, tests;
        bool nameNotEntered, IDNotEntered, scoresNotEntered;
        void setName();
};

Student::Student(){
    nameNotEntered = true;
    IDNotEntered = true;
    scoresNotEntered = true;
}

void Student::setName(){
    cout << "Enter student name:\n";
    cin.ignore();
    getline(cin, name);
    cout << "Student name is " << name << endl;
    nameNotEntered = false;
}

//cout << "____________________\n";
int main(){
    int option = 0;
    Student *stud = new Student;
    while(option != 6){
        cout << "____________________\n";
        cout << "Menu:\n";
        cout << "[1] Enter student name.\n";
        cout << "[2] Enter test scores.\n";
        cout << "[3] Display current grade\n";
        cout << "[4] Display minimum grade needed.\n";
        cout << "[5] Display student summary\n";
        cout << "[6] Quit\n";
        cout << "____________________\n";
        cin >> option;
        if(option == 1){
            stud->setName();
        }
        else{
            cout << "Not a menu option\n";
        }
    }
    cout << "*Quit Program*\n";
    return 0;
}