#include <iostream>

using namespace std;

void replaceCharacter(string &input, char find, char replace) {
    char *ptr = &input[0];
    while (*ptr != '\0') {
        if (*ptr == find) {
            *ptr = replace;
        }
        ptr++;
    }
}

void capitalizeString(string &input) {
    char *ptr = &input[0];
    while (*ptr != '\0') {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

int main() {
    string input;
    char find, replace;

    cout << "Enter a word: ";
    cin >> input;

    cout << "Enter character to find: ";
    cin >> find;

    cout << "Enter replacement character: ";
    cin >> replace;

    replaceCharacter(input, find, replace);
    cout << "Updated string: " << input << endl;

    capitalizeString(input);
    cout << "Capitalized string: " << input << endl;

    return 0;
}
