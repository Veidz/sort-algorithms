#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int *array, int length);
void swap(int *x, int *y);
void quickSort(int array[], int length);
void quickSortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);
void printArray(int array[], int length);

int main() {
  int *array;
  int length = 10;

  array = (int*)malloc(sizeof(int) * length);

  if (array != NULL) {
    initializeArray(array, length);

    // printf("Original Array\n");
    // printArray(array, length);

    printf("\n\nStart Sorting...\n");
    clock_t start = clock();
    quickSort(array, length);
    clock_t end = clock();

    // printf("\nSorted Array\n");
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

void swap(int *x, int *y) {
  int aux = *x;
  *x = *y;
  *y = aux;
}

void quickSort(int array[], int length) {
  quickSortRecursion(array, 0, length - 1);
}

void quickSortRecursion(int array[], int low, int high) {
  if (low < high) {
    int pivotIndex = partition(array, low, high);

    quickSortRecursion(array, low, pivotIndex - 1);
    quickSortRecursion(array, pivotIndex + 1, high);
  }
}

int partition(int array[], int low, int high) {
  int pivotValue = array[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (array[j] <= pivotValue) {
      swap(&array[i], &array[j]);
      i++;
    }
  }

  swap(&array[i], &array[high]);
  return i;
}
