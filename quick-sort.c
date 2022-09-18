#include <stdio.h>

void swap(int *x, int *y);
void quickSort(int array[], int length);
void quickSortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);

  quickSort(array, length);

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
