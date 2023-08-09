#include <stdio.h>
  int main() {
        int data, num1 = 0, num2 = 1, temp, flag = 0;

        printf("Enter ur input:");
        scanf("%d", &data);

        if (data == num1 || data == num2) {
                printf("%d is a fibonacci number\n", data);
                return 0;
        }

        while (num2 <= data) {
                temp = num2;
                num2 = num1 + num2;
                num1 = temp;
                if (num2 == data) {
                        flag = 1;
                        break;
                }
        }

        if (flag) {
                printf("%d is a fibonacci number\n", data);
        } else {
                printf("%d is not a fibonacci number\n", data);
        }
        return 0;
  }
