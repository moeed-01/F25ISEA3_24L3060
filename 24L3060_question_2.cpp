#include<iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> // for time based random seed
#include <algorithm>
using namespace std;

// Function to read words from a file
vector<string> getWordsFromFile(const string& filename) {
	vector<string> words;//store list of words from file(words.txt)
    ifstream file(filename);
    string word;

    if (!file) {
        cout << "Error: Cannot open file '" << filename << "'" << endl;
        return words;
    }

    while (file >> word) {
        words.push_back(word);
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

//  to display the current guessed state of the word
void displayProgress(const string& guessed, int mistakesLeft, const string& usedLetters) {
    cout << endl << "Word: " << guessed << endl;
    cout << "Used letters: ";
    if (usedLetters.empty()) {
        cout << "None" << endl;
    } else {
        cout << usedLetters << endl;
    }
    cout << "Remaining mistakes: " << mistakesLeft << endl;
    cout << "-----------------------------" << endl;
}

// Core game logic
void playHangman(const string& word) {
    string guessed(word.length(), '_');
    string usedLetters = ""; // To track guessed letters
    int mistakes = 0;
    const int maxMistakes = 7;

    cout << endl << "Let's start the game!" << endl;
    cout << "You can make up to " << maxMistakes << " mistakes." << endl;

    while (mistakes < maxMistakes && guessed != word) {
        displayProgress(guessed, maxMistakes - mistakes, usedLetters);

        cout << "Enter a letter: ";
        char letter;
        cin >> letter;
        letter = tolower(letter);

        // Check if this letter was already guessed
        if (usedLetters.find(letter) != string::npos) {
            cout << "  You have used this letter once! Try a new one." << endl;
            continue; // No decrement in mistake for reusing a letter
        }

        // Mark letter as used
        usedLetters += letter;
        usedLetters += ' '; // space for readability

        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == letter && guessed[i] == '_') {
                guessed[i] = word[i];
                correct = true;
            }
        }

        if (!correct) {
            mistakes++;
            cout << " Wrong guess(X)! Mistakes left: "
                << (maxMistakes - mistakes) << endl;
        } else {
            cout << " Correct guess!" << endl;
        }
    }

    cout << endl << "=====================================" << endl;
    if (guessed == word) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << " You lost! The correct word was: " << word << endl;
    }
    cout << "=====================================" << endl;
}

int main() {
    cout << "=====================================" << endl;
    cout << "           HANGMAN GAME" << endl;
    cout << "=====================================" << endl;

    // Change the file name here to match your new file
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



