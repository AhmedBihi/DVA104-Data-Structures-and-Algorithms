#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/*Preconditon:
  Postcondition: Insert 1000 numbers ascending
  return: */
void insert_sorted(int arr[]);

/*Preconditon:
  Postcondition: Reverse the order of numbers in a array
  return: */
void reverse_array(int arr[], int n);

/*Preconditon:
  Postcondition: Shuffle the inserted array
  return: */
void shuffle_random(int* array, size_t n);

/*Preconditon:
  Postcondition: Swap two integers
  return: */
void swap(int *xp, int *yp);

/*Preconditon:
  Postcondition: Sorts the array, prints swaps and comparisons
  return: */
void bubble_sort(int arr[], int n);

/*Preconditon:
  Postcondition: Sorts the array, prints swaps and comparisons
  return: */
void selection_sort(int a[], int s);

/*Preconditon:
  Postcondition: Sorts the array
  return: swaps*/
int quick_sort(int array[], int begin, int end, int *compcount);

#endif // SORT_H_INCLUDED
