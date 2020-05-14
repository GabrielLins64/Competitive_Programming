#include <iostream>
#include <string>

using namespace std;

class Substitute {
private:
	int result;
public:
	Substitute() {result = 0;} // construtor
	int getValue(string key, string code) {
		for(int i = 0; i < code.length(); i++) { // Anda pelo code
			size_t position = key.find(code[i]); // Armazena a posição do caractere code[i], se existir, na key
			// find returns: "The position of the first character of the first match."
			// size_t: Alias of one of the fundamental unsigned integer types. It is a type able to represent the size of any object in bytes.
			if(position != string::npos) { // Se o caractere code[i] estiver na key:
			// npos is a static member constant value with the greatest possible value for an element of type size_t.
				if(position == key.length()-1) result *= 10; // se for o último caractere, é decodificado como 0
				// Caso seja o primeiro número codificado, como é um inteiro, zero à esquerda é desconsiderado.
				// Caso não seja o primeiro, o número já decodificado é acrescido de um zero à direita (mult por 10).
				else {
					result *= 10; // É necessário ser antes, pois caso não tenha entrado no caso anterior,
					// precisa-se colocar o próximo digito à direita.
					result += position + 1; // Coloca a posição (no sistema de contagem 1-inicial) em result.
				}	
			}
		}
		return result;
	}
};

// int main() {
// 	Substitute sub;
// 	string keyTest = "CRYSTALBUM";
// 	string codeTest = "MMA";
// 	cout << sub.getValue(keyTest, codeTest) << endl;
// }