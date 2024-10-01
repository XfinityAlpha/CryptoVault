#include<stdio.h>
#include<string.h>

char dc[26] = "XDGSZANYOBTMJCEVFHKWPLQURI";
char ec[26] = "abcdefghijklmnopqrstuvwxyz";

void e(char* p);
void d(char* p);

int main() {
    char p[100];  // Buffer for input text

    printf("\n\nEnter plain text: ");
    scanf("%s", p);

    printf("\nAfter Encryption:\n-----------------\n");
    e(p);
    printf("%s", p);

    printf("\nAfter Decryption:\n-----------------\n");
    d(p);
    printf("%s", p);

    return 0;
}

void e(char *p) {
    int l = 0;
    while(*(p + l) != '\0') {
        *(p + l) = dc[*(p + l) - 97];
        l++;
    }
}

void d(char *p) {
    int l = 0;
    while(*(p + l) != '\0') {
        int i;
        for(i = 0; i < 26; i++) {
            if(dc[i] == *(p + l))
                break;
        }
        *(p + l) = ec[i];
        l++;
    }
}
