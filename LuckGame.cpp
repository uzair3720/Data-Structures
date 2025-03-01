#include <iostream>

using namespace std;

const int SIZE = 3;

int main() {
    int seed = 123;
    srand(seed);

    char *grid = new char[SIZE * SIZE];

    for (int i = 0; i < SIZE * SIZE; ++i) {
        grid[i] = (rand() % 2 == 0) ? '-' : 'x';
    }

    grid[4] = 'o';
    char *ptr = &grid[4];
    

    int choice;
    cout << "\nChoose a move:\n1) Top\n2) Bottom\n3) Left\n4) Right\n";
    cin >> choice;

    char *new_ptr = ptr;
    switch (choice) {
        case 1: new_ptr = ptr - SIZE; break;
        case 2: new_ptr = ptr + SIZE; break;
        case 3: new_ptr = ptr - 1; break;
        case 4: new_ptr = ptr + 1; break;
        default:
            cout << "Invalid choice! Game over.\n";
            delete[] grid;
            return 0;
    }

    if (new_ptr < grid || new_ptr >= grid + SIZE * SIZE) {
        cout << "Invalid move! Out of bounds. Game over.\n";
        delete[] grid;
        return 0;
    }

    int current_row = (ptr - grid) / SIZE;
    int current_col = (ptr - grid) % SIZE;
    int new_row = (new_ptr - grid) / SIZE;
    int new_col = (new_ptr - grid) % SIZE;

    bool valid = false;
    switch (choice) {
        case 1: valid = (new_row == current_row - 1) && (new_col == current_col); break;
        case 2: valid = (new_row == current_row + 1) && (new_col == current_col); break;
        case 3: valid = (new_row == current_row) && (new_col == current_col - 1); break;
        case 4: valid = (new_row == current_row) && (new_col == current_col + 1); break;
    }

    if (!valid) {
        cout << "Invalid move! Cannot move outside the grid. Game over.\n";
        delete[] grid;
        return 0;
    }

    if (*new_ptr == '-') {
        cout << "Safe Place, You won.\n";
    } else if (*new_ptr == 'x') {
        cout << "You lost!, collided\n";
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i * SIZE + j] << " ";
        }
        cout << "\n";
    }

    delete[] grid;
    return 0;
}
