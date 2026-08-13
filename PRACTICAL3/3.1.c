#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for(i = 0; i < n - 1; i++) {
        minIndex = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;

    printf("Enter the number of marks: ");
    scanf("%d", &n);

    int original[n], bubble[n], selection[n], insertion[n];

    printf("Enter %d marks:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &original[i]);

        // Copy the original array into all three arrays
        bubble[i] = original[i];
        selection[i] = original[i];
        insertion[i] = original[i];
    }

    bubbleSort(bubble, n);
    printf("\nBubble Sort: ");
    printArray(bubble, n);

    selectionSort(selection, n);
    printf("Selection Sort: ");
    printArray(selection, n);

    insertionSort(insertion, n);
    printf("Insertion Sort: ");
    printArray(insertion, n);

    return 0;
}