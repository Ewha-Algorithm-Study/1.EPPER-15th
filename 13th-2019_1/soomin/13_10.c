#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// minimum number of nodes for a tree that generates the given prefix
// n: number of prefix (1 <= n <= 16)
// number of characters per a prefix is smaller than 1000
int main()
{
	int n, i, j, k;
	char prefix[16][1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", &prefix[i]);
	int alphabet_sets[16][26] = { 0 };
	int min_node = 1;
	for (i = 0; i < n; i++)
	{
		char x;
		for (j = 0; j < 26; j++)
		{
			for (k = 0; k < strlen(prefix[i]); k++)
			{
				x = prefix[i][k];
				if (x == (char)('a' + j))
				{
					alphabet_sets[i][j]++;
				}
			}
		}
		for(j=0; j<26; j++)
			printf("%d", alphabet_sets[i][j]);
		printf("\n");
	}
	// compare the generated alphabet_sets to count the number of nodes
	
	int occupied[26][26] = { 0 };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 26; j++)
		{
			if (alphabet_sets[i][j] != 0)
			{
				occupied[j][j] = alphabet_sets[i][j];
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 26; j++)
		{
			min_node += occupied[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (alphabet_sets[i][j] != 0)
			{ 
				for (k = 0; k < 26; k++)
				{
					if (occupied[j][k] < alphabet_sets[i][k])
					{
						//printf("occ: %d, alphabet: %d\n", occupied[j][k], alphabet_sets[i][k]);
						min_node += (alphabet_sets[i][k]- occupied[j][k]);
						occupied[j][k] = alphabet_sets[i][k];
					}
				}
				break;
			}
		}
	}
	printf("MATRIX\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 26; j++)
		{
			printf("%d", occupied[i][j]);
		}
		printf("\n");
	}
	printf("%d", min_node);
}





