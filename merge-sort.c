#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeDisorderedArray(int *array, int length);
void initializeOrderedArray(int *array, int length);

void printArray(int array[], int length);

void mergeSort(int array[], int length);
void mergeSortRecursion(int array[], int start, int end);
void mergeSortedArrays(int array[], int start, int middle, int end);

int main() {
  int *array;
  int length = 100000; // Disordered = ~0.10 seconds (~0.0016 minutes)/ Ordered = ~0.098 seconds (~0.0016 minutes)
  // int length = 1000000; // Disordered = ~0.97 seconds (~0.016 minutes)/ Ordered = ~0.094 seconds (~0.016 minutes)
  // int length = 10000000; // Disordered = ~10 seconds (~0.16 minutes)/ Ordered = ~9.8 seconds (~0.16 minutes)

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeDisorderedArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t startDisordered = clock();
    mergeSort(array, length);
    clock_t endDisordered = clock();

    // printf("\nSorted Array\n");
    // printArray(array, length);

    initializeOrderedArray(array, length);
    clock_t startOrdered = clock();
    mergeSort(array, length);
    clock_t endOrdered = clock();

    printf("\n\nElapsed Time (Disordered Array): %f seconds\n", (double)(endDisordered - startDisordered) / CLOCKS_PER_SEC);
    printf("\n\nElapsed Time (Ordered Array): %f seconds\n", (double)(endOrdered - startOrdered) / CLOCKS_PER_SEC);
  }
  else {
    printf("Memory not allocated\n");
    exit(0);
  }
}

void initializeDisorderedArray(int *array, int length) {
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    array[i] = rand() % 10;
  }
}

void initializeOrderedArray(int *array, int length) {
  for (int i = 0; i < length; i++) {
    array[i] = i + 1;
  }
}

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
}

void mergeSort(int array[], int length) {
  mergeSortRecursion(array, 0, length - 1);
}

void mergeSortRecursion(int array[], int start, int end) {
  if (start < end) {
    int middle = start + (end - start) / 2;
  
    mergeSortRecursion(array, start, middle);
    mergeSortRecursion(array, middle + 1, end);
  
    mergeSortedArrays(array, start, middle, end);
  }
}

void mergeSortedArrays(int array[], int start, int middle, int end) {
  int leftLength = middle - start + 1;
  int rightLength = end - middle;
  
  int *auxLeft, *auxRight;
  auxLeft = (int*)malloc(sizeof(int) * leftLength);
  auxRight = (int*)malloc(sizeof(int) * rightLength);
  
  int i, j, k;
  
  for (i = 0; i < leftLength; i++) {
    auxLeft[i] = array[start + i];
  }
  
  for (i = 0; i < rightLength; i++) {
    auxRight[i] = array[middle + 1 + i];
  }
  
  for (i = 0, j = 0, k = start; k <= end; k++) {
    if ((i < leftLength) && (j >= rightLength || auxLeft[i] <= auxRight[j])) {
      array[k] = auxLeft[i];
      i++;
    }
    else {
      array[k] = auxRight[j];
      j++;
    }
  }
}
