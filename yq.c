#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct yiqing
{
	char provinces[32];
	char city[32];
	int number;
} yq;

int main(int argc, char *argv[])
{
	FILE *r = fopen("E:/test/yq_in.txt", "r");
	assert(r != NULL);
	FILE *w = fopen("E:/test/yq.txt", "w");
	assert(w != NULL);

	yq a[150];
	int i = 0;
	while (fscanf(r, "%s%s%d", a[i].provinces, a[i].city, &a[i].number) != EOF)
	{
		if (i == 0)
		{
			printf("%s\n", a[i].provinces);
			fprintf(w, "%s\n", a[i].provinces);
			printf("%s\t %d\n", a[i].city, a[i].number);
			fprintf(w, "%s\t %d\n", a[i].city, a[i].number);
		}
		else if (strcmp(a[i].provinces, a[i - 1].provinces) == 0)
		{
			printf("%s\t %d\n", a[i].city, a[i].number);
			fprintf(w, "%s\t %d\n", a[i].city, a[i].number);
		}
		else if (strcmp(a[i].provinces, a[i - 1].provinces) != 0)
		{
			printf("\n");
			fprintf(w, "\n");
			printf("%s\n", a[i].provinces);
			fprintf(w, "%s\n", a[i].provinces);
			printf("%s\t %d\n", a[i].city, a[i].number);
			fprintf(w, "%s\t %d\n", a[i].city, a[i].number);
		}
		i++;
	}
	fclose(r);
	fclose(w);

	system("pause");
	return 0;
}
