#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void initializeDisorderedArray(int *array, int length);
void initializeOrderedArray(int *array, int length);

void printArray(int array[], int length);

void bubbleSort(int array[], int length);

int main() {
  int *array;
  int length = 100000; // Disordered = ~21 seconds (~0.36 minutes)/ Ordered = ~0 seconds
  // int length = 1000000; // Disordered = ~2266 seconds (~37 minutes)/ Ordered = ~0.003 seconds

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeDisorderedArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t startDisordered = clock();
    bubbleSort(array, length);
    clock_t endDisordered = clock();

    // printf("\nSorted Array\n");
    // printArray(array, length);

    initializeOrderedArray(array, length);
    clock_t startOrdered = clock();
    bubbleSort(array, length);
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

void bubbleSort(int array[], int length) {
  int i, j, aux;
  bool swap;

  for (i = 0; i < length; i++) {
    swap = false;
    for (j = 0; j < (length - 1 - i); j++) {
      if (array[j] > array[j + 1]) {
        aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
        swap = true;
      }
    }

    if (!swap) {
      break;
    }
  }
}
