#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)

int H, A[MAX + 1];

void MaxHeapify(int i){
    int i, r, largest;
    l = 2 * i;
    r = 2 * i + 1;

    if(l <= H && A[l] > A[i]) largest = l;
    else largest = H;
    if(r <= H && A[r] > A[largest]) largest = r;
    if(largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(largest);
    }
}

int Extract(){
    int maxv;
    if(H < 1) return -INFTY;
    maxv = A[1];
    A[1] = A[H --];
    MaxHeapify(1);
    return maxv;
}

void IncreaseKey(int i, int key){
    if(key < A[i]) return;
    A[i] = key;
    while(i > 1 && A[i / 2] < A[i]){
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}

void Insert(int key){
    H ++;
    A[H] = -INFTY;
    IncreaseKey(H, key);
}

int main(){
    int key;
    char com[10];
    while(1){
        scanf("%s", com);
        if(com[0] == 'e' && com[1] == 'n') break;
        if(com[0] == 'i'){
            scanf("%d", &key);
            Insert(key);
        }else{
            printf("%d\n", Extract());
        }
    }


    return 0;
}