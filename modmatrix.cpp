#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int Modulus(int iN, int iMod) {
    return iN - (iN / iMod) * iMod;
}

char GetChar(int iGenerator, char cBase, int iRange) {
    return (cBase + Modulus(iGenerator, iRange));
}

int main() {
    // Color variables
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // User interaction variables
    bool keepRunning = true;
    char userInput;

    // Random seed
    srand(time(NULL));

    while (keepRunning) {
        // Clear screen
        system("cls");

        // Color code
        SetConsoleTextAttribute(hConsole, 2);

        char caRow[80];
        int j = rand() % 100;
        int k = rand() % 100;
        int l = rand() % 100;
        int m = rand() % 100;

        for (int i = 0; i < 80; ++i) {
            caRow[i] = GetChar(j + i * i, 33, 30);

            if (((i * i + k) % 71) == 0) {
                SetConsoleTextAttribute(hConsole, 7);
            } else {
                SetConsoleTextAttribute(hConsole, 2);
            }

            cout << caRow[i];
        }

        j = (j + 31);
        k = (k + 17);
        l = (l + 47);
        m = (m + 67);

        caRow[Modulus(j, 80)] = '-';
        caRow[Modulus(k, 80)] = ' ';
        caRow[Modulus(l, 80)] = '-';
        caRow[Modulus(m, 80)] = ' ';

        // User input for pausing/exiting
        cout << "\nPress 'p' to pause, 'q' to quit: ";
        cin >> userInput;

        switch (userInput) {
            case 'p':
                cout << "\nPaused. Press any key to resume.";
                cin.ignore(); // Clear input buffer
                cin.get();
                break;
            case 'q':
                keepRunning = false;
                break;
            default:
                break;
        }
    }

    return 0;
}

