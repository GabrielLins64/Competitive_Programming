#include <bits/stdc++.h>

int main() {
	int R1, X1, Y1, R2, X2, Y2;
	while(scanf("%d %d %d %d %d %d", &R1, &X1, &Y1, &R2, &X2, &Y2) != EOF) {
		double distancia = sqrt(pow(Y1-Y2, 2) + pow(X1-X2, 2)); // Calcula a distância entre os centros
		if(R1 >= distancia + R2) printf("RICO\n"); // O Círculo inclui a flor se seu raio for maior que
												   // a distância entre os centros + o raio da flor.
		else printf("MORTO\n");
	}
	return 0;
}