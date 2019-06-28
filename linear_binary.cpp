#include <iostream>
#include <iomanip>
#include <fstream>
#include "linear_binary.h"

using namespace std;

void getData(int list[])
{
  ifstream fin;

  fin.open("numbers.txt");
  if (fin)
  {
    cout << "File successfully opened" << endl;
    cout << "Sorting List.... Please wait" << endl;
  }
  else
  {
    cout << "File was not able to open" << endl;
    return;
  }

  for (int i = 0; i < 200000; i++)
  {
    fin >> list[i];
  }


  fin.close();
}


void selectionSort(int list[], const int& length)
{
  int index = 0;
  int smallestIndex = 0;
  int location = 0;
  int temp = 0;

  for (index = 0; index < length - 1; index++)
  {
    smallestIndex = index;

    for (location = index + 1; location < length; location++)
    {
      if (list[location] < list[smallestIndex])
      {
        smallestIndex = location;
      }
    }

    temp = list[smallestIndex];
    list[smallestIndex] = list[index];
    list[index] = temp;
  }


}


int linearSearch(const int list[], const int& length, const int& searchItem, int& comparisons)
{
  int location = 0;
  bool found = false;

  comparisons = 0;

  while (location < length && !found)
  {

    comparisons++;


    if (list[location] == searchItem)
    {
      found = true;
    }
    else
    {
      location++;
    }
  }


  if (found)
  {
    return location;
  }
  else
  {
    return -1;
  }
}


int binarySearch(const int list[], const int& length, const int& searchItem, int& comparisons)
{
  int first = 0;
  int last = length - 1;
  int mid = 0;
  bool found = false;
  comparisons = 0;


  while (first <= last && !found)
  {
    mid = (first + last) / 2;

    if (list[mid] == searchItem)
    {
      found = true;
      comparisons = comparisons + 1;
    }
    else if (list[mid] > searchItem)
    {
      last = mid -1;
      comparisons = comparisons + 2;
    }
    else
    {
      first = mid + 1;
      comparisons = comparisons + 2;
    }

    


  }

  if (found)
  {

    return mid;
  }
  else
  {
    return -1;
  }
}
