#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int anyto_decimal (char *inp, int choice);
void decimal2biner(int decimal, char *binary) ;
void decimal_to_octal(int decimal, char *octal);
void decimal_to_hex(int n, char *hexa);
void *bintogray (char* bin, char *gray);

int main() 
{
    int n, choice, decimal;
    char inp[100], binary[100], octal[100], hexa[100], gray_code[100];
    int decimal_arr[100];

    //template
    printf("Masukkan jumlah input : ");
    scanf("%d", &n);
    char binary_arr[n][100], *octal_arr[n][100], *hexa_arr[n][100], *gray_code_arr[n][100];
    for (int i = 0; i < n; i++)
    {
        printf("[Koversi angka]\n\n");
        printf("=========================\n");
        printf("Jenis input\n");
        printf("1. Decimal\n2. Binary\n3. Octal\n4. Hexadecimal (dalam kapital)\n5. Gray Code\n");
        printf("=========================\n");
        printf("Pilih (1/2/3/4/5) : ");
        scanf("%d", &choice);
        printf("Masukkan angka : ");
        scanf("%s", inp);
        getchar();
        printf("\n", inp);

        //konversi semua jenis ke desimal
        decimal = anyto_decimal(&inp[0], choice);
        decimal_arr[i] = decimal;

        //TUGAS

        // strcpy(binary, binary_conv(&decimal));
        decimal2biner(decimal, &binary[0]);
        decimal_to_octal(decimal, &octal[0]);
        decimal_to_hex(decimal, &hexa[0]);
        bintogray(&binary[0], &gray_code[0]);

        // hexa_arr[i] = hexa_conv(&decimal, &hexa[0]);

        strcpy(binary_arr[i], binary);
        strcpy(octal_arr[i], octal);
        strcpy(hexa_arr[i], hexa);
        strcpy(gray_code_arr[i], gray_code);
    }

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-25s %-25s %-25s %-25s %-25s\n", "Decimal", "Binary", "Octal", "Hexadecimal", "Gray Code");
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-25d %-25s %-25s %-25s %-25s\n", decimal_arr[i], binary_arr[i], octal_arr[i], hexa_arr[i], gray_code_arr[i]);
    }
}

int anyto_decimal (char *inp, int choice)
{
    int temp = 0, len;
    char bin[strlen(inp)];
    char check;
    len = strlen(inp);

    //cek jenis input
    if (choice == 1)
    {
        temp= atoi(inp);
        return temp;
    }
    else if (choice == 2)
    {
        for (int i = 0; i < len; i++)
        {
            check = *(inp + i)-48;
            temp += check* (int) pow(2, (len-1)-i);
        }
        return temp;
    }
    else if (choice == 3)
    {
        for (int i = 0; i < len; i++)
        {
            check = *(inp + i)-48;
            temp += check* (int) pow(8, (len-1)-i);
        }
        return temp;
    } 
    else if (choice == 4)
    {
        for (int i = 0; i < len; i++)
        {
            if ( (int)(*(inp + i)) > 57)
            {
                check = *(inp + i)-55;
            }
            else
            {
                check = *(inp + i)-48;
            }
            temp += check* (int) pow(16, (len-1)-i);
        }
        return temp;
    }
    else if (choice == 5)
    {
        if (*inp == '0') 
        {
            temp = atoi(inp);
            return temp;
        }
        else{
            bin[0] = '1';
        }
        for (int i = 1; i < len; i++)
        {
            if (*(inp + i) == bin[i-1])
            {
                bin[i] = '0';
            }
            else
            {
                bin[i] = '1';
            }
        }
        for (int i = 0; i < len; i++)
        {
            check = *(bin + i)-48;
            temp += check* (int) pow(2, (len-1)-i);
        }
        return temp;
    }
}

//binary
void decimal2biner(int decimal, char *binary) 
{
    int i = 0;
    char temp[100];

    if (decimal == 0) {
        *(binary) = '0';
        *(binary+1) = '\0';
        return;
    }

    while (decimal > 0) {
        *(temp+i) = (decimal % 2) + 48;
        decimal = decimal / 2;
        i++;
    }

    //reverse
    *binary = *(temp+i-1);
    for (int start = 1; start < i; start++)
    {
        *(binary+start) = *(temp+i-1-start);
    }
    *(binary+i) = '\0';
}

//gray
void *bintogray (char* bin, char *gray)
{
    int temp, len;

    if (*bin == '0') 
    {
        *(gray) = '0';
        *(gray+1) = '\0';
        return;
    }

    len = strlen(bin);
    gray[0] = '1';
    for (int i = 1; i < len; i++)
    {
        if (*(bin + i-1) != *(bin + i))
        {
            gray[i] = '1';
        }
        else
        {
            gray[i] = '0';
        }
    }
    gray[len] ='\0';
}

//octal
void decimal_to_octal(int decimal, char *octal)
{
    int lol, i = 0;
    char value[100];

    if (decimal == 0) {
        *(octal) = '0';
        *(octal+1) = '\0';
        return;
    }
    
    while (decimal != 0)
    {
        lol = decimal % 8;
        value[i] = lol+48;
        decimal = decimal / 8;
        i++;
    }
    // membalikkan string oktal

    *octal = *(value+i-1);
    for (int start = 1; start < i; start++)
    {
        *(octal+start) = *(value+i-1-start);
    }
    *(octal+i) = '\0';
}


//hexa
void decimal_to_hex(int n, char *hexa) {
    int temp, i = 0;
    char value[100];
    if (n == 0) {
        *(hexa) = '0';
        *(hexa+1)= '\0';
        return;
    }
    while (n > 0) {
        temp = n % 16;
        if (temp < 10)
        {
            *(value+i) = temp + 48;
        }
        else
        {
            *(value+i) = temp + 55;
        }
        n = n / 16;
        i++;
    }

    //reverse
    *hexa = *(value+i-1);
    for (int start = 1; start < i; start++)
    {
        *(hexa+start) = *(value+i-1-start);
    }
    *(hexa+i) = '\0';
}
//void decimal_to_hexa(int decimal, char hexa) 
