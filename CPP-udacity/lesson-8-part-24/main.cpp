#include "mainFunctions.cpp"
#include "mainClasses.cpp"

using namespace std;

int main(){
    Gameboard g = Gameboard();
    int i1[2];
    int i2[2];

    // cout << "1 Name: " << endl;
    string player1Name = getPlayerName();
    // cout << "2 Name: " << endl;
    string player2Name = getPlayerName();

    for (int i = 0; i < 16; i++){
        getUserInput(i1);
        getUserInput(i2);

        g.setPos(i1[0], i1[1], 'x');
        g.setPos(i2[0], i2[1], 'y');
        // g.printGamespace();

        int isXWin = g.findSymbolCombination('x');
        if (isXWin == 1){
            cout << player1Name << endl;
            break;
        }

        int isYWin = g.findSymbolCombination('y');
        if (isYWin == 1){
            cout << player2Name << endl;
            break;
        }

    }
    return 0;
}
