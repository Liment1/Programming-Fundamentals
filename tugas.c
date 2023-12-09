#include <stdio.h>
#include <string.h>
#include <math.h>

//prototype
char* tipe(char tipe_penj[]);
char *jenis_baju(char jenis[]);
int harga_baju(char tipe[], char nama[]);
float diskon_func(char diskon);
const char* convert(int inp, int length, int currlen);

//buat konversi ke kata
char currstr[1000];

int main()
{   
    char nama[50], tipe_penj[3], jenis[3], nom[7], kode_pemb[13];
    int  nota, banyak, jumlah_baju, jumlah_bayar = 0, total = 0, bayar;
    char event;

    // Pengulangan sesai pembelian baju
    printf("-- INPUT USER --\n");
    printf("banyak pembelian Baju : ");
    scanf("%d", &banyak);
    getchar();
    printf("\n");

    char kode_arr[banyak][15], nama_arr[banyak][20], tipe_penj_arr[banyak][15];
    int harga_arr[banyak], jumlah_arr[banyak];

    //loop sesuai kemauan user
    for (int i=0; i < banyak; i++)
    {
        //input user
        printf("Pembelian ke %d\n", i+1);
        printf("kode %d\t\t: ", i+1);
        fgets(kode_pemb, 13, stdin); 
        char* ptr = strchr(kode_pemb, '\n'); 
        if (ptr) { 
            *ptr = '\0'; 
        } 
        
        sscanf(kode_pemb, "%[^:]:%[^:]:%s", tipe_penj, jenis, nom);
        printf("Banyak baju\t: ");
        scanf("%d", &jumlah_baju); 
        getchar();
        printf("\n");

        //function tipe, nama, harga, jumlah, total
        char *tipe_baju = tipe(tipe_penj);
        char *nama_baju = jenis_baju(jenis);
        int harga = harga_baju(tipe_baju, nama_baju);

        jumlah_bayar = harga*jumlah_baju;
        total += jumlah_bayar;

        //masukkan ke dalam array
        strcpy(kode_arr[i], kode_pemb);
        strcpy(tipe_penj_arr[i], tipe_baju);
        strcpy(nama_arr[i], nama_baju);
        harga_arr[i] = harga;
        jumlah_arr[i] = jumlah_bayar;
    }

    // Template nota dan input
    printf("%64s", "STRUK PEMBELIAN\n");
    printf("No. Nota\t: ");
    scanf("%d", &nota);
    getchar();
    printf("Nama Pembeli\t: ");
    scanf("%s", &nama);
    getchar();

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-25s %-25s %-25s %-25s %-25s\n", "No. Artikel", "Nama", "Harga", "Jumlah_bayar", "Sub.Total");
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    //lanjutan dari nota (pembelian, bayar, dll)
    for (int i = 0; i < banyak; i++)
    {
        printf("%-20s Kemeja %-21s Rp. %-28d %-20d Rp. %6d\n", kode_arr[i], strcat(tipe_penj_arr[i], nama_arr[i]), harga_arr[i], jumlah_baju, jumlah_arr[i]);
    }
    printf("%103s Rp. %6d\n", "", total);

    //Diskon dan Bayar
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("%-113s", "Event");
    scanf("%c", &event);

    //hitung harga diskon
    float diskon = diskon_func(event);
    //hitung harga setelah diskon
    int harga_diskon = total - (total*diskon);
    //pembayaran
    printf("%-110s %2.0f%%\n", "Jumlah Diskon", diskon*100);
    printf("%-103s Rp. %6d\n", "Total Belanja Setelah Diskon", harga_diskon);
    printf("%-103s Rp. ", "Jumlah bayar"); 
    scanf("%d", &bayar);
    getchar();
    
    if (harga_diskon > bayar)
    {
        printf ("\nJumlah uang yang dimasukkan tidak mencukupi, harap ulangi proses pembelian dari awal.\n");
    } 
    else 
    {
        printf("%-103s Rp. %6d\n", "Uang kembali", bayar - harga_diskon);
    }

    //mengubah ke kata-kata
    int num = bayar-harga_diskon;
    int dupe = num;
    int length = 0;

    while (dupe != 0)
    {
        dupe /= 10;1;        
        length++;
    }

    printf("%115s\n", convert(num, length, 1));
    printf ("%70s","~ Terima kasih ~");
}

//Nama baju, return nama
char *tipe(char tipe_penj[]) 
{
    int len = strlen(tipe_penj);

    if (strcmp("KI", tipe_penj) == 0)
    {
        return "Konsyasi ";
    }
    else if (strcmp("PS", tipe_penj) == 0)
    {
        return "Putus ";
    }
}

//jenis baju
char *jenis_baju(char jenis[])
{
    if (strcmp(jenis, "01") == 0)
    {
        return "LP";
    }

    if (strcmp(jenis, "00") == 0)
    {
        return  "P";
    }
}

//Harga baju, return harga
int harga_baju(char tipe[], char nama[])
{
    if (strcmp(tipe, "Konsyasi ") == 0 && strcmp(nama, "LP") == 0)
    {
        return 50900;
    }
    else if (strcmp(tipe, "Konsyasi ") == 0 && strcmp(nama, "P") == 0)
    {
        return 40900;
    }
    else if (strcmp(tipe, "Putus ") == 0 && strcmp(nama, "LP") == 0)
    {
        return 60900;
    }
    else if (strcmp(tipe, "Putus ") == 0 && strcmp(nama, "P") == 0)
    {
        return 55900;
    }
}

//Diskon baju, return diskon
float diskon_func(char event)
{
    if (event == 'R')
    {
        return 0.2;
    }
    else if (event == 'U')
    {
        return 0.15;
    }
    else if (event == 'G')
    {
        return 0.1;
    }
    else if (event == 'N')
    {
        return 0;
    }
    else
    {
        return 0;
    }
}

//mengubah angka menjadi kata-kata
const char* convert(int inp, int length, int currlen)
{
    char digit[10][20] = {"", "satu ", "dua ", "tiga ", "empat ", "lima ", "enam ", "tujuh ", "delapan ", "sembilan "};
    char thou[4][20] = {"", "ribu ", "juta ", "miliyar "};
    char hun[3][20] = {"ratus ", "", "puluh "};
    
    //cari digit pertama
    int power = pow(10, currlen-1);
    int currinp = (inp / power) % 10;
    int hundreds = currlen % 3;
    int thousands = (currlen-1) / 3;
    int puluh;
    if (hundreds == 2)
    {
        puluh = inp % (int) pow(10, currlen);
        puluh /= (int) pow(10, (currlen/3) * 3);
    }
    else if(hundreds == 1)
    {
        puluh = inp % (int) pow(10, currlen + 1);
        puluh /= (int) pow(10, (currlen/3) * 3);
    }
    

    //cek sepuluh dan seribu
    if (length - currlen == 1 && puluh == 11 && hundreds ==1)
    {
        strcpy(currstr, "sebelas ");
        strcat(currstr, thou[thousands]);
        return currstr;
    }
    else if (length - currlen == 1 && puluh == 10 && hundreds ==1)
    {
        strcpy(currstr, "sepuluh ");
        strcat(currstr, thou[thousands]);
        return currstr;
    }
    //cek angka pertama
    else if (currlen == length)
    {
        //cek seribu
        if (currinp == 1 && currlen == 4)
        {
            strcat(currstr, "seribu");
        }
        else if (hundreds == 0 && currinp == 1)
        {
            strcat(currstr, "seratus ");
        }
        //apabila angka == 0, maka tidak ada yang jalan
        else if (strlen(digit[currinp]) != 0)
        {
            strcpy(currstr, digit[currinp]);
            strcat(currstr, hun[hundreds]);
        }
        //print ribu, juta, miliyar
        if (currlen % 3 == 1 && !(currinp == 1 && currlen == 4))
        {
            strcat(currstr, thou[thousands]);
        }
        return currstr;
    }

    //recursioin
    convert(inp, length, currlen + 1);

    //sebelas dan sepuluh
    if (hundreds == 1)
    {
        if (puluh == 11)
        {
            strcat(currstr, "sebelas ");
            strcat(currstr, thou[thousands]);
        }
        else if (puluh == 10)
        {
            strcat(currstr, "sepuluh ");
            strcat(currstr, thou[thousands]);
        }
    }
    //seratus
    else if (hundreds == 0 && currinp == 1)
    {
        strcat(currstr, "se");
        strcat(currstr, hun[hundreds]);
    }
    //digit biasa
    else if (strlen(digit[currinp]) !=0 && !(puluh == 11 || puluh == 10))
    {
        strcat(currstr, digit[currinp]);
        strcat(currstr, hun[hundreds]);
    }
    
    
    //print ribu, juta, miliyar     
    if (hundreds == 1 && !(puluh == 11 && puluh == 10))
    {
        strcat(currstr, digit[currinp]);
        strcat(currstr, thou[thousands]);
    }
    return currstr;
} 