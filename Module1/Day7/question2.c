#include <stdio.h>
#include <ctype.h>
#include <string.h>

void changeCase(FILE* source, FILE* destination, int option) {
    char ch;
    int isWordStart = 1;

    while ((ch = fgetc(source)) != EOF) {
        if (option == 's') {
            if (isWordStart && isalpha(ch)) {
                ch = toupper(ch);
                isWordStart = 0;
            } else {
                ch = tolower(ch);
            }
        } else if (option == 'u') {
            ch = toupper(ch);
        } else if (option == 'l') {
            ch = tolower(ch);
        }

        fputc(ch, destination);

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            isWordStart = 1;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("  -u : Change file content to Upper Case\n");
        printf("  -l : Change file content to Lower Case\n");
        printf("  -s : Change file content to Sentence Case\n");
        return 1;
    }

    char* option = argv[1];
    char* sourceFileName = argv[2];
    char* destinationFileName = argv[3];

    FILE* sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE* destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    int optionLength = strlen(option);

    if (optionLength > 0 && option[0] == '-') {
        changeCase(sourceFile, destinationFile, option[1]);
    } else {
        char ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}