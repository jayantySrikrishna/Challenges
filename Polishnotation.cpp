#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include <algorithm>
#include <sstream>

using namespace std;

//Converts String to Intger
int stringtoint(const string& a)
{
	std::istringstream ss(a);

	int k;
	ss >> k;
	return k;
}

// Check if the Value stored in the string is a number
bool is_number(const std::string& s)
{
	bool check = false;
	if (!s.empty())
	{
		//Checks if there is any arthimetic before the value and checks for number after removing the arithmetic
		if ((s[0] == '-' || s[0] == '+') && s.size() > 1)
		{
			check = std::find_if(s.begin() + 1, s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
		}
		else
		{
			check = std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
		}
	}
	return check;
}


//Moves Stack Elements into A Vector
void moveStackToVector(stack<string>& input, vector<string>& output)
{

	while (!input.empty())
	{
		output.push_back(input.top());
		input.pop();
	}
}

//Checks if the previous two values stored in the vector are integers
auto check_integer = [](vector<bool>& is_int) {
	int&& size_int = is_int.size();
	if (size_int > 1)
	{
		return (is_int.at(size_int - 1) == true && is_int.at(size_int - 2) == true);
	}

	return false;
};

const vector<string> evaluate_polish_notation(vector<string>& notation)
{
	stack<string> input_string;//Input String in a stack
	vector<bool> is_integer;//Vector to Store the Type of the Stack elements

	//Loop through the String
	for (auto a : notation)
	{

		// check if it is an operator
		if (!is_number(a) && check_integer(is_integer))
		{

			// if it is operator, pop 2 times, then perform appropriate operation
			int num2 = stringtoint(input_string.top());
			input_string.pop();

			is_integer.pop_back();
			int num1 = stringtoint(input_string.top());
			input_string.pop();
			is_integer.pop_back();
			switch (a[0])
			{
			case '+':
				input_string.push(std::to_string(num1 + num2));
				is_integer.push_back(true);
				break;
			case '-':
				input_string.push(std::to_string(num2 - num1));
				is_integer.push_back(true);
				break;
			case '*':

				input_string.push(std::to_string(num1 * num2));
				is_integer.push_back(true);
				break;
			default:
				input_string.push(std::to_string(num1));
				is_integer.push_back(true);
				input_string.push(std::to_string(num2));
				is_integer.push_back(true);
				input_string.push(a);
				is_integer.push_back(false);
				break;

			}

		}
		else
		{  // if it number, push it to stack
			if (is_number(a)) {
				input_string.push(a);
				is_integer.push_back(true);//Integer
			}
			else {
				input_string.push(a);
				is_integer.push_back(false);//Not an Integer
			}
		}

	}
	//Vector to Store Output String
	vector<string> Vector_string;
	moveStackToVector(input_string, Vector_string);
	return Vector_string;
}

int main()
{
	// Case numbers count
	int case_number = 1;

	//String to store line 
	std::string source;

	while (std::getline(cin, source))
	{
		//Return if  empty
		if (source.empty()) { break; }

		//Stores the Complete String in a vector
		vector<string> complete_input;

		stringstream each_input(source);
		// Capture space separated strings into a vector
		while (std::getline(each_input, source, ' ')) {

			complete_input.push_back(source);
		}

		//Reverse the Entire String to capture integers before arithmetic operations 
		std::reverse(complete_input.begin(), complete_input.end());

		//Simplifying Polish Notation
		const vector<string>& output_string = evaluate_polish_notation(complete_input);

		//Displaying Output

		std::cout << "Case " << std::to_string(case_number) << ": ";

		for (int f = 0; f != output_string.size(); ++f)
		{
			std::cout << output_string.at(f) << " ";
		}

		std::cout << std::endl;

		case_number++;
	}


}