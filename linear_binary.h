
#ifndef LINEAR_BINARY_H
#define LINEAR_BINARY_H

void getData(int list[]);
  // function to read in data of 200,000 integers
  // postCondition: integers are read into an array


void selectionSort(int list[], const int& length);
  // function to sort the array using the selection sort algorithm
  // postCondition: the array is sorted from smallest to largest


int linearSearch(const int list[], const int& length, const int& searchItem, int& comparisons);
  // function to search the array using the linear/sequential search algorithm
  // postCondition: index of the search item and the number of comparisons made are returned by reference
  //                index of -1 is returned if item is not found


int binarySearch(const int list[], const int& length, const int& searchItem, int& comparisons);
  // function to search the array using the binary search algorithm
  // postCondition: index of the search item and the number of comparisons made are returned by reference
  //                index of -1 is returned if item is not found


#endif
