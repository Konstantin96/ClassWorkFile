#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <string.h>

struct k
{
	int *mas;
	double *mas1;
};

struct date
{
	int year;
	int m;
	int d;
};

using namespace std;

void main()
{
	int nz;
	do
	{
		printf("Enter number nz: ");
		scanf("%d", &nz);
		cin.get();
		if (nz == 1)
		{
			FILE *pf;
			char s[80];
			int t = 0;
			//create file
			if ((pf = fopen("test.txt", "w")) == NULL)
			{
				printf("Error opened file!\n");
				exit(EXIT_FAILURE);
			}

			else
			{//write in file
				printf("Enter string and number: ");

				fscanf(stdin, "%s %d", s, &t);
				fprintf(pf, "# %d. %s", t, s);
				fclose(pf);
			}

			//read file
			if ((pf = fopen("test.txt", "r")) == NULL)
				exit(EXIT_FAILURE);

			char name[80];
			int i = 0;

			//to read this file
			fscanf(pf, "# %d. %s", &i, name);
			fprintf(stdout, "# %d. %s\n", i, name);
		}

		else if (nz == 2)
		{
			FILE *file;
			char words[40];
			if ((file = fopen("file.txt", "a+")) == NULL)
			{
				fprintf(stdout, "Error opened file!\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				puts("Enter string. Enter 'ENTER'");
				puts("in first string to close programm:");
				cin.get();
				while (gets_s(words) != NULL && words[0] != '\0')
				{
					fprintf(file, "%s", words);
				}
				puts("Text in file: ");
				rewind(file);

				while (fscanf(file, "%s", words) == 1)
				{
					puts(words);
				}
				if (fclose(file) != 0)
					fprintf(stderr, "ERROR IN FILE!");
			}
		}

		else if (nz == 3)
		{
			//KAK uznat' dlinu stroki v file
			FILE *file;
			char buff[10];
			char *input = NULL;
			size_t curLen = 0;

			while (fgets(buff, sizeof(buff), stdin) != 0)
			{
				size_t bufLen = strlen(buff);
				char* extra = (char*)realloc(input, bufLen + curLen + 1);
				if (extra == NULL)
					break;

				input = extra;
				strcpy(input + curLen, buff);
				curLen += bufLen;
			}
			printf("%s [%d] elements in string\n", input, (int)strlen(input));

			free(input);
		}

		else if (nz == 4)
		{
			FILE *file;
			double d = 56.7, newD = 5.3;
			int i = 101, newI = 5;
			long l = 123155L, newL = 41654L;

			if ((file = fopen("fread.txt", "wb+")) == NULL)
			{
				printf("ERROR");
				exit(0);
			}
			else
			{
				fwrite(&d, sizeof(double), 1, file);
				fwrite(&i, sizeof(int), 1, file);
				fwrite(&l, sizeof(long), 1, file);

				//perehod k nachalu file
				rewind(file);

				fread(&newD, sizeof(double), 1, file);
				fread(&newI, sizeof(int), 1, file);
				fread(&newL, sizeof(long), 1, file);

				printf("%2.1lf %ld - %d\n\n", newD, newL, newI);

				fclose(file);
			}
		}

		/* Дан файл, содержащий различные даты. Каждая дата - это число, месяц и год. Найти самую раннюю дату.*/
		else if (nz == 5)
		{
			FILE * file;
			unsigned int year;
			unsigned int m;
			unsigned int d;
			if ((file = fopen("time", "w")) != NULL)
			{
				for (int i = 0;i < 10;i++)
				{
					year = 1950 + rand() % 100;
					m = 1 + rand() % 11;
					d = 1 + rand() % 30;
					fprintf(file, "%2d.%2d.%4d\n", d, m, year);
				}
				fclose(file);
			}
			if ((file = fopen("time", "r")) != NULL)
			{
				date dates[10];
				for (int i = 0;i < 10;i++)
				{
					fscanf(file, "%2d.%2d.%4d",
						&dates[i].d, &dates[i].m, &dates[i].year);
				}
				fclose(file);
				for (int i = 0;i < 10;i++)
				{
					printf("%2d.%2d.%4d\n", dates[i].d, dates[i].m, dates[i].year);
				}
				int min_y = 5000;
				int ind_i = 0;
				for (int i = 0;i < 10;i++)
				{
					if (dates[i].year < min_y)
					{
						min_y = dates[i].year;
						ind_i = i;
					}
				}
				int b = 0;
				for (int i = 0;i < 10;i++)
				{
					if (i != ind_i)
					{
						if (dates[i].year == min_y)b = 1;
					}
				}
				if (b == 0)
				{
					printf("%2d.%2d.%4d\n", dates[ind_i].d, dates[ind_i].m, dates[ind_i].year);
				}
			}
		}

		/* Дан символьный файл f. Записать в файл g компоненты файла f в обратном порядке*/
		else if (nz == 6)
		{
			FILE * file;
			FILE * nfile;
			if ((file = fopen("time", "r")) != NULL)
			{
				char r;
				while (r != '\n')
				{
					fgetc(file);
				}
				if ((file = fopen("newtime", "w")) != NULL)
				{
					fprintf(nfile, " ");
				}
			}
		}

		/* Файл состоит из k компонент структуры, где каждая компонента содержит две матрицы: первая размерности m x n, вторая размерности m x l.
		Получить k произведений соответствующих матриц и записать их во второй файл. Вывести на экран содержимое первого и второго файлов.*/
		else if (nz == 7)
		{
			k k[10];
			int m, n, l;
			printf("Enter count stolbcov: ");
			scanf("%d", &m);
			printf("Enter count strok: ");
			scanf("%d", &n);
			printf("Enter count strok 2 matricy: ");
			scanf("%d", &l);

			for (int i = 0; i < 10; i++)
			{
				k[i].mas = (int*)malloc(m*n * sizeof(int));
				for (int j = 0;j < m*n;j++)
				{
					k[j].mas[i] = 1 + rand() % 49;
				}
				k[i].mas1 = (double*)malloc(m*l * sizeof(double));
				for (int j = 0;j < m*l;j++)
				{
					k[j].mas1[i] = 1.5 + rand() % 48 / 1.1 + rand() % 48;
				}
			}
		}

	} while (nz != 0);
}