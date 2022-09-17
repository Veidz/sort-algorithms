#include <stdio.h>

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);
  int i, j, aux;

  printf("Original Array\n");
  for (i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }

  for (i = 0; i < length; i++) {
    for (j = 0; j < (length - 1); j++) {
      if (array[j] > array[j + 1]) {
        aux = array[j];
        array[j] = array[j + 1];
        array[j + 1] = aux;
      }
    }
  }

  printf("\n\nSorted Array\n");
  for (i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
}
