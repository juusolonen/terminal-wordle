#include "wordgame.h"
#include <iostream>
#include <cctype>
#include <string.h>
#include <fstream>

using namespace Utility;

void WordGame::guess()
{
    std::string gWord;
    std::cin >> gWord;

    while (gWord.length() != 5) {
        pw.print("Word must have 5 letters. Try again");
        std::cin >> gWord;
    }
    pw.print("");
    compare(&gWord);
}

void WordGame::startGame()
{
    currentInd = 0;
    passed = false;

    if (wordllist->empty()) {
        readwords();
    }
    
    chooseword();

    for (auto row : rows) {
        memset(row, 0, sizeof(row));
    }
    pw.print("Game started. Guess a 5 letter word.");
}



void Utility::WordGame::print_result() {
    for (int i = 0; i < currentInd; i++) {
        for (auto j : rows[i]) {
            BG_COLOR color = DEF;
            
            switch (j.pos)
            {
            case Correct:
                color = BG_GREEN;
                break;
            case WrongPlace:
                color = BG_YELLOW;
            default:
                break;
            }
            
            pw.colorprint(j.guessed, color);
        }
        pw.print("");
    }
    pw.print("*******************");
}

void WordGame::compare(std::string *gword) {
 if (currentInd < 5){
        int correctCount = 0;
        for (size_t i = 0; i < 5; i++)
        {
            char gc = gword->at(i);
            char correct = word.at(i);
            Position pos = None;

            if (gc == correct) {
                pos = Correct;
                correctCount++;
            } else if (word.find(gc) != word.npos) {
                pos = WrongPlace;
            }

            GuessedChar guessedChar;
            guessedChar.guessed = gc;
            guessedChar.pos = pos;
            rows[currentInd][i] = guessedChar;
            
            if (correctCount == 5) {
                passed = true;
                pw.print("CONGRATULATIONS! You guessed the correct word");
            }
        }
        currentInd++;
        *gword = "";
    } else {
        throw "Memory leak";
    }
}
bool WordGame::notComplete()
{
    return currentInd < 5 && passed == false;
}
void Utility::WordGame::promptNewGame() {
    pw.print("\n*************");
    std::string ans = pw.prompt("Do you want to start a new game? y/n");

    while (ans != "y" && ans != "n") {
        ans = pw.prompt("Invalid answer. Do you want to start a new game? y/n");
    }

    if (ans == "y") {
        startGame();
    }
}
void WordGame::readwords() {

    std::ifstream FileReader("wordlist.csv");
   
    for (int i = 0; i < 10; i++) {
        char cword[6];
        FileReader.get(cword, 6, ',');
        std::string sword(cword);
        wordllist->push_back(sword);
        FileReader.ignore(1, ',');
    }

}
void WordGame::chooseword() {
    int chosenIndex = rand() % 10;
    word = wordllist->at(chosenIndex);
};
