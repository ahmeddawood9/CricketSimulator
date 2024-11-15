#include<iostream>
using namespace std;

// Class 1: Defining a class for Player
class Player {
private:
    string name;
    int age;
    int runsScored;
    int wicketsTaken;
    int battingSkill;
    int bowlingSkill;
    string role;
    int matchesPlayed; // added extra because of part 4
    float battingAverage; // added extra because of part 4

public:
    Player(string name = "NA", int age = 0, int battingSkill = 0, int bowlingSkill = 0, string role = "NA") {
        this->name = name;
        this->age = age;
        this->runsScored = 0;
        this->wicketsTaken = 0;
        this->battingSkill = battingSkill;
        this->bowlingSkill = bowlingSkill;
        this->role = role;
        matchesPlayed = 0;
        battingAverage = 0.0;
    }

    void displayInfo();
    int getRuns();
    int getWickets();
    int getBattingSkill();
    int getBowlingSkill();
    void updateStatistics(int runs, int wickets);
    string getName() {
        return name;  // Added this method to get player name
    }
};

int Player::getRuns() {
    return runsScored;
}

int Player::getWickets() {
    return wicketsTaken;
}

int Player::getBattingSkill() {
    return battingSkill;
}

int Player::getBowlingSkill() {
    return bowlingSkill;
}

void Player::updateStatistics(int runs, int wickets) {
    runsScored += runs;
    wicketsTaken += wickets;
    matchesPlayed++;
    // Simple float division for batting average calculation
    if (matchesPlayed > 0) {
        battingAverage = (float)runsScored / matchesPlayed; // we have used casting to convert int to float
    }
}

void Player::displayInfo() {
    cout << "Player Info:\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Role: " << role << "\n";
    cout << "Runs Scored: " << runsScored << "\n";
    cout << "Wickets Taken: " << wicketsTaken << "\n";
    cout << "Batting Skill: " << battingSkill << "\n";
    cout << "Bowling Skill: " << bowlingSkill << "\n";
    cout << "Matches Played: " << matchesPlayed << "\n";
    cout << "Batting Average: " << battingAverage << "\n";
}

int main() {
    string playerName;
    string playerRole;
    int playerAge;
    int battingSkill, bowlingSkill; // Variables to store skill ratings

    // Taking input from the user
    cout << "Enter player name: ";
    cin >> playerName; // Use getline to allow names with spaces
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
    cin >> playerRole; // taking input for player role

    // Create a player using the constructor directly
    Player* player = new Player(playerName, playerAge, battingSkill, bowlingSkill, playerRole);

    // Display player information
    player->displayInfo(); // Displaying player info using the dynamically created object

    // Clean up dynamically allocated memory
    delete player; // Freeing memory to avoid memory leaks

    return 0;
}
