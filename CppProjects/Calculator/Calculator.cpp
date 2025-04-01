/*Calculator 
 *See README.md for more info 
 *Current Capabilities: reduction of algebraic expressions with operators [+,*,/,^] (subtraction is the addition of a negative) 
 *Parantheses are supported, EXAMPLE: 2*(2+3-(5*9/(2+3)-2)+1)-(1+1)
 *NO WHITESPACE, DO NOT OMIT OPERATORS FOR PARANTHESES 
 */
 
#include <iostream> 
#include <string> 
#include <cmath> 


//Function Decl 
size_t EndOfExp(const std::string& input,size_t st); 
long double Reducer(const std::string& input,size_t& st,size_t en);
long double NumFromString(const std::string& input,size_t& st); 


//Runner Code 
int main() {
	std::string input = "NOT EXIT";
	size_t st, en; 
	while (input != "EXIT") {
		std::cout << "Please input expression to reduce" << std::endl; 
		std::cin >> input;
	       	st = 0;
		en = input.length();
		std::cout << "...\n...\n...\n"
			  << Reducer(input,st,en) << std::endl; 			
		std::cout << "EXIT?" << std::endl; 
		std::cin >> input; 		
	}
	return 0; 
}




//This is an attempt to redo Reducer() with added parantheses functionality 
//I will be using recursion, the aim is to eventually redesign this into dynamic looping  
long double Reducer(const std::string& input,size_t& st,size_t en) {
	
	long double ans = 0; 

	while (st < en) {
		if (input[st] == ')') 
			st++; //Pesky Parantheses 
		
		long double number = NumFromString(input,st);


		while (input[st] == '^') {
			st++; //Moving st past operator 
			long double numberPow = NumFromString(input,st);
			
			number = std::pow(number,numberPow);
		}

		while (input[st] == '*' || input[st] == '/') {
			bool isMult = (input[st] == '*')? true : false; 
			st++; //Moving st past operator
			long double numberMult = NumFromString(input,st);
			while (input[st] == '^') {
				st++; //Moving st past operator 
				long double numberPow = NumFromString(input,st);
				
				numberMult = std::pow(numberMult,numberPow);
			}
			if (isMult) 
				number *= numberMult;
			else 
				number /= numberMult;	
		}
		ans += number; 
		st++; //Moving st past operator 
	} 
	return ans; 
}


long double NumFromString(const std::string& input,size_t& st) { 
	size_t stOfNum = st; 
	size_t enOfNum; 
	if (input[stOfNum] == '(') {
		enOfNum = EndOfExp(input,st);
		st++;
		return Reducer(input,st,enOfNum);
	}
	if (input[st] == '-') 
		st++; 	
	while ( (input[st] >= '0' && input[st] <= '9') || 
		(input[st] == '.' || input[st] == ',') ) {		
		st++; 
	}
	
	
	return std::stold( input.substr(stOfNum,st - stOfNum) );	
}
size_t EndOfExp(const std::string& input,size_t st) {
	//We assume the expression doesn't have mismatched parantheses 
	
	int balance = 1; //The Difference between # of '(' and ')' 
	while (balance != 0) {
	       	st++;	
		if (input[st] == '(') {
			balance++;
		} else if (input[st] == ')') {
			balance--; 
		}
	}

	return st; 
}
