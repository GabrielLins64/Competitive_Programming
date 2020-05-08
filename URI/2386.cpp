#include <stdio.h>

int main() {

	int A, F, percebidas = 0;
	scanf("%d", &A); // Abertura do telescópio
	scanf("%*s"); // ignora a segunda entrada
	while(scanf("%d", &F) != EOF) { // Pega as entradas até chegar no final do arquivo de input
		// OBS: a abertura da pupila não é considerada, portanto vamos considerar apenas
		// a qtd de fótons * abertura do telescópio. "Percebida pelo telescópio"
		if(F*A >= 40000000) percebidas++;
	}
	printf("%d\n", percebidas);

	return 0;
}