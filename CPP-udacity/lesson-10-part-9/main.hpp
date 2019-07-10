//header file for main.cpp

#include<iostream>

using namespace std;
const int SIZE = 5;

template <class T>
class StudentRecord
{
    const int size = SIZE;
    T grades[SIZE];
    int studentId;

    public:
        StudentRecord(T defInput);
        void setGrades(T* input);
        void setId(int idIn);
        void printGrades();
};

template<class T>
StudentRecord<T>::StudentRecord(T defInput){
    for (int i = 0; i < size; i++){
        grades[i] = defInput;
    }
}
template<class T>
void StudentRecord<T>::setGrades(T* input)
{
    for(int i=0; i < size; i++)
    {
        grades[i] = input[i];
    }
}

template<class T>
void StudentRecord<T>::setId(int idIn)
{
    studentId = idIn;
}

template<class T>
void StudentRecord<T>::printGrades()
{
    std::cout <<"ID# "<< studentId <<": ";
    for(int i=0; i < size; i++)
        std::cout << grades[i] << " ";
    std::cout << "\n";
}
