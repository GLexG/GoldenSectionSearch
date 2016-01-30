#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

double f(float x){
		float pom;
		pom = (x*x*x)-2*x-5;
		return pom;
}

int main(void)
{
		float golden_ratio = (sqrt(5) - 1)/2;

		float c,d,fc,fd;
		double a = 0, b = 55;

		c = b - golden_ratio * (b - a);
		d = a + golden_ratio * (b - a);

		//while(Math.Abs(c-d)>error_margin)
		for(int i=0; i<60; i++)
		{
			fc = f(c); fd = f(d);
			if(fc < fd)
			{
				b=d;
				d=c;
				c = b - golden_ratio * (b - a);
			}
			else
			{
				a=c;
				c=d;
				d=a+golden_ratio * (b - a);
			}
			//return (b+a)/2;
			printf("%12.15f \n" , ((b+a)/2) );
		}
		return (b+a) /2;



	/*const int size = 384;
	int sizeBytes = size * sizeof(int32_t);
	int32_t *x = malloc(sizeBytes);
	int32_t *y = malloc(sizeBytes);
	int32_t *s = malloc(sizeBytes);
	int scalar = 3; 

	// TODO Generate input data
	for(int i = 0; i<size; ++i) {
		x[i] = random() % 100;
		y[i] = random() % 100;
	}

	printf("Writing to LMem.\n");
	MemStream_writeLMem(0, sizeBytes, x);

	printf("Running on DFE.\n");	
	MemStream(scalar, size, y, s);
	
	// TODO Use result data
	for(int i=0; i<size; ++i)
		if (s[i] != x[i] + y[i] + scalar)
			return 1;

	printf("Done.\n");
	return 0;*/
}
