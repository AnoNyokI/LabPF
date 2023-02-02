#include <iostream>
#include <vector>
using namespace std;
// function to display all numbers in container v

void displayNumbersInVector(const vector<int>& v)
{
    int size = v.size();
    for (int i = 0; i < size; ++i)
    {
        cout << v.at(i) << " ";
    }
}

void test1_1()
{
    vector<int> num; // declared num to be a container of integers
    num.push_back(1); // add 1 into the container
    num.push_back(4); // add 4 into the container
    num.push_back(3); // add 3 into the container
    num.push_back(7); // add 7 into the container
    cout << "Size = " << num.size() << endl; // display container's size so far
    cout << "Numbers in container are: ";
    displayNumbersInVector(num);
    cout << endl;
}


int main()
{
    test1_1();
}
