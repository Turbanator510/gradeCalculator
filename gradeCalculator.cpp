#include <iostream>
#include <vector>

using namespace std;

class student {
        vector<int> scores;
        int gradePercentage;
        char letterGrade;
    public:
        string name;
        int ID, tests;
        bool nameNotEntered, IDNotEntered, scoresNotEntered;
};


//cout << "____________________\n";
int main(){
    int option = 0;

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
    }
    return 0;
}