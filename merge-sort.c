#include <stdio.h>

void mergeSort(int array[], int length);
void mergeSortRecursion(int array[], int start, int end);
void mergeSortedArrays(int array[], int start, int middle, int end);

int main() {
  int array[] = { 5, 3, 1, 8, 0 };
  int length = sizeof(array) / sizeof(array[0]);
  
  mergeSort(array, length);
  
  for (int i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
}

void mergeSort(int array[], int length) {
  mergeSortRecursion(array, 0, length - 1);
}

void mergeSortRecursion(int array[], int start, int end) {
  if (start < end) {
    int middle = start + (end - start) / 2;
  
    mergeSortRecursion(array, start, middle);
    mergeSortRecursion(array, middle + 1, end);
  
    mergeSortedArrays(array, start, middle, end);
  }
}

void mergeSortedArrays(int array[], int start, int middle, int end) {
  int leftLength = middle - start + 1;
  int rightLength = end - middle;
  
  int auxLeft[leftLength];
  int auxRight[rightLength];
  
  int i, j, k;
  
  for (i = 0; i < leftLength; i++) {
    auxLeft[i] = array[start + i];
  }
  
  for (i = 0; i < rightLength; i++) {
    auxRight[i] = array[middle + 1 + i];
  }
  
  for (i = 0, j = 0, k = start; k <= end; k++) {
    if ((i < leftLength) && (j >= rightLength || auxLeft[i] <= auxRight[j])) {
      array[k] = auxLeft[i];
      i++;
    }
    else {
      array[k] = auxRight[j];
      j++;
    }
  }  
}