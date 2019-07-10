// constructing vectors
// constructing vectors
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v);
void assignFunction(vector<float> v, int in);
void pushBackFunction(vector<int> v, int in);
void emplaceFunction(vector<int> v, int loc, int in);

void printVector(vector<int> v) {
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
}

void assignFunction(vector<int> v, int in) {
    cout<<"\nassigning "<<in<<" and printing the vector\n";
    //TODO: Finish the function
    v.assign(1, in);
    printVector(v);
}

void pushBackFunction(vector<int> v, int in) {
    cout<<"\npush back "<<in<<" and printing the vector\n";
    //TODO: Finish the function
    v.push_back(in);
    printVector(v);
}

void emplaceFunction(vector<int> v, int loc, int in) {
    vector<int>::iterator it;
    cout<<"\nemplacing "<<in<<" and printing the vector\n";
    //TODO: Finish the function
    it = v.begin() + loc;
    v.emplace(it, in);
    printVector(v);
}
