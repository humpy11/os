#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    // Outer loop for each pass
    for (i = 0; i < size - 1; i++) {
        // Inner loop for comparing adjacent elements
        for (j = 0; j < size - i - 1; j++) {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// LOOK Disk Scheduling Algorithm
void LOOK(int arr[], int size, int head, int direction) {
    int i, j;
    int left[size], right[size];
    int leftSize = 0, rightSize = 0;

    // Dividing the requests into two parts: left and right of the head
    for (i = 0; i < size; i++) {
        if (arr[i] < head) {
            left[leftSize++] = arr[i];  // Store left-side requests
        } else {
            right[rightSize++] = arr[i]; // Store right-side requests
        }
    }

    // Sort the left and right parts using Bubble Sort
    bubbleSort(left, leftSize);
    bubbleSort(right, rightSize);

    // Traversing the requests in the direction of the head
    if (direction == 1) { // Moving right
        // First, visit all requests on the right side (in ascending order)
        for (i = 0; i < rightSize; i++) {
            printf("%d ", right[i]);
        }
        // Then, reverse and visit all requests on the left side (in descending order)
        for (i = leftSize - 1; i >= 0; i--) {
            printf("%d ", left[i]);
        }
    } else { // Moving left
        // First, visit all requests on the left side (in descending order)
        for (i = leftSize - 1; i >= 0; i--) {
            printf("%d ", left[i]);
        }
        // Then, visit all requests on the right side (in ascending order)
        for (i = 0; i < rightSize; i++) {
            printf("%d ", right[i]);
        }
    }

    // Print newline after servicing all requests
    printf("\n");
}

int main() {
    // Array of disk requests
    int arr[] = {98, 183, 41, 122, 14, 124, 165, 67};
    // Size of the disk requests array
    int size = sizeof(arr) / sizeof(arr[0]);
    // Starting point of the disk head
    int head = 50;
    // Direction in which the disk head is moving (1 for right, -1 for left)
    int direction = 1;

    // Print the disk request sequence in the LOOK algorithm
    printf("Disk request sequence in LOOK algorithm: \n");

    // Call LOOK function to process the requests
    LOOK(arr, size, head, direction);

    return 0;
}
