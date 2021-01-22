/*
C++ project which displays a menu with options to enter 
name & test scores and displaying grade details. Details 
include average scores, final grade needed, and summary.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;


//Student class holding all information variables and functions
class Student {
        vector<float> scores; 
        float currentGrade, finalScore, finalGrade;
        char letterGrade;
    public:
        Student();
        string firstName, lastName;
        int  tests;
        bool nameNotEntered, scoresNotEntered, minFinalNotEntered;
        void setName();
        void enterScores();
        void displayCurrentGrade();
        float calcCurrentGrade();
        char getLetterGrade(float percentage);
        void displayMinScore();
        void displaySummary();
        void displayFinalSummary();
};

//Default Constructor initializing information to be entered checks
Student::Student(){
    nameNotEntered = true;
    scoresNotEntered = true;
    minFinalNotEntered = true;
}


//Option 1 Function to input student name
void Student::setName(){
    cout << "Enter student first name:\n";
    cin >> firstName;
    cout << "Enter student last name:\n";
    cin >> lastName;
    cout << "Student name is " << firstName << " " << lastName << endl;
    //Name is now entered
    nameNotEntered = false;
}

//Option 2 Function to input number of tests and respective scores
void Student::enterScores(){
    tests = 0;
    cout << "How many test scores to enter:\n";
    cin >> tests;

    //Ensures input is valid
    if(tests < 1){
        cout << "Invalid number of tests, returning to menu.\n";
    }
    else{
        //Resize scores vector according to need
        scores.resize(tests);
        
        for(int i=0; i<tests; i++){
            cout << "Enter score for Test " << i+1 << endl;
            cin >> scores[i];

            //Ensures input is valid
            if(scores[i] < 0){
                cout << "Invalid score, Try Again.\n";
                i--;
            }
        }
        //Scores are now entered
        scoresNotEntered = false;
    }
}

//Option 3 Function to display current letter and percentage grade
void Student::displayCurrentGrade(){
    cout << "Current grade: " << this->getLetterGrade(this->calcCurrentGrade());
    cout << " " << currentGrade << "%\n";
}

//Calculates and returns current percentage grade
float Student::calcCurrentGrade(){
    currentGrade = 0;

    for(int i=0; i<tests; i++){
        currentGrade += scores[i];
    }

    currentGrade = float(currentGrade / tests);
    return currentGrade;
}

//Converts percentage to letter grade
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

//Option 4 Function to calculate and display final exam grade needed
void Student::displayMinScore(){
    float finalWeight = 0;

    cout << "What is your final exam weight?\n";
    cin >> finalWeight;
    cout << "What is your desired final grade?\n";
    cin >> finalGrade;

    finalWeight *= 0.01;
    finalScore = ((finalGrade - (currentGrade * (1 - finalWeight))) / finalWeight);

    cout << "You need a minimum " << finalScore << "% on the final,\n";
    cout << "to get a final grade of " << finalGrade << "%\n";

    //Final grades desired entered
    minFinalNotEntered = false;
}

//Option 5 Function to display summary of all student grade information
void Student::displaySummary(){
    cout << "Student Name: " << firstName << " " << lastName << endl; 
    cout << "Current Grade: " << letterGrade << " " << currentGrade << "%\n\n";
    cout << "Test Scores:\n";
    for(int i=0; i<tests; i++){
        cout << setw(12) << "Test " << i+1 << ": " << scores[i] << "%\n";
    }
    cout << endl;
}

//Extension of Option 5 if final exam grades desired are entered
void Student::displayFinalSummary(){
    cout << "Final Grade Desired: " << finalGrade << "%\n";
    cout << "Final Score Needed: " << finalScore << "%\n";
}


int main(){
    int option = 0;
    Student *stud = new Student;
    
    //Formats all numbers to be output with 2 decimal places
    cout << fixed << setprecision(2);

    //Display Menu until Option 6 Quit
    while(option != 6){
        cout << "____________________\n";
        cout << "Menu:\n";
        cout << "[1] Enter student name.\n";
        cout << "[2] Enter test scores.\n";
        cout << "[3] Display current grade\n";
        cout << "[4] Display minimum final score needed.\n";
        cout << "[5] Display student summary\n";
        cout << "[6] Quit\n";
        cout << "____________________\n";

        cin >> option;
        cout << endl;

        //Menu option actions
        if(option == 1){
            stud->setName();
        }
        else if(option == 2){
            stud->enterScores();
        }
        else if(option == 3){
            //Ensures action can be completed if scores have been entered
            if(stud->scoresNotEntered){
                cout << "Scores have not been entered yet.\n"; 
                cout << "Please enter option 2 to enter scores.\n";
            }
            else{
                stud->displayCurrentGrade();
            }
        }
        else if(option == 4){
            //Ensures action can be completed if scores have been entered
            if(stud->scoresNotEntered){
                cout << "Scores have not been entered yet.\n"; 
                cout << "Please enter option 2 to enter scores.\n";
            }
            else{
                stud->displayMinScore();
            }
        }
        else if(option == 5){
            //Ensures action can be completed if name and scores have been entered
            if(stud->nameNotEntered){
                cout << "Student name has not been entered yet.\n";
                cout << "Please enter option 1 to enter name.\n";
            }
            else if(stud->scoresNotEntered){
                cout << "Scores have not been entered yet.\n"; 
                cout << "Please enter option 2 to enter scores.\n";
            }
            else{
                //Checks if Option 4 completed to include final grade or not
                if(stud->minFinalNotEntered){
                    stud->displaySummary();
                }
                else{
                    stud->displaySummary();
                    stud->displayFinalSummary();
                }
            }
        }
        else if(option == 6){
            cout << "*Quitting*\n";
        }
        //Ensures input is valid
        else{
            cout << "Not a menu option, Try Again\n";
        }
    }

    cout << "*Quit Program*\n";
    return 0;
}