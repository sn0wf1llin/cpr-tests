/*Goal: understand an
**issue with memory allocation
**in generic classes
*/
/***This code will not compile without errors*****/
#include "main.hpp"

int main()
{
    //StudentRecord is the generic class
    StudentRecord<int> srInt(0);
    srInt.setId(111111);
    int arrayInt[SIZE]={4,3,2,1,4};
    srInt.setGrades(arrayInt);
    srInt.printGrades();

    StudentRecord<char> srChar('-');
    srChar.setId(222222);
    char arrayChar[SIZE]={'A','B','C','D','F'};
    srChar.setGrades(arrayChar);
    srChar.printGrades();

    StudentRecord<float> srFloat(0.0);
    srFloat.setId(333333);
    float arrayFloat[SIZE]={2.75,4.0,3.7,2.8,3.99};
    srFloat.setGrades(arrayFloat);
    srFloat.printGrades();

    StudentRecord<string> srString("");
    srString.setId(4444);
    string arrayString[SIZE]={"B","B-","C+","B","A"};
    srString.setGrades(arrayString);
    srString.printGrades();

    return 0;
}
