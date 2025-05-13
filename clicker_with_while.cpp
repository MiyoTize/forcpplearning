#include <iostream>
#include <string>

int main() {
	std::cout << "Heyo! Here Miyo Kislyy!";
	std::cout << "Do you want play in clicker? Y/n ";
	char a; // answer
	std::cin >> a;

	while(a = 'y') {
		int x = 0;
		char symbol;
		if(symbol == ' ') {
		++x;
		std::cout << x;
		};
	};
}
