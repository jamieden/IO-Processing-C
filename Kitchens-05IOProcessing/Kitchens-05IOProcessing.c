// -----------------------------------------
// -- Written by..: James Kitchens        --
// -- Date Written: 05/22/2018            --
// -- Purpose.....: xxxxxxxxxxxxxxxxxxxx  --
// -----------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define SIZE 101

typedef int bool;
const bool true = 1;
const bool false = 0;

typedef char* String;

void writeFile(String file, String word);
void readFile(String file);

int main() {
	String word = "Timekeper is great! Not really.";
	writeFile("myFile.bin", word);
	readFile("myFile.bin");
} //End main

void writeFile(String file, String word) {
	FILE *ptr;
	ptr = fopen(file, "wb"); //Opens the file for writing
	if (ptr == NULL) {
		printf("Error opening file\n");
		system("pause");
		exit(-1);
	}
	fwrite(word, 1, strlen(word), ptr);
	fclose(ptr);
	system("pause");
}

void readFile(String file) {
	FILE *ptr;
	ptr = fopen(file, "rb"); //Opens the file for reading
	if (ptr == NULL) {
		printf("Error opening file\n");
		system("pause");
		exit(-1);
	}
	String f = "";
	int flen1 = sizeof(String*);
	//Gets file length
	fseek(ptr, 0, SEEK_END);
	int flen = ftell(ptr); 
	int flen2 = flen;
	fseek(ptr, 0, SEEK_SET);
	//fread(people, sizeof(PERSON), 3, ptr);
	fread(&f, flen, 1, ptr); //Reads the file and puts the data inside a variable
	printf("The word: %s\n", &f);
	fclose(ptr); //ERROR EXISTS HERE
	system("pause");
}