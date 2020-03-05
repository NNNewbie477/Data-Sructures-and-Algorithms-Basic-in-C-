#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, b[1000];

void Push(int x){
	s[++top] = x;
}
void Pop(int x){
	top --;
	return s[top + 1];
}

int main(){
	int a, b;
	top = 0;
	char s[100];

	while(scanf("%s", s) != EOF){
		if(s[0] == '+'){
			a = Push();
			b = Pop();
			Push(a + b);
		}else if(s[0] == '-'){
			a = Pop();
			b = Pop();
			Push(a - b);
		}else if(s[0] == '*'){
			a = Pop();
			b = Pop();
			Push(a * b);
		}else {
			Push(atoi(s));
		}


		printf("%d\n", Pop());

		return 0;
	}