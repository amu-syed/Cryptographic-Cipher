#include <stdio.h>
#include <string.h>

// 1. Struct: Bundles the plaintext/ciphertext and the encryption key together
struct SecureData {
    char message[100];
    char key;
};

// 2. Pointers: We pass the memory address (struct SecureData *data).
// This allows the function to directly alter the message in memory.
void processXOR(struct SecureData *data) {
    int len = strlen(data->message);

    // Strip the trailing newline character added by fgets
    if (len > 0 && data->message[len - 1] == '\n') {
        data->message[len - 1] = '\0';
        len--;
    }

    // Loop through the string and modify each byte in memory using the XOR bitwise operator (^)
    for (int i = 0; i < len; i++) {
        data->message[i] = data->message[i] ^ data->key;
    }
}

int main() {
    struct SecureData sessionData;
    int choice;

    printf("--- Cryptographic Data Masking Utility ---\n");

    // 3. Input validation: A robust while loop to sanitize user entries
    while (1) {
        printf("\n1. Encrypt/Decrypt a message\n2. Exit\nSelect option: ");

        // If the user types a letter when we expect a number, this catches the error safely
        if (scanf("%d", &choice) != 1) {
            printf("[-] Invalid input. Please enter 1 or 2.\n");
            while (getchar() != '\n'); // Clear the bad data from the input buffer
            continue;
        }

        while (getchar() != '\n'); // Clear the newline character left by scanf

        if (choice == 2) {
            printf("[*] Shutting down secure terminal...\n");
            break;
        } else if (choice != 1) {
            printf("[-] Invalid option. Please enter 1 or 2.\n");
            continue;
        }

        printf("[*] Enter the message (max 99 chars): ");
        // fgets is used instead of gets() to strictly enforce memory limits and prevent buffer overflows
        if (fgets(sessionData.message, sizeof(sessionData.message), stdin) != NULL) {
            printf("[*] Enter a single character encryption key: ");
            scanf("%c", &sessionData.key);

            // Pass the struct's memory address to the function using the & operator
            processXOR(&sessionData);

            printf("[+] Processed Output: %s\n", sessionData.message);
        }
    }
    return 0;
}
