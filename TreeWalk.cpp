#include <stdio.h>
#define MAX 10000
#define NIL -1

struct Node{int p, l, r;};
struct Node T[MAX];

int n;

void PreParse(int u){
    if(u == NIL) return;
    printf(" %d", u);
    PreParse(T[u].l);
    PreParse(T[u].r);
}

void InParse(int u){
    if(u == NIL) return;
    InParse(T[u].l);
    printf(" %d", u);
    InParse(T[u].r);
}

void PostParse(int u){
    if(u == NIL) return;
    PostParse(T[u].l);
    PostParse(T[u].r);
    printf(" %d", u);
}

int main(){
    int i, v, l, r, root;

    scanf("%d", &n);

    for(i = 0; i < n; i ++){
        T[i].p = NIL;
    }
    
    for(i = 0; i < n; i ++){
        scanf("%d %d %d", &v, &l, &r);
        T[v].l = l;
        T[v].r = r;
        if(l != NIL) T[l].p = v;
        if(r != NIL) T[r].p = v;
    }

    for(i = 0; i < n; i ++) if(T[i].p == NIL) root = i;

    printf("Preorder\n");
    PreParse(root);
    printf("\n");
    printf("Inoder\n");
    InParse(root);
    printf("\n");
    printf("Postorder\n");
    PostParse(root);
    printf("\n");

    return 0;
}
