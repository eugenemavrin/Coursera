#include <iostream>
using namespace std;
int main() {
	int size = 20; //ограничение размера массива

	int *array = (int *) calloc(size, sizeof(int));
	int count = 1;
	int temp = 0;
	int i = 0;

	while (cin.peek() != '\n' && count <= size) { //последнее число должно быть не отрицательным
		cin >> temp;
		array[i] = temp;
		i++;
		count++;
	}

	array = (int*)realloc(array, sizeof(int) * count);
	int belowZero = 0;
	for (int i = 0; i < count - 1; i++) {

		if (array[i] < 0) {
			int j = i;
			while (j < count - 2) {
				array[j] = array[j + 1];
				j++;
			}
			belowZero++;
			--i;
		}
	}
	array = (int*)realloc(array, sizeof(int) * (count - belowZero));
	for (int i = 0; i < count - 1 - belowZero; i++) {
		cout << array[i] << " ";
	}

	free(array);
}

