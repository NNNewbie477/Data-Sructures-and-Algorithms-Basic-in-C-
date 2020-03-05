#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<double> V;

	V.push_back(0.1);
	V.push_back(0.2);
	V.push_back(0.3);

	V[2] = 0.4;

	print(V);

	V.insert(V.begin() + 2, 0.8);
	V.erase(V.begin + 1);

	
	return 0;
}