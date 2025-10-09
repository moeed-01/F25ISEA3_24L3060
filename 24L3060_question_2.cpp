
#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to read words from a file
vector<string> getWordsFromFile(const string& filename) {
    vector<string> words;
    ifstream file(filename);
    string line;

    if (!file) {
        cout << "Error: Cannot open file '" << filename << "'" << endl;
        return words;
    }

    // Use getline instead of >> to handle spaces in words (like "ice cream")
    while (getline(file, line)) {
        if (!line.empty())
            words.push_back(line);
    }
    file.close();
    return words;
}

// Function to select a random word from list
string selectRandomWord(const vector<string>& words) {
    if (words.empty()) {
        return "example";
    }
    srand(time(NULL));
    return words[rand() % words.size()];
}

// Display the current guessed state of the word
void displayProgress(const string& guessed, int mistakesLeft, const string& usedLetters) {
    cout << endl << "Word: " << guessed << endl;
    cout << "Used letters: ";
    if (usedLetters.empty()) {
        cout << "None" << endl;
    }
    else {
        cout << usedLetters << endl;
    }
    cout << "Remaining mistakes: " << mistakesLeft << endl;
    cout << "-----------------------------" << endl;
}

// Core game logic
void playHangman(const string& word) {
    string guessed(word.length(), '_');
    string usedLetters = "";
    int mistakes = 0;
    const int maxMistakes = 7;

    // Reveal spaces right away
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ' ') {
            guessed[i] = ' ';
        }
    }

    cout << endl << "Let's start the game!" << endl;
    cout << "You can make up to " << maxMistakes << " mistakes." << endl;

    while (mistakes < maxMistakes && guessed != word) {
        displayProgress(guessed, maxMistakes - mistakes, usedLetters);

        cout << "Enter a letter (you can also press space if you think there's one): ";
        char letter;
        cin.get(letter);

        // If user presses Enter immediately after space, it may cause newline issue — fix it
        if (letter == '\n') continue;
        letter = tolower(letter);

        // Check if this letter was already guessed
        if (usedLetters.find(letter) != string::npos) {
            cout << "  You have used this letter once! Try a new one." << endl;
            continue;
        }

        // Mark letter as used
        usedLetters += (letter == ' ' ? '_' : letter); // display '_' for space in used letters
        usedLetters += ' ';

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == letter && guessed[i] == '_') {
                guessed[i] = word[i];
                correct = true;
            }
        }

        // Handle space guesses
        if (letter == ' ') {
            bool spaceExists = false;
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == ' ' && guessed[i] == '_') {
                    guessed[i] = ' ';
                    spaceExists = true;
                }
            }
            if (spaceExists)
                correct = true;
        }

        if (!correct) {
            mistakes++;
            cout << " Wrong guess (X)! Mistakes left: "
                << (maxMistakes - mistakes) << endl;
        }
        else {
            cout << " Correct guess!" << endl;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
    }

    cout << endl << "=====================================" << endl;
    if (guessed == word) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    }
    else {
        cout << " You lost! The correct word was: " << word << endl;
    }
    cout << "=====================================" << endl;
}

int main() {
    cout << "=====================================" << endl;
    cout << "           HANGMAN GAME" << endl;
    cout << "=====================================" << endl;

    vector<string> words = getWordsFromFile("words_question_2.txt");
    if (words.empty()) {
        cout << "No words available. Please add some to 'words_question_2.txt'." << endl;
        return 0;
    }

    string word = selectRandomWord(words);
    playHangman(word);

    cout << endl << "Thanks for playing!" << endl;
    return 0;
}



