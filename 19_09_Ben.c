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

    int count = 0;
    
    for (int i = 0; i < size; i++) {
        int d = 0;

        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                d = 1;
                break;
            }
        }

        if (d) {
            int occurrences = 0;
            for (int j = i + 1; j < size; j++) {
                if (array[i] == array[j]) {
                    occurrences++;
                }
            }
            
            if (occurrences > 0) {
                count++;
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", count);

    return 0;
}

