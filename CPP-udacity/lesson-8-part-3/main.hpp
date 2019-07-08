/*Header file for main.cpp*/

#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

void printStudentInfo(int i, string name, int id, int grad_date);
void sortByName(string * names, int * ids, int * grad_dates);
void sortByID(string * names, int * ids, int * grad_dates);
void sortByGradDate(string * names, int * ids, int * grad_dates);
void printArray(int* arr, int );
void reorderIntByInt(int* arr, pair<int, int> pr[5]);
void reorderStringByInt(string * arr, pair<int, int> pr[5]);
void reorderStringByString(string * arr, pair<string, int> pr[5]);
void reorderIntByString(int *arr, pair<string, int> pr[5]);

void reorderIntByInt(int* arr, pair<int, int> pr[5]){
  int narr[5];

  for (int i = 0; i < 5; i++){
      narr[i] = *(arr + pr[i].second);
  }
  for (int i = 0; i < 5; i++){
      arr[i] = narr[i];
  }
}

void reorderStringByInt(string * arr, pair<int, int> pr[5]){
    string narr[5];

    for (int i = 0; i < 5; i++){
        narr[i] = *(arr + pr[i].second);
    }
    for (int i = 0; i < 5; i++){
        arr[i] = narr[i];
    }
}

void reorderStringByString(string * arr, pair<string, int> pr[5]){
  string narr[5];

  for (int i = 0; i < 5; i++){
      int right_index = pr[i].second;
      narr[i] = *(arr + right_index);
  }
  for (int i = 0; i < 5; i++){
      arr[i] = narr[i];
}
}

void reorderIntByString(int *arr, pair<string, int> pr[5]){
  int narr[5];

  for (int i = 0; i < 5; i++){
      int right_index = pr[i].second;
      narr[i] = *(arr + right_index);
  }
  for (int i = 0; i < 5; i++){
      arr[i] = narr[i];
  }
}

void printStudentInfo(int i, string name, int id, int grad_date){
    cout << "student" << i << ": Name: " << name << " ID#" << id << ", Grad. Date: " << grad_date << endl;
}

void sortByName(string * names, int * ids, int * grad_dates){
    pair<string, int> names_indexes[5];

    for (int i = 0; i < 5; i++){
        names_indexes[i] = make_pair(*(names+i), i);
    }

    sort(names_indexes, names_indexes+5);

    reorderIntByString(grad_dates, names_indexes);
    reorderIntByString(ids, names_indexes);
    reorderStringByString(names, names_indexes);

}

void printArray(int * arr, int size){
    cout << "\n--------------\n";
    for (int i = 0; i  < size; i++){
        cout << *(arr + i) << " ";
    }
    cout << "\n--------------\n";
}

void sortByID(string * names, int * ids, int * grad_dates){
    pair<int, int> ids_indexes[5];
    for (int i = 0; i < 5; i++){
        ids_indexes[i] = make_pair(*(ids+i), i);
    }

    sort(ids_indexes, ids_indexes + 5);

    reorderIntByInt(grad_dates, ids_indexes);
    reorderIntByInt(ids, ids_indexes);
    reorderStringByInt(names, ids_indexes);
}

void sortByGradDate(string * names, int * ids, int * grad_dates){
    pair<int, int> dates_indexes[5];
    for (int i = 0; i < 5; i++){
        dates_indexes[i] = make_pair(*(grad_dates+i), i);
    }

    sort(dates_indexes, dates_indexes + 5);

    reorderIntByInt(grad_dates, dates_indexes);
    reorderIntByInt(ids, dates_indexes);
    reorderStringByInt(names, dates_indexes);
}

void printStudentsInfo(string * names, int * ids, int * grad_dates){
    for (int i = 0; i < 5; i++){
        printStudentInfo(i+1, names[i], ids[i], grad_dates[i]);
    }

}