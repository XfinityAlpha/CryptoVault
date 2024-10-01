#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encipher();
void decipher();

int main() {
    int choice;
    while (1) {
        printf("\n1. Encrypt Text");
        printf("\t2. Decrypt Text");
        printf("\t3. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                encipher();
                break;
            case 2:
                decipher();
                break;
            case 3:
                exit(0);
            default:
                printf("Please Enter Valid Option.\n");
                break;
        }
    }
}

void encipher() {
    unsigned int i, j;
    char input[50], key[10];
    
    printf("\n\nEnter Plain Text: ");
    scanf("%s", input);
    printf("Enter Key Value: ");
    scanf("%s", key);
    
    printf("\nResultant Cipher Text: ");
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key))
            j = 0;  
        // Encrypt only uppercase letters
        if (isalpha(input[i])) {
            printf("%c", 'A' + (((toupper(input[i]) - 'A') + (toupper(key[j]) - 'A')) % 26));
        } else {
            printf("%c", input[i]); 
            j--; 
        }
    }
    printf("\n");
}

void decipher() {
    unsigned int i, j;
    char input[50], key[10];
    int value;
    
    printf("\n\nEnter Cipher Text: ");
    scanf("%s", input);
    printf("Enter the Key Value: ");
    scanf("%s", key);
    
    printf("\nDecrypted Text: ");
    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j >= strlen(key))
            j = 0;  
        // Decrypt only uppercase letters
        if (isalpha(input[i])) {
            value = (toupper(input[i]) - 'A') - (toupper(key[j]) - 'A');
            if (value < 0)
                value += 26;
            printf("%c", 'A' + value);
        } else {
            printf("%c", input[i]); 
            j--;
        }
    }
    printf("\n");
}
