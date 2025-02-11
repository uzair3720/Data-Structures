#include<iostream>
using namespace std;

void swap(int *num1, int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(){

    int num1, num2;
    cout << "Enter Num1 & Num2" << endl;
    cin >> num1 >> num2;
    cout << "Numbers before swapping" << endl;
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;

    swap(num1, num2);
    
    cout << "Numbers after swapping" << endl;
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;



    return 0; 
}