#include <iostream>
#include <vector>
using namespace std;

void displayNumbersInVector(const vector<int>& v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        cout << v.at(i) << " ";
    }
}

void getPositionsOfCharInWord(const string& secretWord, char charToCheck, vector<int>& positions)
{
    positions.clear(); // clear the container
    int len = secretWord.size(); // get number of characters in string
    for (int i = 0; i < len; ++i)
    {
        if (secretWord[i] == charToCheck)
        {
            positions.push_back(i); // puhs the index I into container positions
        }
    }
}

void test1_2()
{
    string secretWord;
    secretWord = "programming";
    char guessChar = 'g';
    vector<int> positions; // declare positions to be a container of integers
    getPositionsOfCharInWord(secretWord, guessChar, positions);
    cout << "Secret word: " << secretWord << endl;
    cout << "Character: " << guessChar << endl;
    cout << "Positions: ";

    displayNumbersInVector(positions);
    cout << endl;
}

int main()
{
// test1_1();
    test1_2();
}