#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main()
{
    int sorted[1000], reverse[1000], random[1000];
    int swaps1, swaps2, swaps3, comp1, comp2, comp3;
    insert_sorted(sorted);
    insert_sorted(reverse);
    reverse_array(reverse, 1000);
    insert_sorted(random);
    shuffle_random(random, 1000);
    system("color 3");

    printf("\tSorting algorithms!  |Average  |Best    |Worst\n");
    printf("\tBubble sort          |n^2      |n       |n^2\n");
    printf("\tSelection sort       |n^2      |n^2     |n^2\n");
    printf("\tQuick sort           |nxlogn   |nxlogn  |n^2\n");

    printf("\n\tBubble sort: \n");
    printf("\tSorted: ");
    bubble_sort(sorted, 1000);
    printf("\tDescending: ");
    bubble_sort(reverse, 1000);
    printf("\tRandom: ");
    bubble_sort(random, 1000);

    reverse_array(reverse, 1000);
    shuffle_random(random, 1000);

    printf("\n\tSelection sort: \n");
    printf("\tSorted: ");
    selection_sort(sorted, 1000);
    printf("\tDescending: ");
    selection_sort(reverse, 1000);
    printf("\tRandom: ");
    selection_sort(random, 1000);

    reverse_array(reverse, 1000);
    shuffle_random(random, 1000);

    printf("\n\tQuick sort: \n");
    printf("\tSorted: ");
    swaps1 = quick_sort(sorted, 0, 1000, &comp1);
    printf("\tComparisons = %d   Swaps = %d\n",comp1, swaps1);
    printf("\tDescending: ");
    swaps2 = quick_sort(reverse, 0, 1000, &comp2);
    printf("\tComparisons = %d  Swaps = %d\n",comp2, swaps2);
    printf("\tRandom: ");
    swaps3 = quick_sort(random, 0, 1000, &comp3);
    printf("\tComparisons = %d  Swaps = %d\n",comp3, swaps3);

    return 0;
}
