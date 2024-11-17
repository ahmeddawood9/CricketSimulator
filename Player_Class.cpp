#include<iostream>
using namespace std;
//part 1

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


