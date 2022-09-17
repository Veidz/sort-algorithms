#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int *array, int length);
void insertionSort(int array[], int length);
void printArray(int array[], int length);

int main() {
  int *array;
  int length = 10;

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeArray(array, length);

    printf("Original Array\n");
    printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t start = clock();
    insertionSort(array, length);
    clock_t end = clock();

    printf("\nSorted Array\n");
    printArray(array, length);

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
  int i, j, aux;

  for (i = 1; i < length; i++) {
    aux = array[i];

    for (j = i; (j > 0) && (aux < array[j - 1]); j--) {
      array[j] = array[j - 1];
    }

    array[j] = aux;
  }
}
