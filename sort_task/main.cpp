#include <QCoreApplication>
#include <iostream>

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void displayArray(int* array, int size) {
    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int array[] = {5, 2, 9, 1, 6};
    int size = sizeof(array) / sizeof(array[0]);

    void (*sortFunc)(int*, int);

    std::cout << "Select Sorting Algorithm:" << std::endl;
    std::cout << "1. Bubble Sort" << std::endl;
    std::cout << "2. Selection Sort" << std::endl;
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        sortFunc = &bubbleSort;
    } else if (choice == 2) {
        sortFunc = &selectionSort;
    } else {
        std::cout << "Invalid choice. Using Bubble Sort by default." << std::endl;
        sortFunc = &bubbleSort;
    }

    sortFunc(array, size);

    displayArray(array, size);

    return a.exec();
}
