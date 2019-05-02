#include <iostream>
#include <string>

/*returns true if character represents a numerical digit*/
bool isAsciiDigit(char c){
	return ((int)c >= 48 && (int)c <= 57);
}

/*multiplies numbers present in a string*/
int multiply(std::string parse){
	int product = 1;
	std::string digit = ""; //stack of digits
	for (auto ch : parse) {
		if (isAsciiDigit(ch))
			digit += ch;
		else{ 
			/*converts string into integer*/
			product *= std::stoi(digit); 
			digit = "";
		}
	}
	/*multiplies last digit*/
	if (digit != "") product *= std::stoi(digit);
	if (product == 1) return 0;
	return product;
}

int main(){
	/*apply funciton to all problems*/
	std::cout << multiply("") << std::endl;
	std::cout << multiply("2 3") << std::endl;
	std::cout << multiply("4,6,5") << std::endl;
	std::cout << multiply("4/6/5") << std::endl;
	std::cout << multiply("100X3") << std::endl;
	return 0;
}