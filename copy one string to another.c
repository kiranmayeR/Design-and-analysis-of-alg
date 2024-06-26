#include <stdio.h>
#include <string.h>

void copyString(char* destination, const char* source) {
    strcpy(destination, source);
}

int main() {
    char source[] = "Hello, World!";
    char destination[50];

    copyString(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
