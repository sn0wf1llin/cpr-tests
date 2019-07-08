#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string getPlayerName() {
    string name;
    getline(cin, name);

    return name;
}

void getUserInput(int arr[]){
    cin >> arr[0] >> arr[1];
}
