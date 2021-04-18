#include <stdio.h>
#include <string.h>

void horizontal() {
	int line = 16;
	for(int i = 0; i < 5; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for(int i = 0; i < 15; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for(int i = 0; i < 6; i++) {
		printf("%c", 205);
	}
	printf("%c", 187);
}

void horizontalbetween() {
	printf("%c", 204);
	int line = 16;
	for(int i = 0; i < 5; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for(int i = 0; i < 15; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for(int i = 0; i < 6; i++) {
		printf("%c", 205);
	}
	printf("%c", 185);
	printf("\n");
}

void horizontalbetween2() {
	printf("%c", 204);
	int line = 16;
	for(int i = 0; i < 5; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < 15; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < 6; i++) {
		printf("%c", 205);
	}
	printf("%c", 185);
	printf("\n");
}

void horizontalend() {
	printf("%c", 200);
	int line = 16;
	for(int i = 0; i < 5; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < 15; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(int i = 0; i < 6; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
	printf("\n");
}

void horizontalend2() {
	int line = 62;
	printf("%c", 200);
	for(int i = 0; i < line; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
}
