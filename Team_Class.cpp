// Class 2: Defining a class for Team
class Team {
private:
    Player** players;
    int playerCount;
    int capacity;

public:
    Team(int capacity) {
        this->capacity = capacity;
        players = new Player*[capacity];
        playerCount = 0;
    }

    void addPlayer(Player* player);
    void displayAllPlayers();
    int getTotalRuns();
    int getPlayerCount();
    Player* getPlayer(int index);

    ~Team() {
        for (int i = 0; i < playerCount; i++) {
            delete players[i];
        }
        delete[] players;
    }
};

void Team::addPlayer(Player* P) {
    if (playerCount < capacity) {
        players[playerCount] = P;
        playerCount++;
    } else {
        cout << "Failed to add player because Team is full" << endl;
    }
}

void Team::displayAllPlayers() {
    for (int i = 0; i < playerCount; i++) {
        players[i]->displayInfo();
    }
}

int Team::getTotalRuns() {
    int totalRuns = 0;
    for (int i = 0; i < playerCount; i++) {
        totalRuns += players[i]->getRuns();
    }
    return totalRuns;
}

int Team::getPlayerCount() {
    return playerCount;
}

Player* Team::getPlayer(int index) {
    if (index < playerCount) {
        return players[index];
    }
    return nullptr; // Return nullptr if index is valid , this make sures that there's no runtime problem
}
