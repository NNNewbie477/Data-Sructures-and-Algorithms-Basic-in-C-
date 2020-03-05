#include <iostream>
using namespace std;

struct Card
{	int suit;
	char value;
};

void print(struct Card A[], int N){
	for(int i = 0; i < N; i ++){
		if(i > 0) cout << " ";
		cout << Card[i].suit << Card[i]. value << endl;
	}
	cout << endl;
}

void bubble(struct Card A[], int N){
	for(int i = 0; i < N - 1; i ++){
		for(int j = N - 1; j >= i + 1; j --){
			if(A[j].value < A[j - 1].value){
				Card t = A[j];
				A[j] = A[j - 1];
				A[j - 1] = t;
			}
		}
	}

}

void Selection(struct Card A[], int N){
	for(int i = 0; i < N; i++){
		int minj = i;
		for(int j = i; j < N; j ++){
			if(A[j].value < A[minj]){
				Card t = A[minj];
				A[minj] = A[j];
				A[j] = t;
			}
		}
	}

}

bool isStable(struct Card A[], struct Card B[], int N){
	for(int i = 0; i <= N; i++){
		if(C1[i].suit != C2[i].suit) return false;
	}
	else return true;
}

int main(){
	Card C1[100], C2[100];
	int N;
	char ch;

	cin >> N;
	for(int i = 0; i < N; i ++){
		cin >> C1[i].suit >> C1[i].value;
	}
	for(int i = 0; i < N; i++) C2 = C1;

	bubble(C1, N);
	Selection(C2, N);

	print(C1);
	cout << "Stable" << endl;

	print(C2);
	if(isStable(C1, C2, N)){
		cout << "Stable" << endl;
	}
	else cout << "Not Stable" <<endl;



	return 0;

}