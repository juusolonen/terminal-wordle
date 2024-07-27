#include "wordgame.h"
#include <iostream>
#include <cctype>
#include <string.h>

using namespace Utility;

void WordGame::guess()
{
    std::string gWord;
    std::cin >> gWord;

    while (gWord.length() != 5) {
        pw.print("Word must have 5 letters. Try again");
        std::cin >> gWord;
    }

    compare(&gWord);
    print_result();
}

void WordGame::startGame()
{
    currentInd = 0;
    
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
};
