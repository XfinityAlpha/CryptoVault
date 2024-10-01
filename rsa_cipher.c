#include <stdio.h>
#include <string.h>

// Function to perform modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod; 
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        
        exp = exp >> 1; 
        base = (base * base) % mod; 
    }
    return result;
}

int main() {
    char m[100];
    int p[100], c[100], n = 253, d = 17, e = 13, i;
    
    printf("Enter message: ");
    scanf("%s", m);
    
    // Convert message to integers
    for (i = 0; i < strlen(m); i++)
        p[i] = m[i];

    // Encrypt
    printf("\nCT = ");
    for (i = 0; i < strlen(m); i++) {
        c[i] = mod_exp(p[i], e, n);
        printf("%d ", c[i]);
    }

    // Decrypt
    printf("\nPT = ");
    for (i = 0; i < strlen(m); i++) {
        p[i] = mod_exp(c[i], d, n);
        printf("%c", p[i]);
    }
    printf("\n");

    return 0;
}
