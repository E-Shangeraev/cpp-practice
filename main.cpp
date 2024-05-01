#include <iostream>
#include <cstring>

using namespace std;


// ========= Helpers ==========

void printArray(int array[], int size, string title = "") {
  cout << endl << title << endl;

  for (int i = 0; i < size; i++) {
    cout << array[i] << ' ';
  }

  cout << endl;
}

void swap(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}

// ============================


// ======= Bubble sort ========

void bubbleSort(int array[], int size) {
  int arrayCopy[size];
  memcpy(arrayCopy, array, size * sizeof(array[0]));

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arrayCopy[j] > arrayCopy[j + 1]) {
        swap(arrayCopy[j], arrayCopy[j + 1]);
      }
    }
  }

  printArray(arrayCopy, size, "Bubble sort:");
}

// ============================


// ====== Selection sort ======

void selectionSort(int array[], int size) {
  int arrayCopy[size];
  memcpy(arrayCopy, array, size * sizeof(array[0]));

  for (int i = 0; i < size - 1; i++) {
    int minIndex = i; 

    for (int j = i + 1; j < size; j++) {
      if (arrayCopy[j] < arrayCopy[minIndex]) {
        minIndex = j;
      }
    }

    swap(arrayCopy[minIndex], arrayCopy[i]);
  }

  printArray(arrayCopy, size, "Selection sort:");
}

// ============================


// ======== Quick sort ========

int partition(int array[], int left, int right, int pivot) {
  while(true) {
    while(array[left] < pivot) {
      left += 1;
    }

    while(array[right] > pivot) {
      right -= 1;
    }

    if (left >= right) {
      return right + 1;
    }

    swap(array[left], array[right]);

    left += 1;
    right -= 1;
  }
};

void sort(int array[], int left, int right) {
  int length = right - left + 1;

  if (length < 2) {
    return;
  }

  int pivot = array[left];
  int splitIndex = partition(array, left, right, pivot);
  
  sort(array, left, splitIndex - 1);
  sort(array, splitIndex, right);
};

void quickSort(int array[], int size) {
  int arrayCopy[size];
  memcpy(arrayCopy, array, size * sizeof(array[0]));

  sort(arrayCopy, 0, size);

  printArray(arrayCopy, size, "Quick sort:");
}

// ==========================


int main() {
  int array[] {5, 3, 7, 8, 2, 6, 1, 9, 4, 0};
  const int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);
  selectionSort(array, size);
  quickSort(array, size);

  return 0;
}
