/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n_pembeli;

    // Tampilkan interface
    printf("Ticketing System Eric Chou Concert\n");
    printf("Masukkan jumlah pembeli tiket: ");
    scanf("%d",&n_pembeli);

    char tiket_pembeli[n_pembeli][3];
    int kodeunik_pembeli[n_pembeli];

    for (int i=0; i<n_pembeli;i++){
        printf("Lokasi, grup, dan kode unik kursi ke-%d: ",i+1);
        scanf(" %c %c %d",&tiket_pembeli[i][0],&tiket_pembeli[i][1],&kodeunik_pembeli[i]);
    }

    // Balik kode unik
    int hasilbalik, sisabagi;
    for(int i=0; i<n_pembeli; i++){
        hasilbalik = 0;
        while(kodeunik_pembeli[i]!=0){
            sisabagi = kodeunik_pembeli[i] % 10;
            kodeunik_pembeli[i] = kodeunik_pembeli[i] / 10;
            hasilbalik = hasilbalik*10 + sisabagi;
        }
        // Perbarui nilai kode unik menjadi nilai yang telah dibalik
        kodeunik_pembeli[i] = hasilbalik;
    }

    // Konfigurasi Tempat Duduk
    int seat_left[18];
    int seat_mid[18];
    int seat_right[18];

    // Inisialisasi Nilai Awal
    for (int i = 0; i<18; i++){
        seat_left[i] = 0;
        seat_mid[i] = 0;
        seat_right[i] = 0;
    }
    
    // Pengisian Nilai Tempat Duduk Sesuai Prioritas
    // Diasumsikan kursi maksimal yang dipesan setiap grupnya maksimal 6 kursi
    int index;
    for(int i=0; i<n_pembeli; i++){
        // Kasus Lokasi Middle  
        if(tiket_pembeli[i][0]=='M'){
            // Kasus Lokasi Middle Grup A
            if(tiket_pembeli[i][1]=='A'){
                index = 0;
                while(seat_mid[index]!=0 && index<5){
                    index+=1;
                }
                seat_mid[index] = 1;
                tiket_pembeli[i][2] = index % 6;
            }
            // Kasus Lokasi Middle Grup B
            else if(tiket_pembeli[i][1]=='B'){
                index = 6;
                while(seat_mid[index]!=0 && index<11){
                    index+=1;
                }
                seat_mid[index] = 1;
                tiket_pembeli[i][2] = index % 6;
            }
            // Kasus Lokasi Middle Grup C
            else{
                index = 12;
                while(seat_mid[index]!=0 && index<17){
                    index+=1;
                }
                seat_mid[index] = 1;
                tiket_pembeli[i][2] = index % 6;
            }

        }

        // Kasus Lokasi Left
        else if(tiket_pembeli[i][0]=='L'){
            int prioritas_leftA[6] = {2,5,1,4,0,3};
            int prioritas_leftB[6] = {8,11,7,10,6,9};
            int prioritas_leftC[6] = {14,17,13,16,12,15};
            // Kasus Lokasi Left Grup A
            if(tiket_pembeli[i][1]=='A'){
                index = 0;
                while(seat_left[prioritas_leftA[index]]!=0 && index<5){
                    index+=1;
                }
                seat_left[prioritas_leftA[index]] = 1;
                tiket_pembeli[i][2] = prioritas_leftA[index] % 6;
            }
            // Kasus Lokasi Left Grup B
            else if(tiket_pembeli[i][1]=='B'){
                index = 0;
                while(seat_left[prioritas_leftB[index]]!=0 && index<5){
                    index+=1;
                }
                seat_left[prioritas_leftB[index]] = 1;
                tiket_pembeli[i][2] = prioritas_leftB[index] % 6;
            }
            // Kasus Lokasi Left Grup C
            else{
                index = 0;
                while(seat_left[prioritas_leftC[index]]!=0 && index<5){
                    index+=1;
                }
                seat_left[prioritas_leftC[index]] = 1;
                tiket_pembeli[i][2] = prioritas_leftC[index] % 6;
            }

        }
        // Kasus Lokasi Right
        else if(tiket_pembeli[i][0]=='R'){
            int prioritas_rightA[6] = {0,3,1,4,2,5};
            int prioritas_rightB[6] = {6,9,7,10,8,11};
            int prioritas_rightC[6] = {12,15,13,16,14,17};
            // Kasus Lokasi right Grup A
            if(tiket_pembeli[i][1]=='A'){
                index = 0;
                while(seat_right[prioritas_rightA[index]]!=0 && index<5){
                    index+=1;
                }
                seat_right[prioritas_rightA[index]] = 1;
                tiket_pembeli[i][2] = prioritas_rightA[index] % 6;
            }
            // Kasus Lokasi right Grup B
            else if(tiket_pembeli[i][1]=='B'){
                index = 0;
                while(seat_right[prioritas_rightB[index]]!=0 && index<5){
                    index+=1;
                }
                seat_right[prioritas_rightB[index]] = 1;
                tiket_pembeli[i][2] = prioritas_rightB[index] % 6;
            }
            // Kasus Lokasi right Grup C
            else{
                index = 0;
                while(seat_right[prioritas_rightC[index]]!=0 && index<5){
                    index+=1;
                }
                seat_right[prioritas_rightC[index]] = 1;
                tiket_pembeli[i][2] = prioritas_rightC[index] % 6;
            }

        }
    }

    // Tampilkan Konfigurasi tempat duduk
    printf("Konfigurasi akhir tempat duduk konser adalah:\n");
    for(int i=0;i<=15;i+=3){
        printf("%d %d %d ",seat_left[i],seat_left[i+1],seat_left[i+2]);
        printf("%d %d %d ",seat_mid[i],seat_mid[i+1],seat_mid[i+2]);
        printf("%d %d %d\n",seat_right[i],seat_right[i+1],seat_right[i+2]);
    }

    //  Tampilkan kode unik setiap nomor tiket
    printf("Kode unik untuk setiap tiket adalah:\n");
    int temp_lokasi, temp_grup;
    for(int i=0;i<n_pembeli;i++){
        printf("Tiket %d: ",i+1);
        // Ubah lokasi menjadi kode unik
        if(tiket_pembeli[i][0]=='L'){
            temp_lokasi = 1;
        }
        else if(tiket_pembeli[i][0]=='M'){
            temp_lokasi = 2;
        }
        // Lokasi Right
        else{
            temp_lokasi = 3;
        }

        // Ubah grup menjadi kode unik
        if(tiket_pembeli[i][1]=='A'){
            temp_grup = 4;
        }
        else if(tiket_pembeli[i][1]=='B'){
            temp_grup = 5;
        }
        // Grup C
        else{
            temp_grup = 6;
        }
        printf("%d%d%d%d\n",temp_lokasi,temp_grup,tiket_pembeli[i][2],kodeunik_pembeli[i]);
    }

    // // Debugging Program
    // for (int i=0;i<n_pembeli;i++){
    //     printf("Tiket %d Lokasi %c Grup %c Kode Rahasia %d\n",i+1,tiket_pembeli[i][0],tiket_pembeli[i][1],kodeunik_pembeli[i]);
    // }

    return 0;
}
