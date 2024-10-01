#include<stdio.h>
#include<string.h>

int mult(int x, int y, int n) {
    int k = 1;
    int j;
    for (j = 1; j <= y; j++) 
        k = (k * x) % n;
    return k;
}

int main() {
    char m[100];
    int p[100], c[100], n = 253, d = 17, e = 13, i;
    
    printf("Enter message: ");
    scanf("%s", m);
    
    for (i = 0; i < strlen(m); i++)
        p[i] = m[i];
    
    printf("\nCT = ");
    for (i = 0; i < strlen(m); i++) 
        c[i] = mult(p[i], e, n);
    for (i = 0; i < strlen(m); i++) 
        printf("%d ", c[i]);

    printf("\nPT = ");
    for (i = 0; i < strlen(m); i++) 
        p[i] = mult(c[i], d, n);
    for (i = 0; i < strlen(m); i++) 
        printf("%c", p[i]);
    
    return 0;
}
