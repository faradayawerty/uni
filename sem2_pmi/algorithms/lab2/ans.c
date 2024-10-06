#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "string.txt"

// линейный поиск
int lin(char *str, char *sub);

// поиск Бойера--Мура
int bm(char *str, char *sub);

// поиск Кнута--Морриса--Пратта
int kmp(char *str, char *sub);

// поиск Карпа-Рабина
int kr(char *str, char *sub);

int main()
{
	FILE *f = fopen(FILENAME, "r");
	if(f == NULL) {
		puts("can't open the file");
		return 1;
	}

	size_t str_size = 32, str_len;
	char *str = (char*)malloc(str_size*sizeof(char));

	size_t sub_size = 8, sub_len;
	char *sub = (char*)malloc(sub_size*sizeof(char));

	// breaks when reached end of file
	while(true) {
		do {
			str_len = getline(&str, &str_size, f);
		} while(str_len == 1);

		do {
			sub_len = getline(&sub, &sub_size, f);
		} while(sub_len == 1);

		if(str_len == -1 || sub_len == -1)
			break;

		// remove newline character at the end
		str[str_len-- - 1] = '\0';
		sub[sub_len-- - 1] = '\0';

		printf("%8d\t%8d\t%8d\t%8d\n",
				lin(str, sub),
				bm(str, sub),
				kmp(str, sub),
				kr(str, sub));
	}
	
	free(str); free(sub); fclose(f);
	return 0;
}

int lin(char *str, char *sub)
{
	int sub_len = strlen(sub), count = 0;;

	for(int i = 0; str[i + sub_len - 1] != '\0'; i++) {
		for(int j = 0; j < sub_len && str[i+j] == sub[j]; j++) {
			count++;
			if(j == sub_len-1)
				return count;
		}
		count++;
	}

	return count;
}

int bm(char *str, char *sub)
{
	int sub_len = strlen(sub), count = 0;

	// preprocessing bad match table
	int bmt[256];
	for(int i = 0; i < 256; i++)
		bmt[i] = sub_len;
	for(int i = 0; i < sub_len-1; i++)
		bmt[sub[i]] = sub_len - 1 - i;

	// actual search
	for(int i = 0; str[i + sub_len - 1] != '\0'; i += bmt[str[i + sub_len - 1]]) {
		for(int j = sub_len-1; j >= 0 && str[i+j] == sub[j]; j--) {
			count++;
			if(j == 0)
				return count;
		}
		count++;
	}

	return count;
}

int kmp(char *str, char *sub)
{
	int sub_len = strlen(sub), count = 0;
	int *lps = (int*)malloc(sub_len * sizeof(int)); // largest proper suffix

	lps[0] = 0;
	for(int i = 1, j = 0; i < sub_len; i++) {
		while (sub[i] != sub[j] && j != 0) {
			count++;
			j = lps[j-1];
		}

		count++;
		if(sub[i] == sub[j])
			j++;

		lps[i] = j;
	}

	for(int i = 0, j = 0; str[i] != '\0'; i++) {
		while(str[i] != sub[j] && j != 0) {
			count++;
			j = lps[j-1];
		}

		count++;
		if(str[i] == sub[j])
			j++;

		if(j == sub_len)
			return count;
	}

	return count;
}

int kr(char *str, char *sub)
{
	int sub_len = strlen(sub), sub_hash = 0, str_hash = 0, count = 0;

	for(int i = 0; i < sub_len; i++) {
		sub_hash += sub[i];
		str_hash += str[i];
	}

	count++;
	if(str_hash == sub_hash)
		return count;

	for(int i = sub_len; str[i] != '\0'; i++) {
		str_hash += str[i] - str[i-sub_len];
		count++;
		if(sub_hash == str_hash) {
			bool equal = true;
			for(int j = 0; j < sub_len; j++) {
				count++;
				if(str[i - sub_len + j + 1] != sub[j])
					equal = false;
			}
			if(equal)
				return count;
		}
	}

	return count;
}

