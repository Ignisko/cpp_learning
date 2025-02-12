#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> outcomes = {
        {0, -1, 1, 1, -1}, // Rock (0)
        {1, 0, -1, -1, 1}, // Paper (1)
        {-1, 1, 0, 1, -1}, // Scissors (2)
        {-1, 1, -1, 0, 1}, // Lizard (3)
        {1, -1, 1, -1, 0}  // Spock (4)
    };

    string choices[] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};

    // 1. Get user input
    int userChoiceIndex;
    cout << "Enter your choice (0: Rock, 1: Paper, 2: Scissors, 3: Lizard, 4: Spock): ";
    cin >> userChoiceIndex;

    // Validate user input
    if (userChoiceIndex < 0 || userChoiceIndex > 4) {
        cout << "Invalid choice. Please enter a number between 0 and 4." << endl;
        return 1; // Indicate an error
    }

    // 2. Generate computer choice
    srand(time(0)); // Seed the random number generator
    int computerChoiceIndex = rand() % 5; // Generates a random number between 0 and 4

    // 3. Determine and print the result
    int result = outcomes[userChoiceIndex][computerChoiceIndex];

    cout << "You chose: " << choices[userChoiceIndex] << endl;
    cout << "Computer chose: " << choices[computerChoiceIndex] << endl;

    if (result == 1) {
        cout << choices[userChoiceIndex] << " beats " << choices[computerChoiceIndex] << ". You win!" << endl;
    } else if (result == -1) {
        cout << choices[computerChoiceIndex] << " beats " << choices[userChoiceIndex] << ". You lose!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
