#include <stdio.h>

void insertionSort(int array[], int length);
void printArray(int array[], int length);

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);

  printf("Original Array\n");
  printArray(array, length);

  insertionSort(array, length);

  printf("\n\nSorted Array\n");
  printArray(array, length);
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
