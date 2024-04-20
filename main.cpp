#include <iostream>
#include <cstring>

using namespace std;

template <size_t N>
void printArray(int (&array)[N]) {
  cout << endl;

  for (int &i : array) {
    cout << array[i] << ' ';
  }
}

void bubbleSort(int array[], const int size) {
  int arrayCopy[size];
  memcpy(arrayCopy, array, size); 

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arrayCopy[j] > arrayCopy[j + 1]) {
        int temp = arrayCopy[j];
        arrayCopy[j] = arrayCopy[j + 1];
        arrayCopy[j + 1] = temp;
      }
    }
  }

  printArray(arrayCopy);
}

int main() {
  int array[] = {5, 3, 7, 8, 2, 6, 1, 9, 4, 0};
  const int size = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, size);

  return 0;
}
