#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[]) {
    vector<string> names(argv + 1, argv + argc);
    if (names.empty()) {
        names.push_back("Adam");
        names.push_back("Kira");
        names.push_back("Annalise");
    }
    Game gm{names};
    gm.play();
}
