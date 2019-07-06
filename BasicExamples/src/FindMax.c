#include <stdio.h>
#include <stdlib.h>

int FindMax(int array[])
{
	int i,j, max;

	for(i=0; i<10; i++)
		for(j = 1; j < 10; j++)
		{
			if(array[i] > array[j]){
				max = array[i];
			}
			else
			{
				max = array[j];
				j = 10;
			}
		}

	return max;
}

int FindMax_test(void)
{
    int max;
    int array[10] = {4, 5, 6, 8, 2, 3, 1, 2, 34, 10};

    puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

    max = FindMax(array);
    printf("max: %d", max);

    return EXIT_SUCCESS;
}
