#include <iostream>
using namespace std;
#define MAX 2000000

int H, A[MAX + 1];

void MaxHeapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if(l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if(r <= H && A[r] > A[largest]) largest = r;

    if(largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(largest);
    }
}

int main(){
    cin >> H;

    for(int i = 0; i <= H; i ++) cin >> A[i];

    for(int i = H / 2; i >= 1; i --) MaxHeapify(i);

    for(int i = 1; i <= H; i ++){
        cout << " "  << A[i];
    }
    cout << endl;

    return 0;
}