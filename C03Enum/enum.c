#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, d, e, f, g, h, i;
	int num=0;
	for (a = 1; a <= 9; a++)
		for (b = 1; b <= 9; b++)
			for (c = 1; c <= 9; c++)
				for (d = 1; d <= 9; d++)
					for (e = 1; e <= 9; e++)
						for (f = 1; f <= 9; f++)
							for (g = 1; g <= 9; g++)
								for (h = 1; h <= 9; h++)
									for (i = 1; i <= 9; i++) {
										if()
										if ((a * 100 + b * 10 + c + d * 100 + e * 10 + f) == (g * 100 + h * 10 + i)) { 
											num++; 
											printf("%d%d%d+%d%d%d=%d%d%d.\n\r", a, b, c, d, e, f, g, h, i);
										}
									}
	num = num / 2;
	printf("num is %d.\n\r",num);
	return 0;

}