#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(char *word){
    int size = 0;
    char *temp =word;
    while(*temp != '\0'){
        size++;
        temp++;
    }
    int start = 0;
    int end = size - 1;
    while(start < end){
        if (word[start] != word[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;

}
    
int countFrequency(char *word, char searchChar) {
    int count = 0;
    char *ptr = word;

    while (*ptr != '\0') {
        if (*ptr == searchChar) {
            count++;
        }
        ptr++;
    }
    return count;
}   


int main(){
    char *word;
    char search;
    int choice;
    cout<< "Enter a word" << endl;
    cin >> word;

    do {
        cout << "1. Check if the string is a palindrome\n";
        cout << "2. Count the frequency of a certain character\n";
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    switch (choice){
    case 1:{        
        if (checkPalindrome(word)){
            cout << word << " is Palindrome" << endl;
        }
        else{
            cout << word << " is NOT a Palindrome" << endl;
        }
        break;
    }
    case 2:{
        cout << "Enter the character to check its frequency: ";
        cin >> search;
        cout << "The frequency of '" << search << "' is: "<< countFrequency(word, search) << endl;
        break;
    }
    case 3:{
        cout << "Exiting the program. Goodbye!\n";
            break;
    }
    default: 
        cout << "Invalid choice. Please try again.\n";
    }
    }while(choice != 3);


    return 0;
}