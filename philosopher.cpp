#include <iostream>
using namespace std;

const int N = 5; // number of philosophers

int state[N]; // 0 = thinking, 1 = hungry, 2 = eating

void test(int i) {
    if (state[i] == 1 && state[(i + 4) % N] != 2 && state[(i + 1) % N] != 2) {
        state[i] = 2;
        cout << "Philosopher " << i << " starts eating.\n";
    }
}

void take_fork(int i) {
    state[i] = 1;
    cout << "Philosopher " << i << " is hungry.\n";
    test(i);
}

void put_fork(int i) {
    state[i] = 0;
    cout << "Philosopher " << i << " puts down forks and starts thinking.\n";
    test((i + 4) % N);
    test((i + 1) % N);
}

int main() {
    int choice, phil;
    while (true) {
        cout << "\n1. Pick up fork\n2. Put down fork\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 3) break;
        cout << "Enter philosopher number (0 to " << N-1 << "): ";
        cin >> phil;
        if (phil < 0 || phil >= N) {
            cout << "Invalid philosopher number!\n";
            continue;
        }
        if (choice == 1) {
            take_fork(phil);
        } else if (choice == 2) {
            put_fork(phil);
        } else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
