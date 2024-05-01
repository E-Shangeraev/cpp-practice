#include <iostream>
#include <cstring>

using namespace std;

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

int main() {
  int array[] {5, 3, 7, 8, 2, 6, 1, 9, 4, 0};
  const int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);
  selectionSort(array, size);

  return 0;
}
