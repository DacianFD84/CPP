#include <stdio.h>

int main() {
    int age;

    // Take user input for age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Using if-else to categorize age
      if (age >= 18) {
        printf("You are an adult.\n");
    } else if (age >= 13) {
        printf("You are a teenager.\n");
    } else {
        printf("You are a child.\n");
    }

    // After the else block, we can check for another condition.
    if (age < 5) {
        printf("You are a toddler.\n");
    }

    return 0;
}
