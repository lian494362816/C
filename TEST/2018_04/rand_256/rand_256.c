#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Date: 2018 04 06


#define MY_RAND_MAX (256)
#define RAND_OUTPUT_PAHT "./out.txt"

int main(int argc, char *argv)
{
	int i;
	char String[64] = {0};
	FILE *pFile = NULL;

	pFile = fopen(RAND_OUTPUT_PAHT, "w+");
	if (NULL == pFile)
	{
		printf("fopen failed:%s\n", "out.txt");
		return 0;
	}
	
	for (i = 0; i < MY_RAND_MAX; i++)		
	{
		sprintf(String, "%d, ", rand());
		fwrite(String, strlen(String), 1, pFile);
		memset(String, 0, sizeof(String));

		if (0 == (i + 1) % 10)
		{
			sprintf(String, "\n");
			fwrite(String, strlen(String), 1, pFile);
			memset(String, 0, sizeof(String));
		}
	}

	fclose(pFile);

	return 0;
}
