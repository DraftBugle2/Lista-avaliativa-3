#include <stdio.h>
#include <string.h>

int romanToDecimal(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToDecimalNumber(char* roman) {
    int result = 0;
    int prevValue = 0;

    for (int i = strlen(roman) - 1; i >= 0; i--) {
        int currentValue = romanToDecimal(roman[i]);

        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }

    return result;
}

void printBinaryWithoutLeadingZeros(int decimalNumber) {
    int started = 0;
    for (int i = 11; i >= 0; i--) {
        int bit = (decimalNumber >> i) & 1;
        if (bit || started) {
            printf("%d", bit);
            started = 1;
        }
    }
    if (!started) {
        printf("0");
    }
}

int main() {
    char romanNumber[13];
    scanf("%s", romanNumber);

    int decimalNumber = romanToDecimalNumber(romanNumber);

    printf("%s na base 2: ", romanNumber);
    printBinaryWithoutLeadingZeros(decimalNumber);
    printf("\n");

    printf("%s na base 10: %d\n", romanNumber, decimalNumber);

    printf("%s na base 16: %x\n", romanNumber, decimalNumber);

    return 0;
}
