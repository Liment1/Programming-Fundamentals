#include <stdio.h>

int main()
{   
    char tipe_penj[3], nama[50];
    int  tipe_k, nom, nota, jumlah_pembelian;

    // Pengulangan sesai pembelian baju
    printf("Jumlah Pembelian Baju : ");
    scanf("%d", &jumlah_pembelian);
    printf("\n");

    // Template nota dan input
    printf("No. Nota\t: ");
    scanf("%d", &nota);
    printf("Nama Pembeli\t: ");
    scanf("%s", &nama);
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("%-22s %-22s %-22s %-22s %-22s\n", "No. Artikel", "Nama", "Harga", "Jumlah", "Sub.Total");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    for (int i=0; i < jumlah_pembelian; i++)
    {
        scanf("%[^:]:%d:%d", &tipe_penj, &tipe_k, &nom);
    }


    
    //lanjutan dari nota (pembelian, bayar, dll)

    //Nama baju, return nama
    char* nama_baju ()
    {

    }
    //Harga baju, return harga

    //Diskon baju, return diskon


}