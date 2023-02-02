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

void fillWordWithCharGivenPositions(const vector<int>& positions, char charToFill, string& word)
{
    int numOfPositions = positions.size();
    for (int i = 0; i < numOfPositions; i++)
    {
        // return position value {3, 10} then fill char 'g' at word position 3 & 10
        word.at(positions.at(i)) = charToFill;       
    }
}

void test1_3()
{
    vector<int> positions;
    positions.push_back(3);
    positions.push_back(10);

    string word;
    word = "pro_ra___n_";
    char charToFill = 'g';
    string newWord(word); // construct newWord based on word
    fillWordWithCharGivenPositions(positions, charToFill, newWord);
    
    cout << "Original word: " << word << "" << endl;
    cout << "After filling char " << charToFill << " at position ";
    displayNumbersInVector(positions);
    cout << ", the word becomes: " << newWord << endl;
}

int main()
{
    test1_3();
}