#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            text[i] = (ch - offset + shift) % 26 + offset;
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            text[i] = (ch - offset - shift + 26) % 26 + offset;
        }
    }
}

int main() {
    char text[256];
    int shift;
    char choice;

    printf("Enter text to encrypt/decrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    printf("Encrypt (E) or Decrypt (D): ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
