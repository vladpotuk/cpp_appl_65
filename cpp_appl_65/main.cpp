#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int MAX_LINES = 1000;

int main() {
    system("chcp 1251");
    system("cls");
    char inputPath[] = "input.txt";
    char outputPath[] = "output.txt";
    char buffer[1000];
    char lines[MAX_LINES][1000]; 

    FILE* inputFile = fopen(inputPath, "r");

    if (inputFile == NULL) {
        perror("log");
        return 1;
    }
    else {
        int lineCount = 0;

       
        while (fgets(buffer, 999, inputFile)) {
           
            if (lineCount < MAX_LINES) {
                strcpy(lines[lineCount], buffer);
                lineCount++;
            }
            else {
                cerr << "Перевищено максимальну кількість рядків." << endl;
                fclose(inputFile);
                return 1;
            }
        }

        fclose(inputFile);

      
        FILE* outputFile = fopen(outputPath, "w");
        if (outputFile == NULL) {
            perror("log");
            return 1;
        }

        for (int i = lineCount - 1; i >= 0; i--) {
            fputs(lines[i], outputFile);
        }

        fclose(outputFile);
    }

    cout << "Операція завершена успішно." << endl;

    return 0;
}
