#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeDisorderedArray(int *array, int length);
void initializeOrderedArray(int *array, int length);

void printArray(int array[], int length);

void insertionSort(int array[], int length);

int main() {
  int *array;
  int length = 100000; // Disordered = ~4.4 seconds (~0.78 minutes)/ Ordered = ~0.001 seconds
  // int length = 1000000; // Disordered = ~475 seconds (~8 minutes)/ Ordered = ~0.003 seconds

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeDisorderedArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t startDisordered = clock();
    insertionSort(array, length);
    clock_t endDisordered = clock();

    // printf("\nSorted Array\n");
    // printArray(array, length);

    initializeOrderedArray(array, length);
    clock_t startOrdered = clock();
    insertionSort(array, length);
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

void insertionSort(int array[], int length) {
  int i, j, aux;

  for (i = 1; i < length; i++) {
    aux = array[i];

    for (j = i; (j > 0) && (aux < array[j - 1]); j--) {
      array[j] = array[j - 1];
    }

    array[j] = aux;
  }
}
