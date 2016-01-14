/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int* tokenize(char* d){
	int* token = (int*)malloc(3 * sizeof(int)), j = 0;
	int temp = 0, i = 0;

	while (i<11){
		while (d[i] != '-' && d[i] >= '0' && d[i] <= '9'){
			temp = temp * 10 + (d[i] - '0');
			i++;
		}
		token[j] = temp;
		j++;
		i++;
		if ((d[i]) == '\0') break;
		temp = 0;
	}
	return token;
}
bool isOlder(char* d1, char* d2){
	int *token1, *token2;
	token1 = tokenize(d1);
	token2 = tokenize(d2);
	if (token1[0] == token2[0] && token1[1] == token2[1] && token1[2] == token2[2])
		return false;
	else if (token1[2] > token2[2]){
		return false;
		if (token1[1] > token2[1]){
			return false;
			if (token1[0] > token2[0])
				return false;
		}
	}
	else return true;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, count = 0;
	while (i < len){
		if (isOlder(date, Arr[i].date)){
			count++;
		}
		i++;
	}
	return count;
}
