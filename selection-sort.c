#include <stdio.h>

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);

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

  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
}
