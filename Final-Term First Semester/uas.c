#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void loginpage();
int mainmenu();
void melihatData();
void inputDataPasien();
void inputHasilTest();
void laporan();

typedef struct data {
    char fullName[51];
    char namaLaboran[51];
    char alamat[51];
    char telp[21];
    char tanggalTest[27];
    char jamTest[7];
    char hasilTest[3];
    char IDLaboran[5];
} dataPasien;

void loginPage() { 
    system("cls");
    struct loginInfo {
        char username[51];
        char password[51];
    } login;

    puts("\t\t\tAplikasi Pendataan Rapid Tes Kelurahan ABC\n");
	puts("\tLOGIN");
	printf("%s", "\t\tUsername : "); fscanf(stdin, "%[^\n]", login.username); fgetc(stdin);
	printf("%s", "\t\tPassword : "); fscanf(stdin, "%[^\n]", login.password); fgetc(stdin);

    int flag1 = -1, flag2 = -1;
    if(strcmp(login.username, "Admin") == 0) {
        flag1 = 1;
    } else {
        flag1 = 0;
    }
    if(strcmp(login.password, "adm!n") == 0) {
        flag2 = 1;
    } else {
        flag2 = 0;
    }

    if((flag1 == 0) && (flag2 == 0)) {
        system("cls");
        puts("\n\n\tUsername dan password salah\n");
        puts("\tTekan tombol apapun untuk kembali ke halaman login");
        getch();
        loginPage();
    } else if((flag1 == 1) && (flag2 == 0)) {
        system("cls");
        puts("\n\n\tPassword salah\n");
        puts("\tTekan tombol apapun untuk kembali ke halaman login");
        getch();
        loginPage();
    } else if((flag1 == 0) && (flag2 == 1)) {
        system("cls");
        puts("\n\n\tUsername salah\n");
        puts("\tTekan tombol apapun untuk kembali ke halaman login");
        getch();
        loginPage();
    }
}

int mainmenu() {
    system("cls");
    //check system time
    time_t sec;
    time(&sec);
    struct tm *timeLocal;
    timeLocal = localtime(&sec);
    int sysTime = timeLocal -> tm_hour;

    if((sysTime > 3) && (sysTime < 12)) {
        puts("Selamat pagi,");
    } else if((sysTime > 11) && (sysTime < 18)) {
        puts("Selamat siang,");
    } else if((sysTime > 17) || ((sysTime > -1) && (sysTime < 4))) {
        puts("Selamat malam,");
    }

    puts("\t\t1. Melihat data");
    puts("\t\t2. Input data pasien");
    puts("\t\t3. Input hasil test");
    puts("\t\t4. Laporan");
    puts("\t\t0. Keluar");
    printf("\tPilihan Anda : ");

    char *userInput = (char*) malloc(21 * sizeof(userInput));
    scanf("%[^\n]", userInput); fflush(stdin);
    if(strcmp(userInput, "1") == 0) {
        free(userInput);
        return 1;
    } else if(strcmp(userInput, "2") == 0) {
        free(userInput);
        return 2;
    } else if(strcmp(userInput, "3") == 0) {
        free(userInput);
        return 3;
    } else if(strcmp(userInput, "4") == 0) {
        free(userInput);
        return 4;
    } else if(strcmp(userInput, "0") == 0) {
        free(userInput);
        return 0;
    } else {
        system("cls");
        puts("\n\n\tInput tidak valid");
        puts("\tInput harus berupa angka dari 0 - 4");
        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
        free(userInput);
        mainmenu();
    }
}

void melihatData() {
    system("cls");
    puts("Melihat Data");
    puts("\t\t1. Data orang yang masih menunggu hasil");
    puts("\t\t2. Data orang yang sudah melakukan test");
    puts("\t\t0. Kembali");
    printf("\tPilihan Anda : ");

    int choice;
    char *userInput = (char*) malloc(21 * sizeof(userInput));
    scanf("%[^\n]", userInput); fflush(stdin);
    if(strcmp(userInput, "1") == 0) {
        choice = 1;
    } else if(strcmp(userInput, "2") == 0) {
        choice = 2;
    } else if(strcmp(userInput, "0") == 0) {
        choice = 0;
    } else {
        system("cls");
        puts("\n\n\tInput tidak valid");
        puts("\tInput harus berupa angka dari 0 - 2");
        puts("\n\tTekan tombol apapun untuk kembali ke menu");
        getch();
        fflush(stdin);
        melihatData();
    }
    free(userInput);

    if(choice != 0) {
        dataPasien *pasien = (dataPasien*) malloc(sizeof(dataPasien));
        char *str = (char*) malloc(301 * sizeof(str));
        FILE *fp;

        system("cls");
        //cek apakah di file "data pasien.txt" ada isinya
        fp = fopen("data_files/data pasien.txt", "r");
        int p = fscanf(fp, "%s", str);
        fclose(fp);

        int ctd = 1;
        if(p != 1) {
            puts("Melihat Data");
            puts("\n\n\tTidak ada data yang tersimpan dalam sistem");
            puts("\n\tTekan tombol apapun untuk kembali ke menu");
            getch();
            fflush(stdin);
            melihatData();
        } else {
            if(choice == 1) {
                fp = fopen("data_files/data pasien.txt", "r");
                puts("Daftar Data yang Masih Menunggu Hasil\n");
                printf("   ====================================================\n\n");
                while((fscanf(fp, "%[^_]_%[^_]_%[^_]_%[^_]_%[^#]#%s\n", pasien->fullName, pasien->alamat, pasien->telp, pasien->tanggalTest, pasien->jamTest, str)) != EOF) {
                    if(strcmp(str, "-1_-1") == 0) {
                        printf("\t%d. Nama Lengkap    : %s\n", ctd, pasien->fullName);
                        printf("\t   Alamat          : %s\n", pasien->alamat);
                        printf("\t   No Telepon      : %s\n", pasien->telp);
                        printf("\t   Tanggal Test    : %s\n", pasien->tanggalTest);
                        printf("\t   Jam Test        : %s\n\n", pasien->jamTest);
                        printf("   ====================================================\n\n");
                        ctd += 1;
                    }
                }
                fclose(fp);
                free(pasien);
                free(str);
                puts("\n\tTekan tombol apapun untuk kembali ke menu");
                getch();
                fflush(stdin);
                melihatData();
            } else if(choice == 2) {
                fp = fopen("data_files/data pasien.txt", "r");
                puts("Daftar Data yang Sudah Melakukan Test\n");
                printf("   ====================================================\n\n");
                while((fscanf(fp, "%[^_]_%[^_]_%[^_]_%[^_]_%[^#]#%[^_]_%s\n", pasien->fullName, pasien->alamat, pasien->telp, pasien->tanggalTest, pasien->jamTest, pasien->hasilTest, pasien->IDLaboran)) != EOF) {
                    if(strcmp(pasien->hasilTest, "-1") != 0) {
                        printf("\t%d. Nama Lengkap    : %s\n", ctd, pasien->fullName);
                        printf("\t   Alamat          : %s\n", pasien->alamat);
                        printf("\t   No Telepon      : %s\n", pasien->telp);
                        printf("\t   Tanggal Test    : %s\n", pasien->tanggalTest);
                        printf("\t   Jam Test        : %s\n", pasien->jamTest);
                        if(strcmp(pasien->hasilTest, "1") == 0 ) {
                            strcpy(str, "Positif");
                        } else if(strcmp(pasien->hasilTest, "0") == 0) {
                            strcpy(str, "Negatif");
                        }
                        printf("\t   Hasil Test      : %s\n", str);
                        printf("\t   ID Laboran      : %s\n\n", pasien->IDLaboran);
                        printf("   ====================================================\n\n");
                        ctd += 1;
                    }
                }
                fclose(fp);
                free(pasien);
                free(str);
                puts("\n\tTekan tombol apapun untuk kembali ke menu");
                getch();
                fflush(stdin);
                melihatData();
            }
        }
    }
}

void inputDataPasien() {
    system("cls");

    dataPasien *pasien = (dataPasien*) malloc(sizeof(dataPasien));
    char *str = (char*) malloc (301 * sizeof(str));
    puts("Input Data Pasien");
    printf("\t\tNama Lengkap    : "); fscanf(stdin, "%[^\n]", pasien->fullName); fgetc(stdin); strcpy(str, pasien->fullName); strcat(str, "_");
    printf("\t\tAlamat          : "); fscanf(stdin, "%[^\n]", pasien->alamat); fgetc(stdin); strcat(str, pasien->alamat); strcat(str, "_");
    printf("\t\tNo Telepon      : "); fscanf(stdin, "%[^\n]", pasien->telp); fgetc(stdin); strcat(str, pasien->telp); strcat(str, "_");
    printf("\t\tTanggal Test    : "); fscanf(stdin, "%[^\n]", pasien->tanggalTest); fgetc(stdin); strcat(str, pasien->tanggalTest); strcat(str, "_");
    printf("\t\tJam Test        : "); fscanf(stdin, "%[^\n]", pasien->jamTest); fgetc(stdin); strcat(str, pasien->jamTest);
    free(pasien);

    printf("\tSimpan data? (Y/N) : ");
    char *simpan = (char*) malloc (2 * sizeof(simpan));
    scanf("%[^\n]", simpan); fflush(stdin);
    if((strcmp(simpan, "N") == 0) || (strcmp(simpan, "n") == 0)) {
        puts("\n\tData dihapus dan tidak disimpan");
        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
    } else if((strcmp(simpan, "Y") == 0) || (strcmp(simpan, "y") == 0)) {
        FILE *fp;

        //cek apakah di file "data pasien.txt" ada isinya
        char *temp = (char*) malloc (301 * sizeof(temp));
        fp = fopen("data_files/data pasien.txt", "r");
        int p = fscanf(fp, "%s", temp);
        fclose(fp);

        //menulis dalam file "data pasien.txt"   
        if(p != 1) {
            fp = fopen("data_files/data pasien.txt", "w");
            fprintf(fp, "%s#-1_-1\n", str);
            fclose(fp);
        } else {
            fp = fopen("data_files/data pasien.txt", "a");
            fprintf(fp, "%s#-1_-1\n", str);
            fclose(fp);
        }
        free(temp);

        puts("\n\tData berhasil disimpan");
        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
    } else {
        system("cls");
        puts("\n\n\tInput tidak valid");
        puts("\tInput harus berupa huruf Y untuk yes dan huruf N untuk no");
        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
    }

    free(str);
    free(simpan);
}

void inputHasilTest() {
    system("cls");

    dataPasien *pasien = (dataPasien*) malloc(sizeof(dataPasien));
    char *str = (char*) malloc(16 * sizeof(str));
    char *str2 = (char*) malloc(51 * sizeof(str2));
    char *namaPasien = (char*) malloc(51 * sizeof(namaPasien));
    puts("Input Hasil Test");
    printf("\t\tNama Pasien  : "); fscanf(stdin, "%[^\n]", namaPasien); fgetc(stdin);
    printf("\t\tNama Laboran : "); fscanf(stdin, "%[^\n]", pasien->namaLaboran); fgetc(stdin); strcpy(str2, pasien->namaLaboran);
    printf("\t\tHasil Test   : "); fscanf(stdin, "%[^\n]", pasien->hasilTest); fgetc(stdin); strcpy(str, pasien->hasilTest);
    
    int flag = 1;
    if(strcmp(str, "Positif") == 0) {
        strcpy(str, "1");
    } else if(strcmp(str, "Negatif") == 0) {
        strcpy(str, "0");
    } else {
        flag = 0;
    }

    strcat(str, "_");

    int len = strlen(str2);
    char *resultstr = (char*) malloc(51 * sizeof(resultstr));
    memset(resultstr, '\0', sizeof(resultstr));
    resultstr[0] = str2[0];
    for(int j = 1, i = 0; i < len; i++) {
        if(str2[i] == ' ') {
            resultstr[j] = str2[i + 1];
            j++;
        }
    }
    strcpy(pasien->IDLaboran, resultstr);
    free(resultstr);

    strcat(str, pasien->IDLaboran);

    printf("\tSimpan data? (Y/N) : ");
    char *simpan = (char*) malloc (2 * sizeof(simpan));
    scanf("%[^\n]", simpan); fflush(stdin);

    int find = 0;
    if(flag == 1) {
        if((strcmp(simpan, "N") == 0) || (strcmp(simpan, "n") == 0)) {
            puts("\n\tData dihapus dan tidak disimpan");
            puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
            getch();
            fflush(stdin);
        } else if((strcmp(simpan, "Y") == 0) || (strcmp(simpan, "y") == 0)) {
            FILE *fp;
            FILE *fp2;
            FILE *fptemp;

            //cek apakah di file .txt ada isinya
            char *temp = (char*) malloc (301 * sizeof(temp));
            char *temp2 = (char*) malloc (301 * sizeof(temp2));
            char *temp3 = (char*) malloc (301 * sizeof(temp3));
            fp = fopen("data_files/data pasien.txt", "r");
            int p = fscanf(fp, "%s", temp);
            fclose(fp);

            //simpan dalam file .txt   
            if(p != 1) {
                puts("\n\tNama pasien tidak ditemukan dalam sistem");
                puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
                getch();
                fflush(stdin);
            } else {
                fp = fopen("data_files/data pasien.txt", "r");
                fptemp = fopen("data_files/temp.txt", "w");

                //menulis ke file baru bernama "temp.txt"
                //linear search per baris
                while((fscanf(fp, "%[^_]_%[^#]#%s\n", temp, temp2, temp3)) != EOF) {
                    if(strcmp(temp, namaPasien) == 0) {
                        fprintf(fptemp, "%s_%s#%s\n", temp, temp2, str);
                        find = 1;
                    } else {
                        fprintf(fptemp, "%s_%s#%s\n", temp, temp2, temp3);
                        if(find != 1) {
                            find = 0;
                        }
                    }
                }
                
                fclose(fp);
                fclose(fptemp);

                //menghapus file "data pasien.txt" lalu mengganti nama file "temp.txt" menjadi "data pasien.txt"
                remove("data_files/data pasien.txt");
                rename("data_files/temp.txt", "data_files/data pasien.txt");

                fp2 = fopen("data_files/data laboran.txt", "r");
                int q = fscanf(fp2, "%s", temp); fflush(stdin);
                fclose(fp2);

                if(q != 1) {
                    //menulis dalam file "data laboran.txt"   
                    fp2 = fopen("data_files/data laboran.txt", "w");
                    fprintf(fp2, "%s-%s-%s\n", pasien->namaLaboran, pasien->IDLaboran, "1");
                    fclose(fp2);
                } else {
                    int ctd;
                    fp2 = fopen("data_files/data laboran.txt", "r");
                    fptemp = fopen("data_files/temp.txt", "w");

                    //menulis ke file baru bernama "temp.txt"
                    //linear search per baris
                    int flag;
                    while((fscanf(fp2, "%[^-]-%[^-]-%s\n", str2, temp, temp2)) != EOF) {
                        if(strcmp(str2, pasien->namaLaboran) == 0) {
                            ctd = atoi(temp2);
                            ctd += 1;
                            itoa(ctd, temp3, 10);
                            fprintf(fptemp, "%s-%s-%s\n", str2, temp, temp3);
                            flag = 1;
                        } else {
                            fprintf(fptemp, "%s-%s-%s\n", str2, temp, temp2);
                            if(flag != 1) {
                                flag = 0;
                            }
                        }
                    }
                    fclose(fptemp);
                    if(flag == 0) {
                        fptemp = fopen("data_files/temp.txt", "a");
                        fprintf(fptemp, "%s-%s-%s\n", pasien->namaLaboran, pasien->IDLaboran, "1");
                        fclose(fptemp);
                    }
                    
                    fclose(fp2);
                    free(pasien);

                    //menghapus file "data laboran.txt" lalu mengganti nama file "temp.txt" menjadi "data laboran.txt"
                    remove("data_files/data laboran.txt");
                    rename("data_files/temp.txt", "data_files/data laboran.txt");
                }
            }
            free(temp);
            free(temp2);
            free(temp3);
            free(str);
            free(str2);
            free(simpan);

            if(find == 0) {
                puts("\n\tNama pasien tidak ditemukan dalam sistem");
                puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
                getch();
                fflush(stdin);
            } else {
                puts("\n\tData berhasil disimpan");
                puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
                getch();
                fflush(stdin);
            }
        } else {
            system("cls");
            puts("\n\n\tInput tidak valid");
            puts("\tInput harus berupa huruf Y untuk yes dan huruf N untuk no");
            puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
            getch();
            fflush(stdin);
        }
    } else {
        system("cls");
        puts("\n\n\tInput tidak valid");
        puts("\tInput Hasil Test harus berupa \"Positif\" atau \"Negatif\"");
        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
    }
}

void laporan() {
    system("cls");

    FILE *fp;
    fp = fopen("data_files/data pasien.txt", "r");
    char *str = (char*) malloc(301 * sizeof(str));
    int p = fscanf(fp, "%s", str);
    fclose(fp);

    int totaltest = 0;
    int totaltungguTest = 0;
    int totalselesaiTest = 0;
    int totalpositif = 0;
    int totalnegatif = 0;

    if(p != 1) {
        puts("Laporan");
        puts("\n\n\tTidak ada data yang tersimpan dalam sistem");
        puts("\n\tTekan tombol apapun untuk kembali ke menu");
        getch();
        fflush(stdin);
    } else {
        dataPasien *pasien = (dataPasien*) malloc(sizeof(dataPasien));
        fp = fopen("data_files/data pasien.txt", "r");
        while((fscanf(fp, "%[^#]#%[^_]_%s\n", str, pasien->hasilTest, pasien->IDLaboran)) != EOF) {
            totaltest += 1;
            if(strcmp(pasien->hasilTest, "-1") == 0) {
                totaltungguTest += 1;
            } else if(strcmp(pasien->hasilTest, "1") == 0) {
                totalselesaiTest += 1;
                totalpositif += 1;
            } else if(strcmp(pasien->hasilTest, "0") == 0) {
                totalselesaiTest += 1;
                totalnegatif += 1;
            }
        }
    }

    fclose(fp);
    free(str);

    struct data {
        char nama[51];
        char id[11];
        int jumlah;  
    } laboran[150];

    int n = 0;

    FILE *fp2;
    fp2 = fopen("data_files/data laboran.txt", "r");
    while(fscanf(fp2, "%[^-]-%[^-]-%d\n", laboran[n].nama, laboran[n].id, &laboran[n].jumlah) != EOF) {
        n++;
    }
    fclose(fp2);

    //sorting number
    for(int j = 0; j < n - 1; j++) {
        for(int k = 0; k < n - j- 1; k++) {
            if(laboran[k].jumlah < laboran[k + 1].jumlah) {
                char temp[11] = {};
                int temp2 = 0;
        
                strcpy(temp, laboran[k].id);
                strcpy(laboran[k].id, laboran[k + 1].id);
                strcpy(laboran[k + 1].id, temp);

                strcpy(temp, laboran[k].nama);
                strcpy(laboran[k].nama, laboran[k + 1].nama);
                strcpy(laboran[k + 1].nama, temp);

                temp2 = laboran[k].jumlah;
                laboran[k].jumlah = laboran[k + 1].jumlah;
                laboran[k + 1].jumlah = temp2;
            }
        }
    }
    //sorting name if number is same
    for(int j = 1; j < n; j++) {
        for(int k = 1; k < n; k++) {
            if(laboran[k-1].jumlah == laboran[k].jumlah) {
                char temp[51] = {};
                if(strcmp(laboran[k-1].id, laboran[k].id) > 0) {
                    strcpy(temp, laboran[k-1].id);
                    strcpy(laboran[k-1].id, laboran[k].id);
                    strcpy(laboran[k].id, temp);

                    strcpy(temp, laboran[k-1].nama);
                    strcpy(laboran[k-1].nama, laboran[k].nama);
                    strcpy(laboran[k].nama, temp);
                }
            }	
        }
    }

    if(p == 1) {
        FILE *fptemp;
        fptemp = fopen("data_files/temp.txt", "w");
        fprintf(fptemp,"%s-%s-%d\n", laboran[0].nama, laboran[0].id, laboran[0].jumlah);
        fclose(fptemp);
        fptemp = fopen("data_files/temp.txt", "a");
        for(int j = 1; j < n; j++) {
            fprintf(fptemp,"%s-%s-%d\n", laboran[j].nama, laboran[j].id, laboran[j].jumlah);
        }
        fclose(fptemp);

        remove("data_files/data laboran.txt");
        rename("data_files/temp.txt", "data_files/data laboran.txt");

        puts("Laporan");
        printf("\tJumlah orang yang melakukan test                              : %d orang\n\n", totaltest);
        printf("\tJumlah orang yang masih menunggu hasil test                   : %d orang\n\n", totaltungguTest);
        printf("\tJumlah orang yang telah mendapatkan hasil test                : %d orang\n\n", totalselesaiTest);
        printf("\tJumlah hasil test positif                                     : %d orang\n\n", totalpositif);
        printf("\tJumlah hasil test negatif                                     : %d orang\n\n", totalnegatif);

        printf("\tJumlah test yang telah dilakukan oleh masing - masing laboran : \n");
        fp2 = fopen("data_files/data laboran.txt", "r");
        printf("\t\tID Laboran // Nama Laboran // Jumlah Test\n");
        printf("\t     ==============================================\n");
        while(fscanf(fp2, "%[^-]-%[^-]-%d\n", laboran[0].nama, laboran[0].id, &laboran[0].jumlah) != EOF) {
            printf("\t\t%s // %s // %d orang\n", laboran[0].nama, laboran[0].id, laboran[0].jumlah);
        }
        printf("\t     ==============================================\n");
        fclose(fp2);

        puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
        getch();
        fflush(stdin);
    }
}

int main() {
    //login
    loginPage();

    //main menu
    menu : {
		int menuInput = mainmenu();
        switch(menuInput) {
            case 1 :
                melihatData();
                fflush(stdin);
                goto menu;
                break;
            case 2 :
                inputDataPasien();
                fflush(stdin);
                goto menu;
                break;
            case 3 :
                inputHasilTest();
                fflush(stdin);
                goto menu;
                break;
            case 4 :
                laporan();
                fflush(stdin);
                goto menu;
                break;
            case 0 :
                system("cls");
                exit(1);
                break;
            default :
                puts("\n\n\tInput tidak valid");
                puts("\tInput harus berupa angka dari 0 - 4");
                puts("\n\tTekan tombol apapun untuk kembali ke menu utama");
                getch();
                fflush(stdin);
                goto menu;
                break;
        }
	}
    
    return 0;
}
