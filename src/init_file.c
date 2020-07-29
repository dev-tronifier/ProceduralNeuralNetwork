#include "../include/init_file.h"
#include "../include/types.h"
#include <stdlib.h>
#include <stdio.h>

int rev_int(int i) {
        unsigned char c1, c2, c3, c4;
        c1 = i & 255;
        c2 = (i>>8) & 255;
        c3 = (i>>16) & 255;
        c4 = (i>>24) & 255;

        return ((int)c1<<24) + ((int)c2<<16) + ((int)c3<<8) + c4;
}

void read_mnist(char* path) {
	FILE* fptr = fopen(path, "rb");
	if(!fptr){
		ERROR("FILE NOT FOUND\n");
		exit(-1);
	}

	int mag_no = 0, n_images = 0, n_cols = 0, n_rows = 0;

	READ(mag_no, fptr);
	READ(n_images, fptr);
	READ(n_rows, fptr);
	READ(n_cols, fptr);

	FOR_EQ(rev_int, mag_no, n_images, n_rows, n_cols);

	printf("%d %d %d\n", n_images, n_rows, n_cols);

	for(int i = 0; i < n_images; i++){
		for(int r = 0; r < n_rows; r++){
			for(int c = 0; c < n_cols; c++){
				uchar data = 0;
				READ(data, fptr);
			}
		}
	}
}
