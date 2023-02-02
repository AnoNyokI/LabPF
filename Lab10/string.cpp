#include <iostream>
#include <chrono> // reequired to use sleep_for()
#include <thread> // reequired to use sleep_for()
using namespace std;

void delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void display(const string& text)
{
    int size = text.length();

    for (int i = 0; i < size; ++i)
    {
        cout << text[i];
    }
    cout << endl;
}

void rotateLeft(string& text)
{   
    int size = text.length();

    int tempChar = text[0];

    //set second element as third element
    for (int i = 0; i < size - 1; ++i)
    {
        text[i] = text[i + 1];
    }
    // set last element in array as first element which is P
    text[size - 1] = tempChar;
}

void rotateRight(string& text)
{
    int size = text.length();
    
    int tempChar = text[size - 1];

    // set second element as 13th element
    for (int i = size - 1; i > 0; --i)
    {
        text[i] = text[i - 1];
    }
    // set first element in array as 14th element which is empty space.
    text[0] = tempChar;
}

int main()
{
    string greetText1 = "PROGRAMMING ";
    string greetText2 = "IS FUN! ";

    while (true)
    {
        system("cls"); // or system("clear"); for Linux/MacOS
        display(greetText1);
        rotateLeft(greetText1);
        display(greetText2);
        rotateRight(greetText2);
        delay(200); // delay for certain milliseconds
    }
}