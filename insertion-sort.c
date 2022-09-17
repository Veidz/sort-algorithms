#include <stdio.h>

void insertionSort(int array[], int length);

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);

  insertionSort(array, length);

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
