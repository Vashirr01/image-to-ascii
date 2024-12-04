#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char *argv[]) {
	char Chars[] = " .:-=+*#%@";
	int length = strlen(Chars);

	int w, h, p;
	unsigned char* data = stbi_load(argv[1], &w, &h, &p, 0);

	int height_scale = 8;
	int width_scale = 3;

	for(int i =0; i<h; i+= height_scale){
		for(int j=0; j<w; j+=width_scale) {
	 int pixel_index = (i * w + j) *p;

	     int red = data[pixel_index +0];
		int green = data[pixel_index +1];
	     int blue = data[pixel_index +2];
			int average = (red+green+blue)/3;
		printf("%c", Chars[average *(length-1) /255]);
		}
		printf("\n");
	}
	stbi_image_free(data);
	return 0;
}
