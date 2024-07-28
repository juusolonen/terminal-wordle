#ifndef GAME
#define GAME
#include "printerwriter.h"
#include <vector>

namespace Utility {

    enum Position {
        None,
        WrongPlace,
        Correct
    };
   
    struct GuessedChar {
        char guessed;
        Position pos;
    };

    class WordGame {
        public:
            WordGame(){
                 pw.hello();
            }
            void guess();
            void startGame();
            void print_result();
            void compare(std::string *gword);
            bool notComplete();
            void promptNewGame();
        private:
            void readwords();
            void chooseword();
            std::vector<std::string> wordllist[10];
            std::string word = "horse";
            PrinterWriter pw;
            GuessedChar rows[6][5];
            int currentInd = 0;
            bool passed = false;
    };
}
#endif