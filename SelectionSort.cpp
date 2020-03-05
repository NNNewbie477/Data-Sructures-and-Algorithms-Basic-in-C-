#include <stdio.h>

int SelectionSort(int A[], int N){
	int i, j, t, sw = 0, minj;
	for (int i = 0; i < N - 1; ++i)
	{
		minj = i;
		for (int j = 0; j < N; ++j)
		{
			if(A[j] < A[minj]) minj = j;
		}
		t= A[i];
		A[i] = A[minj];
		A[minj] = t;
		if(i != minj) sw ++;
	}
}

int main(){
	int A[100], N, i, sw;

	scanf("%d", &N);

	for(int i = 0; i < N; i ++) scanf("%d", &A[i]);

	sw = SelectionSort(A, N);

	for(int i = 0; i < N; i ++){
		if(i > 0) printf(" ");
		printf("%d", A[i]);
	}

	printf("\n");
	printf("%d", sw);


	return 0;
}