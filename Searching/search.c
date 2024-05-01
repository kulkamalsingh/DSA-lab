#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int n;
            printf("Enter the number of elements in the array: ");
            scanf("%d", &n);
            int arr[n];
            printf("Enter array elements: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            int target;
            printf("Enter the element to search: ");
            scanf("%d", &target);
            int result = linear_search(arr, n, target);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found in the array.\n");
            }
        } else if (choice == 2) {
            int n;
            printf("Enter the number of elements in the sorted array: ");
            scanf("%d", &n);
            int arr[n];
            printf("Enter sorted array elements: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            int target;
            printf("Enter the element to search: ");
            scanf("%d", &target);
            int result = binary_search(arr, n, target);
            if (result != -1) {
                printf("Element found at index: %d\n", result);
            } else {
                printf("Element not found in the array.\n");
            }
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
