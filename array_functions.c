#include <stdio.h>
#include <stdlib.h>

void createArray(int **arr, int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);

    *arr = (int *)malloc(*size * sizeof(int));

    printf("Enter elements of the array:\n");
    for (int i = 0; i < *size; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &(*arr)[i]);
    }
}

void traverseArray(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int **arr, int *size, int element, int position) {
    (*size)++;
    *arr = (int *)realloc(*arr, *size * sizeof(int));

    for (int i = *size - 1; i > position; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }

    (*arr)[position] = element;
}

void deleteElement(int **arr, int *size, int position) {
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    (*size)--;
    *arr = (int *)realloc(*arr, *size * sizeof(int));
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, element, position;

    do {
        printf("\nMenu:\n");
        printf("1. Create Array\n");
        printf("2. Traverse Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(&arr, &size);
                break;
            case 2:
                traverseArray(arr, size);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertElement(&arr, &size, element, position);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(&arr, &size, position);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    free(arr);

    return 0;
}