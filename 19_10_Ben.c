 #include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Unique elements in the array: ");

    for (int i = 0; i < size; i++) {
        int d = 1;

        for (int j = 0; j < size; j++) {
            if (i != j && array[i] == array[j]) {
                d = 0;
                break;
            }
        }

        if (d) {
            printf("%d ", array[i]);
        }
    }

    printf("\n");

    return 0;
}
