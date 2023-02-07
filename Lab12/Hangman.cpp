#include <iostream>
#include <vector>
#include<bits/stdc++.h>
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

// CHECK IF GUESS ALPHABET IS IN SECRETWORD
void fillWordWithCharGivenPositions(string secretword, char charToFill, string& word)
{

    for (int i = 0; i < secretword.size(); i++)
    {
        // return position value {3, 10} then fill char 'g' at word position 3 & 10
        if (toupper(secretword.at(i)) == charToFill)
        {
            word.at(i) = charToFill; 
        }
    }
}

int main()
{
    string secretword;
    bool gameOn = true;

    while (gameOn)
    {
        cout << "Secret word =>  ";
        cin >> secretword;
    
        // GENERATE '_' according to secretword length
        string word(secretword.length(), '_');
        string newWord(word); // '_' 


        bool winGame = false;
        int i = 0;

        while (!winGame)
        {  
            char guessChar;
            string currentWord;
            
            cout << "Word: ";
            cin >> guessChar;

            // MAKE IT CAPITAL LETTER
            char GUESSCHAR = toupper(guessChar);

            currentWord = newWord;
            fillWordWithCharGivenPositions(secretword , GUESSCHAR, newWord);
            cout << newWord << endl;

            // MAKE SECRETWORD CAPITAL LETTER
            transform(secretword.begin(), secretword.end(), secretword.begin(), ::toupper);

            if (newWord == secretword)
            {
                cout << "YOU WON!" << endl;
                winGame = true;
                cout << endl;
            }
            if (currentWord == newWord)
            {   
                if (i <= 7)
                {
                    displayHangman(i);
                    i++;
                }
                else 
                {
                    cout << "YOU LOSE!" << endl;
                    winGame = true;
                    cout << endl;
                }
            }
        }
    } 
}