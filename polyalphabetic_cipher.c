#include<stdio.h>
#include<string.h>

int main() {
    char pt[100] = {'\0'}, ct[100] = {'\0'}, key[100] = {'\0'}, rt[100] = {'\0'};
    int i, j;

    printf("\nEnter the plain text: ");
    scanf("%s", pt);

    printf("\nEnter the key: ");
    scanf("%s", key);

    // Extend the key length to match the plaintext
    j = 0;
    for(i = strlen(key); i < strlen(pt); i++) {
        if(j == strlen(key)) {
            j = 0;
        }
        key[i] = key[j];
        j++;
    }
    key[i] = '\0';  // Terminate the key string
    printf("\nNew key is: %s", key);

    // Encryption: Converting plain text to cipher text
    for(i = 0; i < strlen(pt); i++) {
        ct[i] = (((pt[i] - 97) + (key[i] - 97)) % 26) + 97;
    }
    ct[i] = '\0';  // Terminate the cipher text string
    printf("\n\nCipher text is: %s", ct);

    // Decryption: Converting cipher text to plain text
    for(i = 0; i < strlen(ct); i++) {
        if(ct[i] < key[i]) {
            rt[i] = 26 + ((ct[i] - 97) - (key[i] - 97)) + 97;
        } else {
            rt[i] = (((ct[i] - 97) - (key[i] - 97)) % 26) + 97;
        }
    }
    rt[i] = '\0';  // Terminate the plain text string
    printf("\n\nPlain text is: %s", rt);

    return 0;
}
