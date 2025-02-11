#include<iostream>
using namespace std;


void populate(int **arr, int week, int days){

    for (int i = 0; i < week; i++){
        for(int j = 0; j<days; j++){
            *(arr[i]+j) = rand() % 21 + 10;
        }
    }
}

void display(int **arr, int week, int days){

    for (int i = 0; i < week; i++){
        for(int j = 0; j<days; j++){
        cout << *(arr[i]+j) << "   ";
        }
        cout << endl;
    }

}

void hottestDay(int **arr, int weeks, int days) {
    for (int i = 0; i < weeks; i++) {
        int maxTemp = *(arr[i]);
        int maxDay = 0; 
        
        for (int j = 1; j < days; j++) {
            if (*(arr[i] + j) > maxTemp) {
                maxTemp = *(arr[i] + j);
                maxDay = j;
            }
        }
        cout << "Hottest day in Week " << i + 1 << " is Day " << maxDay + 1 << " with " << maxTemp << "°C." << endl;
    }
}
int main(){
    int week = 4;
    int days = 7;
    int **temprature;

     temprature = new int*[week];
    for (int i = 0; i < week; i++) {
        temprature[i] = new int[days];
    }
    populate(temprature, week, days);

    display(temprature, week, days);

    hottestDay(temprature, week, days);

    return 0;
}