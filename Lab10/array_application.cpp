#include <iostream>
#include <string>
#include <chrono> // reequired to use sleep_for()
#include <thread> // reequired to use sleep_for()
using namespace std;


void getData(int noOfStudents, int id[], double marks[])
{
    int idInput;
    double marksInput;

    for (int i = 0; i < noOfStudents; i++)
    {
        cout << endl;
        cout << "Student " << i+1 << endl;

        cout << "id => ";
        cin >> idInput;
        id[i] = idInput;

        cout << "Marks => ";
        cin >> marksInput;
        marks[i] = marksInput;
    }
}

void display(int noOfStudents, int id[], double marks[])
{
    cout << endl;
    cout << "  id   " << "  " << " marks " << endl
         << "-------" << "  " << "-------" << endl;
    
    for (int i = 0; i < noOfStudents; i++)
    {
        cout << "  " << id[i] << "     " << marks[i] << endl;
    }
    cout << endl;
}

double getAverageMarks(int noOfStudents, double marks[])
{
    double tempmark = 0; //assume a temporary mark as 0
    for (int i = 0; i < noOfStudents; i++)
    {
        tempmark += marks[i]; //sum all marks
    }
    double average = tempmark/noOfStudents; // total sum / total student
    return average;
}

double getFailureRate(int noOfStudents, double marks[])
{
    double failMark = 50; // assume fail marks as 50
    int failIndicator = 0;

    for (int i = 0; i < noOfStudents; i++)
    {
        if (marks[i] < failMark)
        {
            failIndicator += 1; 
        }
    }

    double failSum = failIndicator;
    double failureRate = ((failSum/noOfStudents) * 100); // total fail/total students * 100
    return failureRate; 
}

int getRecordNoOfLowestMarks(int noOfStudents, double marks[])
{
    int lowMark = marks[0]; //assume that first element is smallest
    int recordLowest;
    for ( int i = 1; i < noOfStudents; i++ ) 
    {
        if ( lowMark > marks[i] )  
        {
            lowMark = marks[i]; //update smallest
            recordLowest = i; // find id with lowest mark
        }
    }
    return recordLowest;
}

int getRecordNoWithId(int noOfStudents, int id[], int targetid)
{
    int recordNo;
    for ( int i = 0; i < noOfStudents; i++ ) 
    {
        if ( id[i] == targetid ) // check if the element exist in array
        {
            recordNo = i; 
        }
    }
    return recordNo;
}

int main()
{
    const int noOfStudents = 5;

    int id[noOfStudents];
    double marks[noOfStudents];

    getData(noOfStudents, id, marks);
    display(noOfStudents, id, marks);

    double average = getAverageMarks(noOfStudents, marks);
    cout << "Average = " << average << endl << endl;
  
    double failureRate = getFailureRate(noOfStudents, marks);
    cout << "Failure Rate = " << failureRate << " %" << endl << endl;
     
    int recordLowest = getRecordNoOfLowestMarks(noOfStudents, marks);
    cout << "Record of Lowest Marks => " << endl;
     
    cout << "Record No = " << recordLowest + 1 << endl
    << " id = " << id[recordLowest] << endl
    << " Marks = " << marks[recordLowest] << endl << endl;


    cout << "Enter id to search marks => ";

    int targetid;
    cin >> targetid;

    int recordNo = getRecordNoWithId(noOfStudents, id, targetid);
    if (recordNo != -1)
    {
        cout << "Marks = " << marks[recordNo] << endl;
    }
    else
    {
        cout << "Marks not found!" << endl;
    }
}