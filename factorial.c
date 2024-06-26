#include <stdio.h>

long long factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    printf("Factorial of %d is %lld\n", num, factorial(num));
    return 0;
}
