#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define pivot_index() (begin+(end-begin)/2)
#define swapD(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

void insert_sorted(int arr[])
{
    int i;
    for(i=0; i<1000; i++)
        arr[i] = i;
}

void reverse_array(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void shuffle_random(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n)
{
    int swapcount = 0, compcount = 0, i, j;
    for(i=0; i<n; i++) // n = array size
        for(j = 0; j < n-i-1; j++)  // Last i elements are already in place
        {
            compcount++;
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapcount++;
            }
        }
    printf("\tComparisons = %d Swaps = %d\n", compcount, swapcount);
}

void selection_sort(int a[], int s)
{
    int i ,j, swapcount = 0, compcount = 0;
    for(i=0; i<s; i++)
    {
        for(j=i+1; j<s; j++)
        {
            compcount++;
            if(a[i]>a[j])
            {
                swap(&a[i], &a[j]);
                swapcount++;
            }
        }
    }
    printf("\tComparisons = %d ", compcount);
    printf("Swaps = %d\n", swapcount);
}

int quick_sort(int array[], int begin, int end, int *comp)
{
    int pivot;
    static int swapcount = 0;
    static int compcount = 0;
    int t;     /* temporary variable for swap */
    compcount++;
    if (end > begin)
    {
        int l = begin + 1;
        int r = end;
        swapD(array[begin], array[pivot_index()], t); /* choose arbitrary pivot */
        swapcount++;
        pivot = array[begin];
        while(l < r)
        {
            compcount++;
            if (array[l] <= pivot)
            {
                l++;
            }
            else
            {
                while(l < --r && array[r] >= pivot) /* skip superfluous swaps */
                    ;
                swapD(array[l], array[r], t);
                swapcount++;
            }
        }
        l--;
        swapD(array[begin], array[l], t);
        *comp = compcount;
        swapcount++;
        quick_sort(array, begin, l, comp);
        quick_sort(array, r, end, comp);
    }
    return swapcount;
}
