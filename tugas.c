#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* tipe(char tipe_penj[]);
char *jenis_baju(char jenis[]);
int harga_baju(char tipe[], char nama[]);
int diskon_func(char diskon);

int main()
{   
    char nama[50], tipe_penj[3], jenis[3], nom[7], kode_pemb[13];
    int  nota, banyak, jumlah_baju, jumlah_bayar, total, diskon;
    char event;
    jumlah_bayar = 0;

    // Pengulangan sesai pembelian baju
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
        printf("kode %d:  ", i+1);
        fgets(kode_pemb, 13, stdin); 
        char* ptr = strchr(kode_pemb, '\n'); 
        if (ptr) { 
            *ptr = '\0'; 
        } 
        
        sscanf(kode_pemb, "%[^:]:%[^:]:%s", tipe_penj, jenis, nom);
        printf("Banyak baju : ");
        scanf("%d", &jumlah_baju); 
        getchar();

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

        // printf("%s %s %s %d %d\n", kode_arr[i], tipe_penj_arr[i], nama_arr[i], harga_arr[i], jumlah_arr[i]);
        // printf("%s Kemeja %s %d %d %d\n\n", tipe_baju, nama_baju, harga, jumlah_bayar, total);
    }

    // Template nota dan input
    printf("No. Nota\t: ");
    scanf("%d", &nota);
    getchar();
    printf("Nama Pembeli\t: ");
    scanf("%s", &nama);
    getchar();

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d ", nama[i]); 
    // }

    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%-25s %-25s %-25s %-25s %-25s\n", "No. Artikel", "Nama", "Harga", "jumlah_bayar", "Sub.Total");
    printf("----------------------------------------------------------------------------------------------------------------    \n");
 
    //lanjutan dari nota (pembelian, bayar, dll)
    for (int i = 0; i < banyak; i++)
    {
        printf("%-22s Kemeja %s %s %d %-22d\n", kode_arr[i], tipe_penj_arr[i], nama_arr[i], harga_arr[i], jumlah_arr[i]);
        fflush(stdout);
    }
    printf("%d", total);
    scanf("%c", event);
    diskon = diskon_func(event);
    pritnf("%d", diskon);

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
int diskon_func(char diskon)
{
    if
    {
        return ;
    }
}