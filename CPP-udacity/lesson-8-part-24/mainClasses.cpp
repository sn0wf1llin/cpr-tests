#include <iostream>
using namespace std;

class Gameboard {
    char gamespace[4][4];

    public:
        Gameboard();
        ~Gameboard();
        void setPos(int x, int y, char c);
        char getPos(int x, int y);
        void printGamespace();
        int findSymbolCombination(char c);
};

int Gameboard::findSymbolCombination(char c){
    //diagonal
    int diagonal = 1;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i == j) {
                diagonal &= (gamespace[i][j] == c);
            }
        }
    }
    if (diagonal == 1){
        return diagonal;
    }

    //horizontal
    for (int i = 0; i < 4; i++){
        int horizontal = 1;
        for (int j = 0; j < 4; j++){
            horizontal &= (gamespace[i][j] == c);
        }
        if (horizontal == 1){
            return horizontal;
        }
    }
    //vertical
    int vertical = 1;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            vertical &= (gamespace[j][i] == c);
        }
        if (vertical == 1){
            return vertical;
        }
    }

    return 0;
}

Gameboard::Gameboard() {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            gamespace[i][j] = '-';
        }
    }
}

Gameboard::~Gameboard(){
    cout << "Cleaning ... " << endl;
}

void Gameboard::setPos(int x, int y, char c){
    if (0 <= x < 4 && 0 <= y < 4){
        gamespace[x][y] = c;
    } else {
        cout << "Error! " << "x = " << x << "; y = " << y << endl;
    }
}

char Gameboard::getPos(int x, int y){
    return gamespace[x][y];
}

void Gameboard::printGamespace() {
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << gamespace[i][j] << " ";
        }
        cout << "\n";
    }
}
