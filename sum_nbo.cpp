#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Enter at least one file Name");
		return -1;
	}
	for(int i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "rb");
		unsigned char buffer[4];

		if(fp == NULL){
			perror (argv[i]); 
		}

		size_t byteRead = fread(buffer, 1, sizeof(buffer), fp);
		for(size_t i = 0; i < byteRead; i++){
			printf("%02X ", buffer[i]);
		}
		printf("\n");
	}

	return 0;
}

