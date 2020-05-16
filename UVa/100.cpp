#include <iostream>

using namespace std;

// Para pegar um input de um arquivo e testá-lo no seu programa, primeiro
// crie um executável, ex: g++ 100.cpp -o main
// depois utilize: ./main < input_file > output_file
// input_file é um arquivo de texto com os inputs, e output_file será gerado
// com os outputs do seu programa.

int collatz_next(int x) { // Calcula o próximo número da sequência de Collatz, dado x.
	if(x % 2 == 0) return x/2; // Se x for par
	else return 3*x + 1; // Se x for ímpar
}

int lenght(int x) { // Calcula o tamanho da sequência de Collatz de x.
	int counter; // Contador, para o tamanho da sequência.
	for(counter = 1; x != 1; counter++, x = collatz_next(x));
	return counter;
}

int max(int a, int b) {
	if(a>b) return a;
	else return b;
}

int min(int a,int b) {
	if(a<b) return a;
	else return b;
}

int main() {
	int i, j, bigger = 1;
	while(cin >> i >> j) {
		for(int x = min(i, j); x <= max(i, j); x++) {
			int l = lenght(x);
			if(l > bigger) bigger = l;
		}
		cout << i << " " << j << " " << bigger << endl;
		bigger = 1;
	}
}