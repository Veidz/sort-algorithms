#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[], int length);
void printArray(int array[], int length);

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);

  printf("Original Array\n");
  printArray(array, length);

  bubbleSort(array, length);

  printf("\n\nSorted Array\n");
  printArray(array, length);
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
