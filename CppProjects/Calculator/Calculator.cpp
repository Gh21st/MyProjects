#include <iostream> 
#include <string> 
#include <cmath>
//Make a function that can reduce any string expression of type 
//n = Q|[+,-,*,/,^]|[n,Q]
//Solving is weird because we have to observe PEMDAS 
//We will reduce the expression to ans from left to right while observing PEMDAS
//ans will be our final ans 
//To this end we must first solve the next term before adding it to ans 
//This will require 3 nested loops, add/subtract, mult/div, powers 
//NO PARANTHESES


long double Reducer(const std::string&);
long double NumFromString(const std::string&,int&); 

int main() {
	std::string input = "NOT EXIT";
	while (input != "EXIT") {
		std::cout << "Please input expression to reduce" << std::endl; 
		std::cin >> input;
	       	
		std::cout << "...\n...\n...\n"
			  << Reducer(input) << std::endl; 			
		std::cout << "EXIT?" << std::endl; 
		std::cin >> input; 		
	}
	return 0; 
}




//string is of form n = Q|[+,*,/,^]|[n|Q]
//Subtraction is represented as the addition of a negative : a - b = a + -b
long double Reducer(const std::string& input) {
	int len = input.length(); 
	long double ans = 0;  
	int index = 0; 
	while (index < len) {
		long double number = NumFromString(input,index); //This is what we are adding to ans  
		//This grabs the first number from the string 
		
		//We do this like so because I am dumb 
		while (input[index] == '^') { 
			index++; //We iterate past the operator  
			//This is our power layer 
			double numberPow = NumFromString(input,index); //This is what we are exponentiating to number  
			//No more layers so we start the result chain
			number = pow(number,numberPow);
			
			    	
		}
		while (input[index] == '*' || input[index] == '/') {
			bool multiplication = (input[index] == '*')? 1 : 0;
			index++; //We iterate past the operator 

			//This is our multiplication layer
			long double numberMult = NumFromString(input,index); //This is what we are multiplying to number 
			

			while (input[index] == '^') { 
				index++; //We iterate past the operator  
				//This is our power layer 
				double numberPow = NumFromString(input,index); //This is what we are exponentiating to numberMult  
				//No more layers so we start the result chain
				numberMult = pow(numberMult,numberPow);
			    	
			}
			
			if (multiplication) 
				number *= numberMult;
			else 
				number /= numberMult;	
		}
		ans += number;
		index++; //We iterate past the operator 
	}
	return ans; 
} 


long double NumFromString(const std::string& input,int& index) { 
	int stOfNum = index;
      	if (input[index] == '-') 
		index++; 	
	while ( (input[index] >= '0' && input[index] <= '9') || 
		(input[index] == '.' || input[index] == ',') ) {
		
		index++; 
	}
	 
	return std::stold( input.substr(stOfNum,index - stOfNum) );	
}
