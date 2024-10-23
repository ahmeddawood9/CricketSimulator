#include<iostream>
using namespace std;
//Class 1
//Defining a class for player
class Player {
private : // private attributes below there
    string name;
    int age;
    int runsScored;
    int wicketsTaken;
    int battingSkill;
    int bowlingSkill;
    string role;
public : // Public attributes below down there
    Player(string name="NA", int age=0, int battingSkill=0, int bowlingSkill=0, string role="NA") {
        this->name = name;
        this->age = age;
        this->runsScored = 0;
        this->wicketsTaken = 0;
        this->battingSkill = battingSkill;
        this->bowlingSkill = bowlingSkill;
        this->role = role;
    }
    //copy constructor
    Player(const Player& other) {
        this->name = other.name;
        this->age = other.age;
        this->runsScored = other.runsScored;
        this->wicketsTaken = other.wicketsTaken;
        this->battingSkill = other.battingSkill;
        this->bowlingSkill = other.bowlingSkill;
        this->role = other.role;
    }


    // a method to display player information
    void displayInfo();

};
Player* createPlayer(string& name,int age,int battingSkill,int bowlingSkill,string& role) {

    Player* obj = new Player(name, age, battingSkill, bowlingSkill, role);
    return obj;

}

void Player :: displayInfo () {
    cout << "Name: " <<name<< endl;
    cout << "Age: " <<age<< endl;
    cout << "Runs Scored: " <<runsScored<< endl;
    cout << "Wickes Taken: " <<wicketsTaken<< endl;
    cout << "Batting Skill: " <<battingSkill<< endl;
    cout << "Bowling Skill: " <<bowlingSkill<< endl;
    cout << "Role : " <<role<< endl;


}


int main() {
    string playerName;
    string playerRole;
    int playerAge;
    int battingSkill, bowlingSkill; // Variables to store skill ratings

    // Taking input from the user
    cout << "Enter player name: ";
    cin>>playerName; // Use getline to allow names with spaces
    cout << "Enter player age: ";
    cin >> playerAge; // Input age

    // Input and validate batting skill
    do {
        cout << "Enter batting skill (1-10): ";
        cin >> battingSkill;
        if (battingSkill < 1 || battingSkill > 10) {
            cout << "Invalid input! Please enter a skill between 1 and 10." << endl;
        }
    } while (battingSkill < 1 || battingSkill > 10);

    // Input and validate bowling skill
    do {
        cout << "Enter bowling skill (1-10): ";
        cin >> bowlingSkill;
        if (bowlingSkill < 1 || bowlingSkill > 10) {
            cout << "Invalid input! Please enter a skill between 1 and 10." << endl;
        }
    } while (bowlingSkill < 1 || bowlingSkill > 10);

    cout << "Enter player role: ";

    cin>>playerRole;// taking input for player role

    // Create a player using the createPlayer function
    Player* player = createPlayer(playerName, playerAge, battingSkill, bowlingSkill, playerRole);

    // Display player information
    player->displayInfo(); // Displaying player info using the dynamically created object

    // Clean up dynamically allocated memory
    delete player; // Freeing memory to avoid memory leaks

    return 0;
}
