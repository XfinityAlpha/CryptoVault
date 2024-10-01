#include <stdio.h>
#include <string.h>

int main() {
    char pt[100] = {'\0'}, ct[100] = {'\0'}, key[100] = {'\0'}, extendedKey[100] = {'\0'}, rt[100] = {'\0'};
    int i, j = 0;

    printf("\nEnter the plain text: ");
    scanf("%s", pt);

    printf("\nEnter the key: ");
    scanf("%s", key);

    
    for(i = 0; i < strlen(pt); i++) {
        extendedKey[i] = key[j];
        j++;
        if (j == strlen(key)) {
            j = 0; 
        }
    }
    extendedKey[i] = '\0'; 
    printf("\nNew key is: %s", extendedKey);

    // Encryption: Converting plain text to cipher text
    for(i = 0; i < strlen(pt); i++) {
        ct[i] = (((pt[i] - 'a') + (extendedKey[i] - 'a')) % 26) + 'a');
    }
    ct[i] = '\0'; // Terminating the cipher text string
    printf("\n\nCipher text is: %s", ct);

    // Decryption: Converting cipher text to plain text
    for(i = 0; i < strlen(ct); i++) {
        rt[i] = (((ct[i] - 'a') - (extendedKey[i] - 'a') + 26) % 26) + 'a'); // Adding 26 to ensure no negative results
    }
    rt[i] = '\0'; // Terminating the plain text string
    printf("\n\nPlain text is: %s", rt);

    return 0;
}
