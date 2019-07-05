/*Goal: sort students by multiple data vaule
**
**student1: Name: Joe Lime, ID#15, Grad. Date: 2019
**student2: Name: Bob Green, ID#3, Grad. Date: 2020
**student3: Name: SallyAnne Green , ID#1, Grad. Date: 2017
**student4: Name: Annie Blue, ID#10, Grad. Date: 2020
**student5: Name: Jose Lemon, ID#25, Grad. Date: 2016
*/

#include"main.hpp"

int main()
{
    string names[5] = {"Joe Lime", "Bob Green", "SallyAnne Green", "Annie Blue", "Jose Lemon"};
    int ids[5] = {15, 3, 1, 10, 25};
    int grad_dates[5] = {2019, 2020, 2017, 2020, 2016};

    for (int i = 0; i < 5; i++){
        printStudentInfo(i+1, names[i], ids[i], grad_dates[i]);
    }
    //ToDo sort the students by name, then by number, then by gradDate
    cout << "__________________________________________________________________\n";
    sortByID(names, ids, grad_dates);
    sortByGradDate(names, ids, grad_dates);
    sortByName(names, ids, grad_dates);
    for (int i = 0; i < 5; i++){
        printStudentInfo(i+1, names[i], ids[i], grad_dates[i]);
    }
    return 0;
}
