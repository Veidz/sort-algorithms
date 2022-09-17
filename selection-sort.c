#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int *array, int length);
void insertionSort(int array[], int length);
void printArray(int array[], int length);

int main() {
  int *array;
  int length = 100000; // ~9 seconds (~0.15 minutes)
  // int length = 1000000; // ~964 seconds (~16 minutes)

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t start = clock();
    insertionSort(array, length);
    clock_t end = clock();

    // printf("\n\nSorted Array\n");
    // printArray(array, length);

    printf("\n\nElapsed Time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
  }
  else {
    printf("Memory not allocated\n");
    exit(0);
  }
}

void initializeArray(int *array, int length) {
  srand(time(NULL));
  for (int i = 0; i < length; i++) {
    array[i] = rand() % 10;
  }
}

void printArray(int array[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
}

void insertionSort(int array[], int length) {
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
