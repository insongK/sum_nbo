#include <stdio.h>
#include <stdint.h>

uint32_t htonl(uint32_t u32);

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Enter at least one file Name");
		return -1;
	}
	uint32_t answer = 0;
	for(int i = 1; i < argc; i++){
		FILE *fp = fopen(argv[i], "rb");
		uint32_t u32;
		if(fp == NULL)     continue;	

		size_t read_size = fread(&u32, sizeof(uint8_t), 8, fp);
		fclose(fp);
		if(read_size != 4) continue;
		
		answer += u32 = htonl(u32);
		
		if(answer == u32) printf("%d(0x%x)", u32, u32);
		else	          printf(" + %d(0x%x)", u32, u32);
	}
	printf(" = %d(0x%x)\n", answer, answer);

	return 0;
}

uint32_t htonl(uint32_t u32){
	uint8_t u8[4];

	u8[0] = (u32 >> 0)  & 0xFF;
	u8[1] = (u32 >> 8)  & 0xFF;
	u8[2] = (u32 >> 16) & 0xFF;
	u8[3] = (u32 >> 24) & 0xFF;

	return (u8[0] << 24) | (u8[1] << 16) | (u8[2] << 8) | (u8[3] << 0);
} 
