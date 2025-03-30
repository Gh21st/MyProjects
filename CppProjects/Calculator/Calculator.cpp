/*Calculator 
 *See README.md for more info 
 *Current Capabilities: reduction of algebraic expressions of form n : Q|[+,*,/,^]|[n,Q] 
 *Immediate Future: support for common constants (pi,e)
 *Sometime Future: support for parantheses 
 *Maybe Future: support for common functions (trig,log,ln) 
 */
 
#include <iostream> 
#include <string> 
#include <cmath>



//Function Decl 

long double Reducer(const std::string&);
long double NumFromString(const std::string&,int&); 


//Runner Code 
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




//Func Def 

//Function is designed to store little extra information 
//We reduce from left to right with ans being our final answer 
//Read a number
//Check if number is raised to a power
	//reduce the Q^Q situation to Q 
//Check if number is multiplied to another 
	//Check if that number is raised to a power 
		//reduce the Q^Q situation to Q 
	//Reduce the Q*Q situation to Q 
//Add Q to ans 
//Repeat until end of input

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
