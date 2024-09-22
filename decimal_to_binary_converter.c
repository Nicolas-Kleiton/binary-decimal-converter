#include <stdio.h>
#include <string.h>
#include <math.h>

void decimalToBinary(int n){
    
    if (n > 0){
        decimalToBinary(n / 2);
        printf("%d", n % 2);
    }
}

int binaryToDecimal(const char *binary){
    int decimal = 0;
    int size = strlen(binary);

    for(int i = 0; i < size; i++){
        if (binary[size - i - 1] == '1'){
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int main(void){

    int number;
    char continueChoice;
    char choice;
    char binary[64];

    do
    {   
        printf("How would you like to convert?\n");
        printf("1 - Decimal to binary\n");
        printf("2 - Binary to decimal\n");
        scanf(" %c", &choice);

        switch (choice)
    {
    case '1':
        
        puts("");
        printf("Enter a decimal number: ");
        scanf("%d", &number);
        printf("Number in binary: ");

        if(number == 0){
            printf("0");
        } else{
            decimalToBinary(number);
        }

        puts("");
        break;
    
    case '2':

        puts("");
        printf("Enter a binary number: ");
        scanf("%63s", binary);
        printf("Number in decimal: %d\n", binaryToDecimal(binary));
        puts("");
        break;
    
    default:
        printf("Invalid choice!\n");
        break;
    }

    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &continueChoice);
    puts("");

    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    printf("Thank you for using the converter!\n");

    return 0;
}
