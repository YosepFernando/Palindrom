#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

void menu();
void header();
void headerKeluar();
void ngulang();
void bukaFile();
void cekKata();
void inputFile();
void validString();

int main(){
    system ("clear");
    menu();
    return 0;
}

void header(){
    printf ("====================================================\n");
    printf ("+          PRAKTIKUM ALGORITMA PEMROGRAMAN         +\n");
    printf ("+                     MODUL IV                     +\n");
    printf ("+ ------------------------------------------------ +\n");
    printf ("+              PROGRAM KATA PALINDROM              +\n");
    printf ("+                  OLEH KELOMPOK 16                +\n");
    printf ("====================================================\n");
}

void headerKeluar(){
        system ("clear");
        printf ("====================================================\n");
        printf ("+                                                  +\n");
        printf ("+                 TERIMA KASIH                     +\n");
        printf ("+                                                  +\n");
        printf ("====================================================\n");
}

void menu(){
    int pil_menu;
    header();
    printf ("+ Menu:                                            +\n");
    printf ("+ 1. Cek Kata                                      +\n");
    printf ("+ 2. Lihat Kamus Kata                              +\n");
    printf ("+ 3. Keluar                                        +\n");
    printf ("----------------------------------------------------\n");
    printf ("Masukan pilihan --> ");
    scanf ("%d", &pil_menu);
    switch (pil_menu)
    {
    case 1:
        system ("clear");
        cekKata();
        break;
    case 2:
        bukaFile();
        break;
    case 3:
        system ("clear");
        headerKeluar();
        break;
    default:
        fflush (stdin);
        printf ("====================================================\n");
        printf ("+               PILIHAN TIDAK TERSEDIA             +\n");
        printf ("====================================================\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        main();
        break;
    }
}

void cekKata(){
    fflush (stdin);
    char kata[25];
    int pnjg_string;
    int h;
    int indeks = 0;
    int l = 0;
    int status = 1;
    int jumlah_kemunculan[26] = {0};
    char x;

    header();
    printf ("Masukan kata --> ");
    do {
        scanf ("%c", &x);
        kata[indeks] = tolower(x);
        indeks++;
    } while (kata[indeks-1] != '\n');
    
    kata[indeks-1] = '\0';
    validString(kata, indeks);
    pnjg_string = strlen(kata);

    printf ("----------------------------------------------------\n");
    h = pnjg_string-1;

    while (l < h)
    {
        if (kata[l] != kata[h]) 
        {
            printf("%s bukan merupakan palindrome\n", kata);
            status = 0;
            break;
        } 
        l++;
        h--;
    }
    if (status == 1){
        printf("%s merupakan palindrome\n", kata);
    }
    printf("%s(%d) ", kata, pnjg_string);
    inputFile(kata,jumlah_kemunculan,status);
    printf ("\n----------------------------------------------------\n");

    ngulang();
}

void validString(char *kata, int indeks){
    int cek_huruf;
    for(int i = 0;i < indeks-1;i++){
        //untuk cek input huruf apakah sudah sesuai. 65 - 90 pada tabel ASCI = huruf kapital, 97 - 122 = huruf kecil
        if((kata[i] >= 65 && kata[i] <= 90) || (kata[i] >= 97 && kata[i] <= 122)){
           cek_huruf = 0;
           continue;
        }
        else{
            cek_huruf = 1;
            fflush(stdin);
            break;
        }
    }

    if (cek_huruf == 1){
        printf ("====================================================\n");
        printf ("=            INPUT HANYA BERUPA HURUF!!            =\n");
        printf ("====================================================\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        //validString(kata, indeks);
        fflush(stdin);
        system("clear");
        cekKata();
    } 
}

void inputFile(char *kata, char *jumlah_kemunculan, int *status){
    FILE *fptr;

    fptr = fopen("Kamuskata.txt","a");
    fprintf(fptr,"%s[%lu] >> ",kata, strlen(kata));
    
    //untuk print ke txt
    for(int c = 0; c < strlen(kata); c++){
        //untuk menambahkan tiap ada huruf yang muncul, dan akan tersimpan pada indeks yang sesuai dengan abjad.
        if (kata[c] >= 65 && kata[c] <= 90){
            jumlah_kemunculan[kata[c] - 65]++;
        } 
        else if (kata[c] >= 97 && kata[c] <= 122){
            jumlah_kemunculan[kata[c] - 97]++;
        }
    }

    for(int d = 0; d < 26; d++){
        if(jumlah_kemunculan[d] != 0) {
            printf("%c=%d ",d+65, jumlah_kemunculan[d]);
            fprintf(fptr,"%c = %d ",(d+65), jumlah_kemunculan[d]);
        }
    }

    if (status == 0){
        fprintf(fptr, "Bukan Palindrom");
    } else {
        fprintf(fptr, "Palindrom");
    }
    fprintf (fptr, "\n");
    fclose(fptr);
}

void bukaFile(){
    system ("clear");
    FILE *fptr;
    char isi[255];
    int pilihan; 
    char buff[25];
    fptr = fopen("Kamuskata.txt","r");
    header();
    printf("\nIsi dari file kamuskata:\n");
    if (fptr == NULL){
        printf("Error: File tidak ada!");
    }
    while(fgets(isi, sizeof(isi), fptr)){
        printf("%s", isi);
    }
    fclose(fptr);
    printf ("\n----------------------------------------------------\n");   
    ngulang();
}

void ngulang(){
    int ulang;
    printf ("+ 1. Kembali                                       +\n");
    printf ("+ 2. Keluar                                        +\n");
    printf ("----------------------------------------------------\n");
    printf ("Masukan pilihan --> ");
    scanf ("%d", &ulang);

    switch (ulang)
    {
    case 1:
        system ("clear");
        main();
    case 2:
        system ("clear");
        headerKeluar();
        exit(0);
    default:
        fflush(stdin);
        printf ("=================================================\n");
        printf ("+             PILIHAN TIDAK TERSEDIA            +\n");
        printf ("=================================================\n");
        printf ("Tekan enter untuk ulang --> ");
        getchar();
        ngulang();
        break;
    }
}
