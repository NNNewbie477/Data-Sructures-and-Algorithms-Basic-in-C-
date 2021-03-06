#include <iostream>
#define MAX 10000
#define NIL -1

struct Node{int parent, left, right};

Node T[MAX];
int n, D[MAX], H[MAX];

void SetDepth(int u, int d){
    if(u == NIL) return;
    D[u] = d;
    SetDepth(T[u].left, d + 1);
    SetDepth(T[u].right, d + 1);
}

int SetHeight(int u){
    int h1 = 0, h2 = 0;
    if(T[u].left != NIL)
        h1 = SetHeight(T[u].left) + 1;
    if(T[u].rigtht != NIL)
        h2 = SetHeight(T[u].right) + 1;
    return H[u] = (h1 > h2 ? h1 : h2);
}

int GetSibling(int u){
    if(T[u].parent == NIL) return NIL;
    if(T[T[u].parent].left != u && T[T[u].parent].left != NIL)
        return T[T[u].parent].left;
    if(T[T[u].parent].right != u && T[T[u].parent].right != NIL)
        return T[T[u].parent].right;
    return NIL;
}

void Print(int u){
    printf("node %d: ", u);
    printf("parent = %d, ", T[u].parent);
    printf("sibling = %d, ",GetSibling(u));
    int deg = 0;
    if(T[u].left != NIL) deg ++;
    if(T[u].right != NIL) deg ++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[u]);
    printf("height = %d, ", H[u]);

    if(T[u].parent == NIL){
        printf("root\n");
    }else if(T[u].left == NIL && T[u].right == NIL){
        printf("leaf\n");
    }else printf("internal node\n");
    }

int main()[
    int v, l, r, root = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i ++) T[i].parent = NIL;

    for(int i = 0; i < n; i ++){
    scanf("%d %d %d", &v, &l, &r);  
    T[v].left = l;
    T[v].right = r;
    if(l != NIL) T[l].parent = v;
    if(r != NIL) T[r].parent = v;
    }
    
    for(int i = 0; i < n; i ++) if(T[i].parent == NIL) root = i;

    SetDepth(root, 0);
    SetHeight(root);

    for(int i = 0; i < n; i ++) Print(i);

    return 0;
]