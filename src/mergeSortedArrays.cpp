/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int* tokens(char* d){
	int* token = (int*)malloc(sizeof(int) * 3), j = 0;
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
bool isOLD(char* d1, char* d2){
	int *token1, *token2;
	token1 = tokens(d1);
	token2 = tokens(d2);
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
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *C = (transaction*)malloc(sizeof(transaction)*(ALen + BLen));
	if (A && B){
		int i = 0, j = 0, k = 0;
		while (i < ALen && j < BLen){
			if (isOLD(A[i].date, B[j].date)){
				C[k] = A[i];
				i++;
			}
			else{
				C[k] = B[j];
				j++;
			}
			k++;
		}
		while (i < ALen){
			C[k] = A[i];
			k++;
			i++;
		}
		while (j < BLen){
			C[k] = B[j];
			k++;
			j++;
		}
		return C;
	}
	else return NULL;

}