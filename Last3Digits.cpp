#include <iostream>
#include <string>
using namespace std;

//Digits Cropping
unsigned long long digitscropping(unsigned long long v)
{
	//Remove Zeros to improve the performance
	while ((v%10) == 0)
	{
		v =(v/10);
	}
	// Consider only last 10 digits as the early digits doesn't affect last three digits of factorial 
	return v%100000000000;
}


int main()
{
	//Input Value
	unsigned long long n;
	
	//Output Value
	unsigned long long factorial = 1;
	
	//Input
	cin >> n;
	// Find the factorial
	for (unsigned long long i = n; i >1; i--)
	{
		factorial *= i;

		//Crop the digits 
		factorial=digitscropping(factorial);
	}
	// Convert Integer to String 
	std::string output = std::to_string(factorial);
	
	//Check the size of the string 
	int inputSize = output.size();

	// Crop the Last 3 digits
	output = (inputSize > 3) ? output.substr(inputSize - 3) :output;
	
	//Output
	std::cout << output << std::endl;

	return 0;
}