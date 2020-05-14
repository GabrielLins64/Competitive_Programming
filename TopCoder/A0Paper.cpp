#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A0Paper {
// Como cada posição do vetor, da ultima à primeira, pode ser representada como uma potência de 2
// podemos assumir que (da mesma forma que os binários) a soma de dois elementos i+1 serão sempre
// o elemento i. Portanto, para termos a soma dos elementos do vetor sendo maior que o valor
// desejado, a soma com certeza passou pelo valor desejado por uma potência de 2.
public:
	string canBuild(vector<int> A) {
		double sum = 0.0, weight = 1.0;
		for(auto i = A.begin(); i != A.end(); i++, weight /= 2.0) {
			for(; *i != 0; (*i)--) {
				sum += weight;
				if(sum == 1.0) return "Possible";
			}
		}
		return "Impossible";
	}
};

int main() {
	A0Paper test;
	vector<int> A = {2,0,0,0,0,0,0,3,2,0,0,5,0,3,0,0,1,0,0,0,5};
	cout << test.canBuild(A) << endl;
	return 0;
}