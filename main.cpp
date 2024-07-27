#include <stdio.h>
#include "printerwriter.h"
#include "wordgame.h"

using namespace Utility;

int main(int, char**){

    WordGame game;
    game.startGame();
    while(game.notComplete()){
        game.guess();
    }
    return 0;
}
