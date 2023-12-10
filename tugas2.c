#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int anyto_decimal (char *inp, int choice);
void *bintogray (char* bin, char *gray);

int main() 
{
    int n, choice, decimal;
    char inp[100], binary[100], octal[100], hexa[100], gray_code[100];
    char *binary_arr[100], *octal_arr[100], *hexa_arr[100], *gray_code_arr[100];
    int decimal_arr[100];

    //template
    printf("Masukkan jumlah input : ");
    scanf("%d", &n);
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
        decimal = anyto_decimal (&inp[0], choice);
        printf("%d\n", decimal);
        decimal_arr[i] = decimal;

        //TUGAS

        // strcpy(binary, binary_conv(&decimal));

        bintogray(&binary[0], &gray_code[0]); //ini puny gw udh jadi, tunggu yg bkin binary

        // binary_binary[i] = binary_conv(&decimal, &binary[0]);
        // octal_arr[i] = octal_conv(&decimal, &octal[0]);
        // hexa_arr[i] = hexa_conv(&decimal, &hexa[0]);

    }

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-25s %-25s %-25s %-25s %-25s\n", "Decimal", "Binary", "Octal", "Hexadecimal", "Gray Code");
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    // for (int i = 0; i < n; i++)
    // {
    //      printf("%-25d %-25s %-25s %-25s %-25s\n", decimal_arr[i], binary_arr[i], octal_arr[i], hexa_arr[i], gray_code_arr[i]);
    // }
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
        bin[0] = '1';
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


//decimal
int binary2decimal(int n) {
    int decimal = 0;
    int i = 0;
    int sisa;
    //loop
    while(n != 0) {
        sisa = n % 10;
        n /= 10;
        decimal += sisa * pow(2, i);
        i++;
    }

    return decimal;
}

void *bintogray (char* bin, char *gray)
{
    int temp, len;

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