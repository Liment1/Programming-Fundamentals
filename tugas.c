#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* tipe(char tipe_penj[]);
char *jenis_baju(char jenis[]);
int harga_baju(char tipe[], char nama[]);

int main()
{   
    char nama[50], tipe_penj[3], jenis[3], nom[7], kode_pemb[15];
    int  nota, banyak, jumlah;
    jumlah = 0;

    // Pengulangan sesai pembelian baju
    printf("Jumlah Pembelian Baju : ");
    scanf("%d", &banyak);
    printf("\n");

    // Template nota dan input
    printf("No. Nota\t: ");
    scanf("%d", &nota);
    printf("Nama Pembeli\t: ");
    scanf("%s", &nama);
    getchar();

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d ", nama[i]); 
    // }

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%-22s %-22s %-22s %-22s %-22s\n", "No. Artikel", "Nama", "Harga", "Jumlah", "Sub.Total");
    printf("----------------------------------------------------------------------------------------------------------------    \n");

    for (int i=0; i < banyak; i++)
    {
        scanf("%[^:]:%[^:]:%s", tipe_penj, jenis, nom);
        getchar();


        // fgets(kode_pemb, 13 ,stdin);
        // getchar();
        // sscanf(kode_pemb, "%[^:]:%[^:]:%[^\n]", tipe_penj, jenis, nom); 


        char *tipe_baju = tipe(tipe_penj);
        char *nama_baju = jenis_baju(jenis);
        int harga = harga_baju(tipe_baju, nama_baju);
        jumlah += harga;

        printf("%s %s %d %d\n", tipe_baju, nama_baju, harga, jumlah);
    }


    
    //lanjutan dari nota (pembelian, bayar, dll)

}

//Nama baju, return nama
char *tipe(char tipe_penj[]) 
{
    int len = strlen(tipe_penj);

    if (strcmp("KI", tipe_penj) == 0)
    {
        return "Konsyasi";
    }
    else if (strcmp("PS", tipe_penj) == 0)
    {
        return "Putus";
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
//AQWD
//Harga baju, return harga
int harga_baju(char tipe[], char nama[])
{
    if (strcmp(tipe, "Konsyasi") == 0 && strcmp(nama, "LP") == 0)
    {
        return 50900;
    }
    else if (strcmp(tipe, "Konsyasi") == 0 && strcmp(nama, "P") == 0)
    {
        return 40900;
    }
    else if (strcmp(tipe, "Putus") == 0 && strcmp(nama, "LP") == 0)
    {
        return 60900;
    }
    else if (strcmp(tipe, "Putus") == 0 && strcmp(nama, "P") == 0)
    {
        return 55900;
    }
}

//Diskon baju, return diskon
int diskon()
{

}
