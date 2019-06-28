#include <iostream>
#include <iomanip>
#include <fstream>
#include "linear_binary.h"

using namespace std;

void clearScreen()
{
  for (int i = 0; i < 10; i++)
  {
    cout << ("\n\n\n\n\n\n\n\n\n\n");
  }
}

int main()
{
  int integerList[200000];    // array to hold the integers read in from file
  int unsortedList[200000];   // array to hold the integers that is not sorted for linear search
  int listLength = 200000;
  int target = 0;
  int linearComparisons = 0;
  int binaryComparisons = 0;
  int linearIndex = 0;
  int binaryIndex = 0;
  int choice = 0;

  getData(integerList);


  for (int i = 0; i < 200000; i++)
  {
    unsortedList[i] = integerList[i];
      // stores an unsorted list of integers since the array has to be sorted for binary search
  }


  selectionSort(integerList, listLength);

  cout << "Sorting Complete" << endl;
  cout << "Press Enter to continue..." << endl;
  cin.get();



  do
  {
    clearScreen();

    cout << "*************************************************************************" << endl;
    cout << "* Search Algorithm Comparison                                           *" << endl;
    cout << "* Current Target: " << target << endl;
    cout << "*                                                                       *" << endl;
    cout << "* Search Metrics                                                        *" << endl;
    cout << "*                                                                       *" << endl;
    cout << "* Linear: " << linearComparisons << " comparisons" << endl;
    cout << "* Binary: " << binaryComparisons << " comparisons" << endl;
    cout << "*                                                                       *" << endl;
    cout << "* Linear - found at index: " << linearIndex << endl;
    cout << "* Binary - found at index: " << binaryIndex << endl;
    cout << "*                                                                       *" << endl;
    cout << "* <If target not found, index = -1>                                     *" << endl;
    cout << "*                                                                       *" << endl;
    cout << "* <Enter integer to search. Then select a search method>                *" << endl;
    cout << "*                                                                       *" << endl;
    cout << "* 1. Enter integer to search                                            *" << endl;
    cout << "* 2. Linear Search                                                      *" << endl;
    cout << "* 3. Binary Search                                                      *" << endl;
    cout << "* 4. Quit Program                                                       *" << endl;
    cout << "*************************************************************************" << endl;
    cout << "Please enter choice (1-4): ";
    cin >> choice;

    while (choice < 1 || choice > 4 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Please enter valid choice (1-4): ";
      cin >> choice;
    }

    switch (choice)
    {
      case 1:
        cout << "Please enter target number to search: ";
        cin >> target;

        while( cin.fail())
        {
          cout << "Please enter valid input: ";
          cin >> target;
        }
        break;

      case 2:
        linearIndex = linearSearch(unsortedList, listLength, target, linearComparisons);
        break;

      case 3:
        binaryIndex = binarySearch(integerList, listLength, target, binaryComparisons);
        break;

      case 4:
        cout << "Program Terminating" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
        break;
    }


  } while (choice != 4);




  return 0;
}
