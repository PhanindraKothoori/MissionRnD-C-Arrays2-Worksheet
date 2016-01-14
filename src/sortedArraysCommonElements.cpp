/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<conio.h>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int* tokenise(char* d){
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

int isOlder(char* d1, char* d2){
	int *token1, *token2;
	token1 = tokenise(d1);
	token2 = tokenise(d2);
	if (token1[0] == token2[0] && token1[1] == token2[1] && token1[2] == token2[2])
		return 2;
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

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A && B){
		struct transaction *C = (transaction*)malloc(sizeof(transaction) * 3);
		int i = 0, j = 0, k = 0;
		while (i < ALen && j < BLen){
			int res = isOlder(A[i].date, B[j].date);

			if (res == 2){
				C[k] = A[i];
				i++;
				j++;
				k++;
			}
			else if (res == 1){
				i++;
			}
			else if (res == 0){
				j++;
			}
		}
		return k>0 ? C : NULL;
	}
	else return NULL;
}
