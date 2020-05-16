#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define toDigit(c) (c - '0')
#define toChar(i) ('0' + i)
#define notBinary(c) (c != '0' && c != '1')
#define encode(a,b,c) (toChar(toDigit(a)+toDigit(b)+toDigit(c)))

class BinaryCode {
private:
	string decode_(string message, string assumption) {
		string answer = assumption; // Se o primeiro dígito decodificado, 0 ou 1, 
		if(message.length()==1) {// Caso a mensagem só tenha 1 dígito
			if(notBinary(message[0])) return "NONE"; // Se não for binário (0 ou 1)
			else if(message==assumption) return message;
			else return "NONE";
		}
		answer.push_back(toChar(toDigit(message[0]) - toDigit(answer[0]))); // Q[0] = P[0] + P[1] <=> P[1] = Q[0] - P[0]
		// Se P[1] não for 0 ou 1, ou a soma dos dígitos da decoficação não for igual ao que veio na codificação,
		// então a decodificação está errada ou a mensagem é inválida*.
		// *É possível uma mensagem inválida, uma vez que uma decodificação pode ser obtida com a soma de dígitos que
		// não foram obtidas por uma codificação.
		if(notBinary(answer.back()) || message[0] != encode('0', answer[0], answer[1])) return "NONE";
		for(int i = 2; i < message.length(); i++) { // Q[n] = P[n-1] + P[n] + P[n+1] <=> P[n+1] = Q[n] - P[n] - P[n-1]
			answer.push_back(toChar(toDigit(message[i-1]) - toDigit(answer[i-1]) - toDigit(answer[i-2]))); // P[n] = Q[n-1] - P[n-1] - P[n-2]
			if(notBinary(answer.back()) || message[i-1] != encode(answer[i-2], answer[i-1], answer[i])) return "NONE";
		}
		if(notBinary(answer.back()) || message.back() != encode(answer.end()[-2], answer.back(), '0')) return "NONE";
		return answer;
	}
	vector<string> decryption;
public:
	vector<string> decode(string message) {
		decryption.push_back(decode_(message, "0"));
		decryption.push_back(decode_(message, "1"));
		return decryption;
	}
};

int main() {
	BinaryCode test;
	string message = "1";
	vector<string> ans = test.decode(message);
	cout << "{" << ans[0] << ", " << ans[1] << "}" << endl;
	return 0;
}