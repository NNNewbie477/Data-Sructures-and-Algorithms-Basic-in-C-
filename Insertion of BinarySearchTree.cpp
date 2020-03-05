#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

void Insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node*)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else {
            x = x->right;
        }
    }

    z->parent = y;
    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

void Inorder(Node *u){
    if(u == NIL) return;
    Inorder(u->left);
    printf(" %d", u->key);
    Inorder(u->right);
}

void Preorder(Node *u){
    if(u == NIL) return;
    printf(" %d", u->key);
    Preorder(u->left);
    Preorder(u->right);
}

int main(){
    int n, i, x;
    string com;
    scanf("%d", &n);

    for(i = 0; i < n; i ++){
        cin >> com;
        if(com == "insert"){
            scanf("%d", &x);
            Insert(x);
        }else if(com == "print"){
            Inorder(root);
            printf("\n");
            Preorder(root);
            printf("\n");
        }
    }

    return 0;
}