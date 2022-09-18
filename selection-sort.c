#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeDisorderedArray(int *array, int length);
void initializeOrderedArray(int *array, int length);

void printArray(int array[], int length);

void selectionSort(int array[], int length);

int main() {
  int *array;
  int length = 100000; // ~9 seconds (~0.15 minutes)/ Ordered = ~9 seconds (~0.15 minutes)
  // int length = 1000000; // ~964 seconds (~16 minutes)/ Ordered = ~926 seconds (~15.4 minutes)

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeDisorderedArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t startDisordered = clock();
    selectionSort(array, length);
    clock_t endDisordered = clock();

    // printf("\nSorted Array\n");
    // printArray(array, length);

    initializeOrderedArray(array, length);
    clock_t startOrdered = clock();
    selectionSort(array, length);
    clock_t endOrdered = clock();

    // printf("\n\nElapsed Time (Disordered Array): %f seconds\n", (double)(endDisordered - startDisordered) / CLOCKS_PER_SEC);
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

void selectionSort(int array[], int length) {
  for (int i = 0; i < length; i++) {
    int minNumberPos = i;

    for (int j = i + 1; j < length; j++) {
      if (array[j] < array[minNumberPos]) {
        minNumberPos = j;
      }
    }

    if (minNumberPos != i) {
      int aux = array[i];
      array[i] = array[minNumberPos];
      array[minNumberPos] = aux;
    }
  }
}
