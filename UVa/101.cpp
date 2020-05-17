#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define toDigit(c) (c - '0')

#define MAX 25

// Vamos fazer as EDs abaixo globais, para uma manipulação mais organizada nos métodos.
int positions[MAX]; // Array que vai armazenar as posições de cada bloco, para diminuir as buscas
stack<int> blocks[MAX], tmp; // Pilhas: de blocos e temporária.

void initialize_blocks(int n) { // Inicializa os n blocos em seus devidos lugares
	for(int i = 0; i < n; i++) {
		blocks[i].push(i);
		positions[i] = i;
	}
}

void print_blocks(int n) { // Método para printar os blocos (também limpa todas as pilhas para o próximo uso)
	for(int i = 0; i < n; i++) {
		cout << i << ":"; // Printa a pilha de bloco inicial i
		if(blocks[i].empty()) cout << endl; // Se não houver blocos na pilha, vai para a próxima
		else { // Se houver:
			while(!blocks[i].empty()) { // Enquanto não houver mais blocos nesta pilha
				tmp.push(blocks[i].top()); // Coloca-os na pilha tmp
				blocks[i].pop();
			}
			while(!tmp.empty()) {
				cout << " " << tmp.top(); // Imprime o último elemento de tmp (que era o primeiro da pilha original)
				tmp.pop();
			}
			cout << endl;
		}
	}
}

void move_single(int a, int b) { // Método para mover um bloco a (do topo) para a pilha b
	blocks[positions[a]].pop(); // Retira a do topo de onde estava
	blocks[b].push(a); // Coloca a no topo da pilha b
	positions[a] = b; // Atualiza a posição de a
}

void clean_top(int a) { // Método para tirar todos os blocos acima de a
	while(blocks[positions[a]].top() != a) { // Vamos retirar o que está em cima de a
		int t = blocks[positions[a]].top(); // t é o último bloco da pilha que contém a
		move_single(t, t); // Move t para a sua pilha de origem t
	}
}

void lift_stack(int a) { // Método para levantar (colocar, em ordem inversa, na pilha tmp) "a" e tudo que está acima deste
	while(blocks[positions[a]].top() != a) { // Enquanto a não está no topo da pilha que o contém
		tmp.push(blocks[positions[a]].top()); // Coloca em tmp o que está no topo da pilha que contém a
		blocks[positions[a]].pop(); // Retira o que está no topo da pilha que contém a
	}
	tmp.push(a); // Coloca a em tmp
	blocks[positions[a]].pop(); // Retira a da pilha de onde estava
}

void drop_stack(int b) { // Coloca (em ordem inversa) tudo que está em tmp na pilha b
	while(!tmp.empty()) { // Enquanto tmp não estiver vazia
		blocks[positions[b]].push(tmp.top()); // Coloca o que está em cima de tmp na pilha que contém b
		positions[tmp.top()] = positions[b]; // Atualiza a posição do bloco movido de tmp
		tmp.pop(); // Retira o bloco de tmp
	}
}

void move_onto(int a, int b) {
	clean_top(a); // Limpa o que está acima de a
	clean_top(b); // Limpa o que está acima de b
	move_single(b, b); // Coloca b na sua pilha de origem b
	move_single(a, b); // Coloca a na pilha b
}

void move_over(int a, int b) {
	clean_top(a); // Limpa o que está acima de a
	move_single(a, positions[b]); // Move a para a pilha em que b está
}

void pile_onto(int a, int b) {
	clean_top(b); // Limpa o que está acima de b
	move_single(b, b); // Coloca b em sua pilha inicial
	lift_stack(a); // Levanta "a" com tudo que está acima
	drop_stack(b); // E coloca na pilha que contém b
}

void pile_over(int a, int b) {
	lift_stack(a); // Levanta "a" com tudo que está acima
	drop_stack(b); // E coloca na pilha que contém b
}

void process_input(char com_1_0) { // Processar entrada. Recebe o primeiro caractere da primeira parte do comando
	int a, b;
	char com_2[6];
	cin >> a >> com_2 >> b;
	if(a == b || positions[a] == positions[b]) return; // Comando ilegal, é apenas ignorado.
	if(com_1_0 == 'm') {
		if(com_2[1]=='n') move_onto(a,b);
		else move_over(a,b);
	} else {
		if(com_2[1]=='n') pile_onto(a,b);
		else pile_over(a,b);
	}
}

int main() {
	int n;
	while(cin >> n) {
		initialize_blocks(n);
		char com_1[6]; // Primeira parte do comando (move ou pile)
		while(cin >> com_1) {
			if(com_1[0] == 'q') break;
			process_input(com_1[0]);
		}
		print_blocks(n);
	}
}