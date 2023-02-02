#include <iostream>
using namespace std;

// note: \\ is translated as the character \ because \ is a special character
void displayHangman(int stage)
{
    switch (stage)
    {
        case 0:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;
        // switch
        
        case 1:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 2:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | /  " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 3:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | /| " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 4:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O  " << endl;
        cout << " | /|\\ " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 5:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | /|\\ " << endl;
        cout << " |  |  " << endl;
        cout << " | " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 6:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | /|\\ " << endl;
        cout << " |  |  " << endl;
        cout << " | /   " << endl;
        cout << " | " << endl;
        cout << " ========== " << endl;
        break;

        case 7:
        cout << " +----+ " << endl;
        cout << " |/ | " << endl;
        cout << " |  O " << endl;
        cout << " | /|\\ " << endl;
        cout << " |  | " << endl;
        cout << " | / \\ " << endl;
        cout << " | R.I.P. " << endl;
        cout << " ========== " << endl;
        break;
    }
}

void test2_1()
{
    for (int stage = 0; stage < 8; ++stage)
    {
    // system("cls"); // OR system("clear"); for Linux / MacOS
    displayHangman(stage);
    system("pause");
    }
}

int main()
{
    test2_1();
}