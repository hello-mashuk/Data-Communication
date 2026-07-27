//this is the c programme of Cyclic Redundancy Check (CRC)
// Data com Lab 

#include <stdio.h>
#include <string.h>

int main() {

    char data[50], generator[20], temp[50], remainder[20];
    char dividend[50];
    int datalen, genlen, i, j;

    printf("Enter Data bits : ");
    scanf("%s", data);

    printf("Enter Generator bits : ");
    scanf("%s", generator);

    datalen = strlen(data);
    genlen = strlen(generator);

    // Copy data and append zeros
    strcpy(temp, data);

    for (i = 0; i < genlen - 1; i++) {
        temp[datalen + i] = '0';
    }
    temp[datalen + genlen - 1] = '\0';

    strcpy(dividend, temp);

    // ---------------- Sender CRC Division ----------------
    for (i = 0; i < datalen; i++) {
        if (dividend[i] == '1') {
            for (j = 1; j < genlen; j++) {
                dividend[i + j] =
                    (dividend[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Extract remainder
    for (i = 0; i < genlen - 1; i++) {
        remainder[i] = dividend[datalen + i];
    }
    remainder[genlen - 1] = '\0';

    printf("\nCRC Remainder : %s\n", remainder);

    // Generate transmitted codeword
    strcpy(temp, data);
    strcat(temp, remainder);

    printf("Transmitted Codeword : %s\n", temp);

    // ---------------- Receiver Side ----------------
    printf("\nReceiver Checking...\n");

    strcpy(dividend, temp);

    // Divide received codeword
    for (i = 0; i < datalen; i++) {
        if (dividend[i] == '1') {
            for (j = 1; j < genlen; j++) {
                dividend[i + j] =
                    (dividend[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Check remainder
    int error = 0;

    for (i = datalen; i < datalen + genlen - 1; i++) {
        if (dividend[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error)
        printf("Oh No!! Error Found.\n");
    else
        printf("Yay! Error Free.\n");

    return 0;
}
