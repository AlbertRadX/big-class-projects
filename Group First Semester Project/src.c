#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include "ext_func/tabel.c"
#include "ext_func/windowCust.c"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

void mainmenu();
void beforeSignIn();
void signinPage();
void signupPage();
void invalidInput();
void keluarProgram();
void masuk();
void list();
void dataPenjualan();
void cariBarangFull();
void cariBarangNama();
void cariBarangMenu();

void setColor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void invalidInput() { 
	system("cls"); // 39 biji
	setColor(4);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("          %c  Input yang diterima tidak valid!   %c\n",186,186);
	printf("          %c Tekan tombol apapun untuk coba lagi %c\n",186,186);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	getch();
	setColor(7);
}

void beforeSignIn() { 
	system("cls");
	system("color E");
	puts("\n            "UNDERLINE"Aplikasi Data Penjualan PT.Geoculus"CLOSEUNDERLINE"\n");//39 biji jg
	setColor(6);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("          %c                                     %c",186,186);
	printf("\n          %c             1. Sign in              %c",186,186);
	printf("\n          %c             2. Sign up              %c",186,186);
	printf("\n          %c             3. Keluar               %c\n",186,186);
	printf("          %c                                     %c",186,186);
	printf("\n\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			signinPage();
			break;
		case 50 :
			signupPage();
			signinPage();
			break;
		case 51 :
			system("cls");
			exit(0);
			break;
		default :
			invalidInput();
			beforeSignIn();
			break;
	}
	setColor(7);
}

void signupPage() { 
	char *str, *buf;
	str = (char*) malloc(301*sizeof(str));
	buf = (char*) malloc(301*sizeof(buf));
	
	system("cls");
	puts("         SIGN UP----");
	puts("         ----Please enter your credentials\n");
	puts("\t=======================================\n");
	printf("%s", "\t     Full Name : "); fscanf(stdin, "%[^\n]", buf); fgetc(stdin); strcpy(str, buf); strcat(str, "-");
	printf("%s", "\t     ID : "); fscanf(stdin, "%[^\n]", buf); fgetc(stdin); strcat(str, buf); strcat(str, "-");
	printf("%s", "\t     Password : "); fscanf(stdin, "%[^\n]", buf); fgetc(stdin); strcat(str, buf);
	
	//write in file login.in
	FILE *fp;
	fp = fopen("data_files/login.in", "r");
	int i = fscanf(fp, "%s", buf);
	fclose(fp);
	if(i != 1) {
		fp = fopen("data_files/login.in", "w");
		fprintf(fp, "%s\n", str);
		fclose(fp);
	} else {
		fp = fopen("data_files/login.in", "a");
		fprintf(fp, "%s\n", str);
		fclose(fp);
	}
	
	free(str);
	free(buf);
}

void signinPage() { 
	char *name, *id, *pass, *str1, *str2;
	name = (char*) malloc(301*sizeof(name));
	id = (char*) malloc(301*sizeof(id));
	pass = (char*) malloc(301*sizeof(pass));
	str1 = (char*) malloc(301*sizeof(str1));
	str2 = (char*) malloc(301*sizeof(str2));

	int flag = 0;
	
	system("cls");
	system("color E");
	puts("    	 SIGN IN----");
	puts("         ----Please enter your credentials\n");
	puts("\t=======================================\n");
	printf("%s", "\t     ID : "); fscanf(stdin, "%[^\n]", str1); fgetc(stdin);
	printf("%s", "\t     Password : "); fscanf(stdin, "%[^\n]", str2); fgetc(stdin);

	FILE *fp;
	fp = fopen("data_files/login.in", "r");
	while(!feof(fp)) {
		fscanf(fp, "%[^-]-%[^-]-%[^\n]\n", name, id, pass);
		if(strcmp(str1, id) == 0) {
			if(strcmp(str2, pass) == 0) {
				flag = 1;
				break;
			}
		}
	}
	fclose(fp);
	
	free(name);
	free(id);
	free(pass);
	free(str1);
	free(str2);
	
	if(flag == 0) {
		system("cls");
		puts("\t=======================================\n");
		puts("\t     Akun tidak terdaftar!");
		puts("\t     Tekan tombol apapun untuk kembali");
		puts("\n\t=======================================");
		getch();
		beforeSignIn();
	} else {
		mainmenu();
	}
}

void mainmenu() {
	system("cls");
	setColor(6);
	puts("\n              "UNDERLINE"Aplikasi Data Penjualan PT.Geoculus"CLOSEUNDERLINE"\n");
	setColor(2);
	puts("                Pilih menu dengan menekan angka\n");
	setColor(6);
	printf("\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("            %c                                     %c",186,186);
		printf("\n\t    %c        1. Pemasukkan Kendaraan      %c\n",186,186);
		printf("\t    %c        2. Penarikkan Kendaraan      %c\n",186,186);
		printf("\t    %c        3. Stok Kendaraan            %c\n",186,186);
		printf("\t    %c        4. Cari Kendaraan            %c\n",186,186);
		printf("\t    %c        5. Logout                    %c\n",186,186);
		printf("\t    %c        6. Tutup Program             %c\n",186,186);
		printf("            %c                                     %c",186,186);
	printf("\n\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			masuk();
			break;
		case 50 :
			dataPenjualan();
			break;
		case 51 :
			list();
			break;
		case 52 :
			cariBarangMenu();
			break;
		case 53 :
			beforeSignIn();
			break;
		case 54 :
			keluarProgram();
			break;
		default :
			invalidInput();
			mainmenu();
			break;
	}
}

int jenisb()
{
	setColor(2);
	puts("                       Pilih Jenis Kendaraan\n");
	setColor(6);
	printf("\t          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("                  %c                          %c",186,186);
	printf("\n\t          %c        1. Motor          %c\n",186,186);
	printf("\t          %c        2. Mobil          %c\n",186,186);
	printf("\t          %c        3. Bus            %c\n",186,186);
	printf("\t          %c        4. Kembali        %c\n",186,186);
	printf("                  %c                          %c",186,186);
	printf("\n\t          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			system("cls");
			return 0;
			break;
		case 50 :
			system("cls");
			return 1;
			break;
		case 51 :
			system("cls");
			return 2;
			break;
		case 52 :
			mainmenu();
			break;
		default :
			invalidInput();
			system("cls");
			jenisb();
			break;
	}
}

void masuk()
{
	int jumlah,x;
	FILE *fp;
	FILE *fptemp;
	fp = fopen("data_files/data penjualan.in","r");
	
	char *nama, *merk, *model, *str1, *str2, *temp;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	str1 = (char*)malloc(50*sizeof(str1));
	str2 = (char*)malloc(150*sizeof(str2));
	temp = (char*)malloc(150*sizeof(temp));
	
	char jenis[5][10]={{"Motor"},{"Mobil"},{"Bus"}};
	int jumTemp;
	
	system("cls");
	x=jenisb();
	system("color E");
	printf("    	     Jenis Kendaraan : %s\n",jenis[x]); strcpy(str1, jenis[x]); strcat(str1, "-");
	puts("\t=======================================\n");
	printf("\t        Nama Kendaraan : ");
	scanf("%s",nama); fgetc(stdin); strcat(str1, nama); strcat(str1, "-");
	printf("\t        Merk Kendaraan : ");
	scanf("%s",merk); fgetc(stdin); strcat(str1, merk); strcat(str1, "-");
	printf("\t        Model Kendaraan : ");
	scanf("%s",model); fgetc(stdin); strcat(str1, model);
	printf("\t        Jumlah Kendaraan : ");
	scanf("%d",&jumlah);
	
	int calc, flag = -1;
	
	int p = fscanf(fp,"%s",temp);
	fclose(fp);

	if(p!=1)
	{
		fp = fopen("data_files/data penjualan.in","w");
		fprintf(fp,"%s-%s-%s-%s#%d\n",jenis[x],nama,merk,model,jumlah);
		fclose(fp);
	}
	else
	{
		fp = fopen("data_files/data penjualan.in","r");
		fptemp = fopen("data_files/temp.in", "w");
		
		while((fscanf(fp, "%[^#]#%d\n", str2, &jumTemp)) != EOF) {
		if(strcmp(str2, str1) == 0) {
				calc = jumTemp + jumlah;
				fprintf(fptemp, "%s#%d\n", str1, calc);
				flag = 0;
			} else {
				fprintf(fptemp, "%s#%d\n", str2, jumTemp);
				if(flag != 0) {
					flag = 1;
				}
			}
		}
		
		fclose(fp);
		fclose(fptemp);
		
		remove("data_files/data penjualan.in");
		rename("data_files/temp.in", "data_files/data penjualan.in");
		
		if(flag == 1) {
			fp = fopen("data_files/data penjualan.in","a");
			fprintf(fp,"%s-%s-%s-%s#%d\n",jenis[x],nama,merk,model,jumlah);
			fclose(fp);
		}
	}
	printf("\nData berhasil disimpan\nPress any button to continue . . .\n");
	getch();
	
	free(nama);
	free(merk);
	free(model);
	free(str1);
	free(str2);
	free(temp);
	
	mainmenu();
}

void dataPenjualan(){
	int jumlah,x;
	FILE *fp;
	FILE *fptemp;
	fptemp = fopen("data_files/temp.in", "w");
	fp = fopen("data_files/data penjualan.in","r");
	
	char *nama, *merk, *model, *str1, *str2;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	str1 = (char*)malloc(50*sizeof(str1));
	str2 = (char*)malloc(150*sizeof(str2));
	
	char jenis[5][10]={{"Motor"},{"Mobil"},{"Bus"}};
	int jumTemp;
	
	system("cls");
	x=jenisb();
	system("color E");
	printf("    	     Jenis Kendaraan : %s\n",jenis[x]); strcpy(str1, jenis[x]); strcat(str1, "-");
	puts("\t=======================================\n");
	printf("\t        Nama Kendaraan : ");
	scanf("%s",nama); fgetc(stdin); strcat(str1, nama); strcat(str1, "-");
	printf("\t        Merk Kendaraan : ");
	scanf("%s",merk); fgetc(stdin); strcat(str1, merk); strcat(str1, "-");
	printf("\t        Model Kendaraan : ");
	scanf("%s",model); fgetc(stdin); strcat(str1, model);
	printf("\t        Jumlah Kendaraan : ");
	scanf("%d",&jumlah);
	
	int calc, flag = -1;
	
	while((fscanf(fp, "%[^#]#%d\n", str2, &jumTemp)) != EOF) {
		calc = 1;
		if(strcmp(str2, str1) == 0) {
			calc = jumTemp - jumlah;
			if(calc < 0) {
				fprintf(fptemp, "%s#%d\n", str2, jumTemp);
				printf("%s\n%s", "Jumlah barang yang ditarik melebihi jumlah stok yang terdaftar", "Press any key to continue . . .");
			} else if(calc == 0) {
				printf("\nData berhasil disimpan\nPress any key to continue . . .\n");
			} else {
				fprintf(fptemp, "%s#%d\n", str1, calc);
				printf("\nData berhasil disimpan\nPress any key to continue . . .\n");
			}
			flag = 0;
		} else {
			fprintf(fptemp, "%s#%d\n", str2, jumTemp);
			if(flag != 0) {
				flag = 1;
			}
		}
	}
	
	fclose(fp);
	fclose(fptemp);
	
	remove("data_files/data penjualan.in");
	rename("data_files/temp.in", "data_files/data penjualan.in");

	if(flag == 1) {
		printf("%s\n%s", "Item tidak terdaftar dalam stok barang", "Press any key to continue . . .");
	}
	
	free(nama);
	free(merk);
	free(model);
	free(str1);
	free(str2);
	
	getch();

	mainmenu();
}

void sortingNama()
{
	struct P
	{
		char jenis[10];
		char nama[50];
		char merk[50];
		char model[50];
		int jumlah;
	}data[150];
	
	int i=0;
	FILE *fptemp;
	FILE *fp = fopen("data_files/data penjualan.in","r");
	while(fscanf(fp,"%[^-]-%[^-]-%[^-]-%[^#]#%d\n",data[i].jenis,data[i].nama,data[i].merk,data[i].model,&data[i].jumlah) != EOF)
	{
		i++;
	}
	fclose(fp);

	for(int k=0;k<i-1;k++)
	{
		for(int j=0;j<i-k-1;j++)
		{
			if(strcmp(data[j].nama,data[j+1].nama)>0)
			{
				char temp[50];
				int temp2;
				
				strcpy(temp,data[j].nama);
				strcpy(data[j].nama,data[j+1].nama);
				strcpy(data[j+1].nama,temp);
				
				strcpy(temp,data[j].jenis);
				strcpy(data[j].jenis,data[j+1].jenis);
				strcpy(data[j+1].jenis,temp);
				
				strcpy(temp,data[j].merk);
				strcpy(data[j].merk,data[j+1].merk);
				strcpy(data[j+1].merk,temp);
				
				strcpy(temp,data[j].model);
				strcpy(data[j].model,data[j+1].model);
				strcpy(data[j+1].model,temp);
				
				temp2=data[j].jumlah;
				data[j].jumlah=data[j+1].jumlah;
				data[j+1].jumlah=temp2;
			}
		}
	}
	
	fptemp = fopen("data_files/temp.in", "w");
	fprintf(fptemp,"%s-%s-%s-%s#%d\n",data[0].jenis,data[0].nama,data[0].merk,data[0].model,data[0].jumlah);
	fclose(fptemp);
	fptemp = fopen("data_files/temp.in", "a");
	for(int j = 1; j < i-1; j++) {
		fprintf(fptemp,"%s-%s-%s-%s#%d\n",data[j].jenis,data[j].nama,data[j].merk,data[j].model,data[j].jumlah);
	}
	fprintf(fptemp,"%s-%s-%s-%s#%d",data[i-1].jenis,data[i-1].nama,data[i-1].merk,data[i-1].model,data[i-1].jumlah);
	fclose(fptemp);
		
	remove("data_files/data penjualan.in");
	rename("data_files/temp.in", "data_files/data penjualan.in");
} 

void sortingJumlah()
{
	struct P
	{
		char jenis[10];
		char nama[50];
		char merk[50];
		char model[50];
		int jumlah;
	}data[150];
	
	int i=0;
	FILE *fptemp;
	FILE *fp = fopen("data_files/data penjualan.in","r");
	while(fscanf(fp,"%[^-]-%[^-]-%[^-]-%[^#]#%d\n",data[i].jenis,data[i].nama,data[i].merk,data[i].model,&data[i].jumlah) != EOF)
	{
		i++;
	}
	fclose(fp);

	for(int k=0;k<i-1;k++)
	{
		for(int j=0;j<i-k-1;j++)
		{	
			if(data[j].jumlah>data[j+1].jumlah)
			{

				char temp[50];
				int temp2;
				
				strcpy(temp,data[j].nama);
				strcpy(data[j].nama,data[j+1].nama);
				strcpy(data[j+1].nama,temp);
				
				strcpy(temp,data[j].jenis);
				strcpy(data[j].jenis,data[j+1].jenis);
				strcpy(data[j+1].jenis,temp);
				
				strcpy(temp,data[j].merk);
				strcpy(data[j].merk,data[j+1].merk);
				strcpy(data[j+1].merk,temp);
				
				temp2=data[j].jumlah;
				data[j].jumlah=data[j+1].jumlah;
				data[j+1].jumlah=temp2;
			}
		}	
	}
	
	fptemp = fopen("data_files/temp.in", "w");
	fprintf(fptemp,"%s-%s-%s-%s#%d\n",data[0].jenis,data[0].nama,data[0].merk,data[0].model,data[0].jumlah);
	fclose(fptemp);
	fptemp = fopen("data_files/temp.in", "a");
	for(int j = 1; j < i-1; j++) {
		fprintf(fptemp,"%s-%s-%s-%s#%d\n",data[j].jenis,data[j].nama,data[j].merk,data[j].model,data[j].jumlah);
	}
	fprintf(fptemp,"%s-%s-%s-%s#%d",data[i-1].jenis,data[i-1].nama,data[i-1].merk,data[i-1].model,data[i-1].jumlah);
	fclose(fptemp);
		
	remove("data_files/data penjualan.in");
	rename("data_files/temp.in", "data_files/data penjualan.in");
}

void sortingBarang()
{
	printf("Pilih jenis sorting!\n");
	printf("1. Sorting sesuai nama\n");
	printf("2. Sorting sesuai jumlah\n");
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			system("cls");
			sortingNama();
			printf("\nSorting berhasil!\n\nPress any key to continue...");
			getch();
			break;
		case 50 :
            system("cls");
            sortingJumlah();
            printf("\nSorting berhasil!\n\nPress any key to continue...");
            getch();
            break;
		default :
			invalidInput();
			system("cls");
			mainmenu();
			break;
	}
}
void list()
{
	system("cls");
	
	setColor(6);
	FILE *fp;
	
	char *jenis, *nama, *merk, *model, *jumlah, *buf;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	jenis = (char*)malloc(10*sizeof(jenis));
	jumlah = (char*)malloc(10*sizeof(jumlah));
	
	fp = fopen("data_files/data penjualan.in","r");
	
		//PLACEHOLDER (CAN BE CHANGED)
		//urutan item belum dibikin, kodingan ini cuman buat tabelnya tanpa diurutin...
		//urutan item ngikutin urutan di file "data penjualan.in"
	//top
	printf("%c", 201);
	horizontal();
	printf("\n");
	printf("%c%-5s%c%-15s%c%-16s%c%-16s%c%-6s%c\n", 186, "Jenis", 186, "Nama", 186, "Merk", 186, "Model", 186, "Jumlah", 186);
	
	int flag = 0;
	//middle
	buf = (char*) malloc(10*sizeof(buf));
	if(fscanf(fp, "%s\n", buf) == EOF) {
		horizontalbetween2();
		printf("%c\t\t    %-43s%c", 186, "Tidak ada daftar barang", 186);
		printf("\n");
		flag = 1;
	}
	rewind(fp);
	while(fscanf(fp, "%[^-]-%[^-]-%[^-]-%[^#]#%s\n", jenis, nama, merk, model, jumlah) != EOF) {
		if(strcmp(jenis, "\n") == 0) {
			horizontalbetween2();
			printf("%c\t\t    %-43s%c", 186, "Tidak ada daftar barang", 186);
			printf("\n");
			flag = 1;
			break;
		} else {
			horizontalbetween();
			printf("%c%-5s%c%-15s%c%-16s%c%-16s%c%-6s%c", 186, jenis, 186, nama, 186, merk, 186, model, 186, jumlah, 186);
			printf("\n");
		}
	}
	
	//bottom
	if(flag == 0) {
		horizontalend();
	} else {
		horizontalend2();
	}
		//PLACEHOLDER (CAN BE CHANGED)
		
	fclose(fp);
	
	printf("\n\nMenu:\n");
	printf("%c%c%c%c%c%c\n",196,196,196,196,196,196);
	printf("1. Sorting\n");
	printf("2. Kembali\n");
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			system("cls");
			sortingBarang();
			break;
		case 50 :
			system("cls");
			mainmenu();
			break;
		default :
			invalidInput();
			system("cls");
			list();
			break;
		}
	

	
	free(buf);
	free(nama);
	free(jenis);
	free(merk);
	free(model);
	free(jumlah);
	
	mainmenu();
}

void cariBarangNama() {
	FILE *fp;
	fp = fopen("data_files/data penjualan.in","r");
	
	char *nama, *merk, *model, *str1, *str2, *temp1, *temp2, *temp3;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	str1 = (char*)malloc(50*sizeof(str1));
	str2 = (char*)malloc(50*sizeof(str2));
	temp1 = (char*)malloc(50*sizeof(temp1));
	temp2 = (char*)malloc(50*sizeof(temp2));
	temp3 = (char*)malloc(50*sizeof(temp3));
	
	system("cls");
	system("color E");
	puts("\n\t=======================================\n");
	printf("\t        Nama Kendaraan : ");
	scanf("%s",nama); fgetc(stdin); strcpy(str1, nama);
	
	int jumTemp, flag = -1;
	
	system("cls");
	system("color E");
	printf("    	           %s      \n", nama);
	puts("\t==================================================\n");
	while((fscanf(fp, "%[^-]-%[^-]-%[^-]-%[^#]#%d\n", temp1, str2, temp2, temp3, &jumTemp)) != EOF) {
		if(strcmp(str2, str1) == 0) {
			printf("\t        Barang : %s %s %s %s", temp1, str2, temp2, temp3);
			printf("\n\t        Jumlah : %d\n\n", jumTemp);
			flag = 0;
		} else {
			if(flag != 0) {
				flag = 1;
			}
		}
	}
	
	if(flag == 1) {
		printf("\t    Kendaraan tidak terdaftar dalam stok");
	}
	
	printf("\n\n\n%s", "Press any key to continue . . .");
	
	free(nama);
	free(merk);
	free(model);
	free(str1);
	free(str2);
	free(temp1);
	free(temp2);
	free(temp3);
	
	getch();
	mainmenu();
}

void cariBarangJenis() {
	FILE *fp;
	fp = fopen("data_files/data penjualan.in","r");
	
	char *nama, *merk, *model, *str1, *str2, *temp1, *temp2, *temp3;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	str1 = (char*)malloc(50*sizeof(str1));
	str2 = (char*)malloc(50*sizeof(str2));
	temp1 = (char*)malloc(50*sizeof(temp1));
	temp2 = (char*)malloc(50*sizeof(temp2));
	temp3 = (char*)malloc(50*sizeof(temp3));
	
	char jenis[5][10]={{"Motor"},{"Mobil"},{"Bus"}};
	
	system("cls");
	system("color E");
	int x = jenisb();
	strcpy(str1, jenis[x]);
	
	int jumTemp, flag = -1;
	
	system("cls");
	system("color E");
	printf("    	           %s      \n", jenis[x]);
	puts("\t==================================================\n");
	while((fscanf(fp, "%[^-]-%[^-]-%[^-]-%[^#]#%d\n", str2, temp1, temp2, temp3, &jumTemp)) != EOF) {
		if(strcmp(str2, str1) == 0) {
			printf("\t        Barang : %s %s %s %s", str2, temp1, temp2, temp3);
			printf("\n\t        Jumlah : %d\n\n", jumTemp);
			flag = 0;
		} else {
			if(flag != 0) {
				flag = 1;
			}
		}
	}
	
	if(flag == 1) {
		printf("\t    Kendaraan tidak terdaftar dalam stok");
	}
	
	printf("\n\n\n%s", "Press any key to continue . . .");
	
	free(nama);
	free(merk);
	free(model);
	free(str1);
	free(str2);
	free(temp1);
	free(temp2);
	free(temp3);
	
	getch();
	mainmenu();
}

void cariBarangFull() {
	FILE *fp;
	fp = fopen("data_files/data penjualan.in","r");
	
	char *nama, *merk, *model, *str1, *str2;
	nama = (char*)malloc(50*sizeof(nama));
	merk = (char*)malloc(50*sizeof(merk));
	model = (char*)malloc(50*sizeof(model));
	str1 = (char*)malloc(50*sizeof(str1));
	str2 = (char*)malloc(150*sizeof(str2));
	
	char jenis[5][10]={{"Motor"},{"Mobil"},{"Bus"}};
	
	system("cls");
	int x=jenisb();
	system("color E");
	printf("    	     Jenis Kendaraan : %s\n",jenis[x]); strcpy(str1, jenis[x]); strcat(str1, "-");
	puts("\t=======================================\n");
	printf("\t        Nama Kendaraan : ");
	scanf("%s",nama); fgetc(stdin); strcat(str1, nama); strcat(str1, "-");
	printf("\t        Merk Kendaraan : ");
	scanf("%s",merk); fgetc(stdin); strcat(str1, merk); strcat(str1, "-");
	printf("\t        Model Kendaraan : ");
	scanf("%s",model); fgetc(stdin); strcat(str1, model);
	
	int jumTemp, flag = -1;
	
	system("cls");
	system("color E");
	printf("    	     %s %s %s\n", nama, merk, model);
	puts("\t=======================================\n");
	while((fscanf(fp, "%[^#]#%d\n", str2, &jumTemp)) != EOF) {
		if(strcmp(str2, str1) == 0) {
			printf("\t        Jumlah Barang : %d", jumTemp);
			flag = 0;
		} else {
			if(flag != 0) {
				flag = 1;
			}
		}
	}
	
	if(flag == 1) {
		printf("\t    Kendaraan tidak terdaftar dalam stok");
	}
	
	printf("\n\n\n%s", "Press any key to continue . . .");
	
	free(nama);
	free(merk);
	free(model);
	free(str1);
	free(str2);
	
	getch();
	mainmenu();
}

void cariBarangMenu() {
	system("cls");
	setColor(2);
	puts("                       Pilih Cara Pencarian\n");
	setColor(6);
	printf("\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("             %c                                    %c",186,186);
	printf("\n\t     %c    1. Nama                         %c\n",186,186);
	printf("\t     %c    2. Jenis                        %c\n",186,186);
	printf("\t     %c    3. Jenis, Nama, Merk, dan Model %c\n",186,186);
	printf("\t     %c    4. Kembali                      %c\n",186,186);
	printf("             %c                                    %c",186,186);
printf("\n\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
		case 49 :
			cariBarangNama();
			break;
		case 50 :
			cariBarangJenis();
			break;
		case 51 :
			cariBarangFull();
			break;
		case 52 :
			mainmenu();
			break;
		default :
			invalidInput();
			system("cls");
			cariBarangMenu();
			break;
	}
}

void keluarProgram() { 
	system("cls");
	setColor(2);
	puts("\n       		        KELUAR PROGRAM\n");
	setColor(6);
	printf("\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("            %c                                     %c",186,186);
	printf("\t\n            %c          Apakah anda yakin?         %c\n",186,186);
	printf("\t    %c             1. Ya                   %c\n",186,186);
	printf("\t    %c             2. Kembali              %c\n",186,186);
	printf("            %c                                     %c",186,186);
	printf("\n\t    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	
	int i = 1, key;
	while(i) {
		if(kbhit() != 0) {
			key = getch();
			i = 0;
		}
	}
	switch(key) {
			case 49 :
				exit(0);
				break;
			case 50 :
				mainmenu();
				break;
			default :
				invalidInput();
				keluarProgram();
				break;
	}
}

int main() {
	setWindowSize();
	setFontSize();
	//sign in or sign up page
	beforeSignIn();

	return 0;
}
