#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//Student class holding all information variables and fucntions
class Student {
        vector<float> scores; 
        float currentGrade, finalScore, finalGrade;
        char letterGrade;
    public:
        Student();
        string name;
        int  tests;
        bool nameNotEntered, scoresNotEntered;
        void setName();
        void enterScores();
        void displayCurrentGrade();
        float calcCurrentGrade();
        char getLetterGrade(float percentage);
};

Student::Student(){
    nameNotEntered = true;
    scoresNotEntered = true;
}

void Student::setName(){
    cout << "Enter student name:\n";
    cin >> name;
    cout << "Student name is " << name << endl;
    nameNotEntered = false;
}

void Student::enterScores(){
    tests = 0;
    cout << "How many test scores to enter:\n";
    cin >> tests;

    if(tests < 0){
        cout << "Invalid number of tests, returning to menu.\n";
    }
    else{
        scores.resize(tests);
        
        for(int i=0; i<tests; i++){
            cout << "Enter score for Test " << i+1 << endl;
            cin >> scores[i];

            if(scores[i] < 0){
                cout << "Invalid score, Try Again.\n";
                i--;
            }
        }
        scoresNotEntered = false;
    }
}

void Student::displayCurrentGrade(){
    cout << "Current grade: " << this->getLetterGrade(this->calcCurrentGrade());
    cout << " " << currentGrade << "%\n";
}

float Student::calcCurrentGrade(){
    currentGrade = 0;

    for(int i=0; i<tests; i++){
        currentGrade += scores[i];
    }

    currentGrade = float(currentGrade / tests);
    return currentGrade;
}

char Student::getLetterGrade(float percentage){
    if (percentage >= 90){
		letterGrade = 'A';
    }
	else if (percentage >= 80){
		letterGrade = 'B';
    }
	else if (percentage >= 70){
		letterGrade = 'C';
    }
	else if (percentage >= 60){
		letterGrade = 'D';
    }
	else{
		letterGrade = 'F';
    }
    return letterGrade;
}


int main(){
    int option = 0;
    Student *stud = new Student;
    
    cout << fixed << setprecision(2);

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
        else if(option == 2){
            stud->enterScores();
        }
        else if(option == 3){
            if(stud->scoresNotEntered){
                cout << "Scores have not been entered yet.\n" << 
                "Please enter option 2 to enter scores first.\n";
            }
            else{
                stud->displayCurrentGrade();
            }
        }
        else if(option == 6){
            cout << "*Quitting*\n";
        }
        else{
            cout << "Not a menu option, Try Again\n";
        }
    }

    cout << "*Quit Program*\n";
    return 0;
}