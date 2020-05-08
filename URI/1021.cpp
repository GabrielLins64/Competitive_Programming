#include <bits/stdc++.h>

using namespace std;

int main() {

	double vr; // Valor real
	scanf("%lf", &vr);
	int notas[6] = {100, 50, 20, 10, 5, 2}; // Valor das cédulas
	double moedas[6] = {100, 50, 25, 10, 5, 1}; // Valor dos centavos (em int para usar o operador %)
	int vr_notas = (int) vr; // Pega apenas o valor em cédulas do valor real
	int vr_moedas = (int) (100.0 * (vr - (double) vr_notas)); // Pega o valor inteiro de centavos
	printf("NOTAS:\n");
	for(int i = 0; i < 6; i++) {
		int nota = notas[i];
		printf("%d nota(s) de R$ %d.00\n", vr_notas/nota, nota);
		vr_notas %= nota;
	}
	vr_moedas += 100*vr_notas;
	printf("MOEDAS:\n");
	for(int i = 0; i < 6; i++) {
		int moeda = moedas[i];
		printf("%d moeda(s) de R$ %.2lf\n", vr_moedas/moeda, (double)moeda/100.0);
		vr_moedas %= moeda;
	}

	return 0;

}
