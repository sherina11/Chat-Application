#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sendMessage(char username[]) {
    FILE *fp = fopen("chat.txt", "a");
    char message[200];

    getchar(); // clear buffer

    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    fprintf(fp, "%s: %s", username, message);
    fclose(fp);

    printf("Message Sent!\n");
}

void viewMessages() {
    FILE *fp = fopen("chat.txt", "r");
    char ch;

    printf("\n--- Chat History ---\n");

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}

int main() {
    char username[50];
    int choice;

    printf("Enter your username: ");
    scanf("%s", username);

    while (1) {
        printf("\n1. Send Message\n2. View Messages\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: sendMessage(username); break;
            case 2: viewMessages(); break;
            case 3: exit(0);
        }
    }
}