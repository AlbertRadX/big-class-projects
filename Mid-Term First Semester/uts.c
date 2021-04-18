#include <stdio.h>
#include <string.h> //menggunakan strlen()
#include <conio.h> //menggunakan kbhit()
#include <ctype.h> //menggunakan isdigit()
#include <windows.h> //menggunakan system("cls")

void penjumlahan(int a,int b,int c) {
	int result=a+b+c;
	int i,j;
	if(result>40) {
		puts("Hasil penjumlahan anda lebih dari 40\n");
	} else {
		printf("\nHasil :\n");
		if(a!=0) {
			i=0;
			while(i<a) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if((a!=0 && b!=0) || (a!=0 && c!=0) ) printf("+\n");
		if(b!=0) {
			i=0;
			while(i<b) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if(b!=0 && c!=0) printf("+\n");
		if(c!=0) {
			i=0;
			while(i<c) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if(result!=0) {
			printf("=\n");
			i=0;
			while(i<result) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		
		if(a!=0 && b!=0 && c!=0) {
			printf("%d + %d + %d = %d",a,b,c,result);
		} else if(a!=0 && b!=0) {
			printf("%d + %d = %d",a,b,result);
		} else if(b!=0 && c!=0) {
			printf("%d + %d = %d",b,c,result);
		}	else if(a!=0 && c!=0) {
			printf("%d + %d = %d",a,c,result);
		}
	}	
}

void pengurangan(int a,int b,int c) {
	int result=a-b-c;
	int i,j;
	if(result>40) {
		puts("Hasil pengurangan anda lebih dari 40\n");
	} else {
		printf("\nHasil :\n");
		if(a!=0) {
			i=0;
			while(i<a) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if((a!=0 && b!=0) || (a!=0 && c!=0) ) printf("-\n");
		if(b!=0) {
			i=0;
			while(i<b) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if(b!=0 && c!=0) printf("-\n");
		if(c!=0) {
			i=0;
			while(i<c) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		if(result!=0) {
			printf("=\n");
			i=0;
			while(i<result) {
				i++;
				printf("#");
				if(i%10==0) {
					printf("\n");
				}
			}
			if(i%10!=0) {
				printf("\n");
			}
		}
		
		if(a!=0 && b!=0 && c!=0) {
			printf("%d - %d - %d = %d",a,b,c,result);
		} else if(a!=0 && b!=0) {
			printf("%d - %d = %d",a,b,result);
		} else if(b!=0 && c!=0) {
			printf("%d - %d = %d",b,c,result);
		}	else if(a!=0 && c!=0) {
			printf("%d - %d = %d",a,c,result);
		}
	}	
}

void perkalian(int a,int b) {
	int result=a*b;
	int i,j;
	printf("\nHasil :\n");
	for(i=0;i<b;i++) {
		for(j=0;j<a;j++) {
			printf("@");
		}
		printf("\n");
	}
	printf("\n");
	printf("Hasil dari %d x %d adalah %d, sesuai dengan jumlah data diatas.",a,b,result);
}

void segiSamKaki(int x) {
	int i=1,j;
	while (i<=x) {
		if(i<x) {
			for(j=1;j<=i;j++) {
				printf("#");
			}
			printf("\n");
		} else {
			for(j=1;j<=x;j++) {
				printf("#");
			}
		}
		i++;
	}
}

void segiSamSisi(int x) {
	int i,j;
	for(i=1;i<=x;i++) {
		for(j=1;j<=x-i;j++) {
			printf(" ");
		}
		for(j=1;j<=i;j++) {
			printf("# ");
		}
		printf("\n");
	}
}

int keluarProgram() {
	int key,i=1;
	system("cls");
	puts("Apakah anda ingin keluar dari aplikasi ini?");
	puts("    1. Ya");
	puts("    2. Tidak");
	while(i) {
		if(kbhit()!=0) {
			key=getch();
			i=0;
		}	
	}
	switch(key) {
		case 49:
			return 1;
			break;
		case 50:
			return 2;
			break;
		default:
			system("cls");
			puts("Invalid Input");
			puts("Tekan tombol apapun untuk kembali ke main menu");
			getch();
			return 5;
			break;
	}
}

int nameCheck(char *str) {
	int i,ctd=0;
	for(i=0;i<strlen(str);i++) {
		if(isdigit(str[i])!=0) {
			system("cls");
			puts("Nama tidak valid!");
			puts("Nama tidak boleh memiliki angka!\n");
			return -1;
		}
	}
	for(i=0;i<strlen(str);i++) {
		if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') {
			ctd++;
		}
		if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
			ctd++;
		}
	}
	return ctd;
}

void mainMenu(char *str,int x) {
	int i;
	system("cls");
	puts("Selamat datang di Aplikasi :");
	puts("\tBelajar Bersama dan Menyenangkan");
	printf("Nama Siswa : %s\n",str);
	printf("\n\n");
	printf("Selamat siang, %s gunakan menu berikut untuk dapat belajar.\n",str);
	puts("\tBelajar Bersama dan Menyenangkan");
	//garis {
	for(i=0;i<62;i++) {
		if(x>6) {
			printf("%c",'+');
		} else {
			printf("%c",'-');
		}	
	}
	printf("\n");
	//}
	puts("   1. Penjumlahan");
	puts("   2. Pengurangan");
	puts("   3. Perkalian");
	puts("   4. Bangun datar");
	puts("   0. Keluar dari aplikasi");
}

int keyMenuPressed(int key) {
	switch(key) {
		case 48:
			return 0;
			break;
		case 49:
			return 1;
			break;
		case 50:
			return 2;
			break;
		case 51:
			return 3;
			break;
		case 52:
			return 4;
			break;
		default:
			system("cls");
			puts("Invalid Input");
			puts("Tekan tombol apapun untuk kembali ke main menu");
			getch();
			return 5;
			break;
	}
}

int main() {
	char username[100];
	int i,vowel=-1,key;
	
	//tampilan awal (input nama)
	while(vowel==-1) {
		puts("Isi nama anda di bawah ini");
		gets(username);
		vowel=nameCheck(username);
	}
	
	//tampilan menu
	menu :
		mainMenu(username,vowel);
		i=1;
		while(i) {
			if(kbhit()!=0) {
				key=keyMenuPressed(getch());
				if(key==5) {
					mainMenu(username,vowel);
				} else {
					i=0;
				}
			}
		}
	
	//penjumlahan
	if(key==1) {
		int num1,num2,num3;
			system("cls");
			puts("Hasil penjumlahan tidak dapat lebih dari 40!");
			printf("Bilangan 1 : "); scanf("%d",&num1);
			printf("Bilangan 2 : "); scanf("%d",&num2);
			printf("Bilangan 3 : "); scanf("%d",&num3);
			penjumlahan(num1,num2,num3);
		puts("\n\nTekan tombol apapun untuk kembali ke main menu");
		getch();
		goto menu;
	}
	//pengurangan
	if(key==2) {
		int num1,num2,num3;
			system("cls");
			puts("Hasil pengurangan tidak dapat lebih dari 40!");
			printf("Bilangan 1 : "); scanf("%d",&num1);
			printf("Bilangan 2 : "); scanf("%d",&num2);
			printf("Bilangan 3 : "); scanf("%d",&num3);
			pengurangan(num1,num2,num3);
		puts("\n\nTekan tombol apapun untuk kembali ke main menu");
		getch();
		goto menu;
	}
	//perkalian
	if(key==3) {
		int num1,num2;
			system("cls");
			printf("Bilangan 1 : "); scanf("%d",&num1);
			printf("Bilangan 2 : "); scanf("%d",&num2);
			perkalian(num1,num2);
		puts("\n\nTekan tombol apapun untuk kembali ke main menu");
		getch();
		goto menu;
	}
	//bangun datar (segitiga sama kaki dan seigitga sama sisi)
	if(key==4) {
		int num1,num2;
			system("cls");
			puts("Segitiga sama kaki");
			printf("Sisi : "); scanf("%d",&num1);
			segiSamKaki(num1);
			puts("\n\nSegitiga sama sisi");
			printf("Sisi : "); scanf("%d",&num2);
			segiSamSisi(num2);
		puts("\n\nTekan tombol apapun untuk kembali ke main menu");
		getch();
		goto menu;
	}
	//keluar program
	if(key==0) {
		i=keluarProgram();
		if(i==2) {
			goto menu;	
		} else if(i==1) {
			return 0;
		} else {
			goto menu;
		}
	}

	
	return 0;
}
