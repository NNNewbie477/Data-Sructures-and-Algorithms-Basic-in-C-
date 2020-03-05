#include <iostream>
using namespace std;
#define MAX 100000

int Parent(int i ){return i / 2;}
int Left(int i){return 2 * i;}
int Right(int i){return 2 * i + 1;}

int main(){
    int H, i, A[MAX + 1];
    
    cin >> H;

    for(i = 1; i <= H; i ++) cin >> A[i];
    for(i = 1; i <= H; i ++){
        cout << "node " << i << ": key = " << A[i] << ", ";
        if(Parent(i) >= 1) cout << "parent key = " << A[Parent(i)] << ", ";
        if(Left(i) <= H) cout << "left key = " << A[Left(i)] << ", ";
        if(Right(i) <= H) cout << "right key = " << A[Right(i)] << ", ";
        cout << endl;
    }

    return 0;
}