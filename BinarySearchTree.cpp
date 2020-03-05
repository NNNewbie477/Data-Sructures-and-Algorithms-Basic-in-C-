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

Node *TreeMinimum(Node *x){
    while(x->left != NIL) x = x->left;
    return x;
}

Node * find(Node *u, int k){
    while(u != NIL && k != u->key){
        if(k < u->key) u = u->left;
        else u = u->right;
    }
    return u;
}

Node * TreeSuccessor(Node *x){
    if(x->right != NIL) return TreeMinimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y ->parent;
    } 
    return y;

}

void TreeDelete(Node *z){
    Node *y;
    Node *x;
    
    if(z->left == NIL || z->right == NIL) y = z;
    else y = TreeSuccessor(z);

    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    if(x != NIL){
        x->parent = y->parent;
    }

    if(y->parent == NIL){
        root = x;
    }else {
        if(y == y->parent->left){
            y->parent->left = x;    
        }else{
            y->parent->right = x;
        }
    }
    if(y != z){
        z->key = y->key;
    }

    free(y);
}

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
        if(com[0] == 'f'){
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NIL) printf("yes\n");
            else printf("root\n");
        }
        else if(com == "insert"){
            scanf("%d", &x);
            Insert(x);
        }else if(com == "print"){
            Inorder(root);
            printf("\n");
            Preorder(root);
            printf("\n");
        }else if(com == "delete"){
            scanf("%d", &x);
            TreeDelete(find(root, x));
            }
    }

    return 0;
}