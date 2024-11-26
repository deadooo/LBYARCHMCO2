#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void imgCvtGrayInttoFloat(int *intImage, float *floatImage, int height, int width);

int main() {
    int height, width;
    int i = 0;
    int j = 0;
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    

    // Allocate memory for integer and float images
    int *intImage = (int *)malloc(height * width * sizeof(int));
    float *floatImage = (float *)malloc(height * width * sizeof(float));
    if (intImage == NULL || floatImage == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the integer pixel values
    printf("Enter the pixel values (row by row):\n");
    int test;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
        	test = 0;
        	scanf("%d", &test);
        	if(test >= 1 && test <= 255){
        		intImage[i * width + j] = test;
			}else{
				printf("Error please enter valid input(1 - 255)\n");
			}
            
        }
    }

    // Generate random integer grayscale image
//    printf("Random integer grayscale image:\n");
//    srand(time(NULL));
//    for (i = 0; i < height; i++) {
//        for (j = 0; j < width; j++) {
//            intImage[i * width + j] = rand() % 256; // Random value [0, 255]
//            printf("%d ", intImage[i * width + j]);
//        }
//        printf("\n");
//    }

    // Call the assembly function and start clock
    clock_t start = clock();
    imgCvtGrayInttoFloat((int *)intImage, (float *)floatImage, height, width);
    // End clock
	clock_t end = clock();
	
    // Print the float grayscale image
    printf("\nFloat grayscale image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", floatImage[i * width + j]);
        }
        printf("\n");
    }
	// Print the time taken running the asm function
	printf("\nTime taken: %.2f ms\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);
	
    // Free allocated memory
    free(intImage);
    free(floatImage);

    return 0;
}