#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	int a, b, x;
	string s;

	while(cin >> s){
		if(s[0] == '+'){
			a = s.top(); s.pop();
			b = s.top(); s.pop();
			s.push(a + b);
		}
		else if(s[0] == '-'){
			a = s.top(); s.pop();
			b = s.top(); s.pop();
			s.push(a - b);
		}
		else if(s[0] == '*'){
			a = s.top(); s.pop();
			b = s.top(); s.pop();
			s.push(a * b);
		}
		else{
			s.push(atoi(s.c_str()));
		}
	}

	cout << s.top() <<end;

	
	return 0;
}