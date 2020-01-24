#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ERROR_CODE ((double)98245.1653)

// prototype add, subtract, multiply, and divide functions
double add(double firstNumber, double secondNumber);
double subtract(double firstNumber, double secondNumber);
double multiply(double firstNumber, double secondNumber);
double divide(double firstNumber, double secondNumber);

int main(void)
{
	double(*mathFun_ptr)(double x, double y);  // declare function pointer that accepts two doubles as arguments
	double num1 = 0;  // initialize the first number that will be entered by user to 0
	char mathOperator = 0;  // initialize the mathOperator
	double num2 = 0;  // initialize the second number that will be entered by user to 0
	double returnValue = 0;  // initialize the returnValue to 0
	
	// flush all of the input buffer so no erroneous characters will be part of the input
	int c = getchar();  // random variable declared to be a placeholder for any erroneous characters in the input buffer to be processed
	while (c != '\n' && c != '\r' && c != EOF){c = getchar();}
	
	// prompt the user for a mathematical expression to be evaluated
	printf("Enter two ints and/or doubles separated by a math operator\n");
	printf("e.g., 1.2 + 3.4, 5.6 - 7.8, 9.10 * 2.3, 4.5 / 6.7\n");
	scanf("%lf %c %lf", &num1, &mathOperator, &num2);
	
	// point the math function pointer to the memory address of the respective function based on the operator that was entered by user 
	if (mathOperator == '+')
	{
		mathFun_ptr = &add;
	}
	else if (mathOperator == '-')
	{
		mathFun_ptr = &subtract;
	}
	else if (mathOperator == '*')
	{
		mathFun_ptr = &multiply;
	}
	else if (mathOperator == '/')
	{
		mathFun_ptr = &divide;
	}
	else
	{
		puts("Something went wrong!"); // default statement will be output to screen if the math operator doesn't match any of the above
		return -1;
	}

	// if mathFun_ptr exists (not NULL), call the math function pointer with the two number arguments and print out the result
	if (mathFun_ptr)
	{
		returnValue = mathFun_ptr(num1, num2);
		printf("The result is:\t%lf\n", returnValue);
	}
	else
	{
		puts("Something went wrong!");
		return -1;
	}
	return 0;
}

// add function returns a double and accepts two doubles as arguments to add together
double add(double firstNumber, double secondNumber)
{
	return firstNumber + secondNumber;
}

// subtract function returns a double and accepts two doubles as arguments to subtract
double subtract(double firstNumber, double secondNumber)
{
	return firstNumber - secondNumber;
}

// multiply function returns a double and accepts two doubles as arguments to multiply together
double multiply(double firstNumber, double secondNumber)
{
	return firstNumber * secondNumber;
}

// divide function returns a double and accepts two doubles as arguments to divide
double divide(double firstNumber, double secondNumber)
{
	if (secondNumber)
	{
		return firstNumber / secondNumber;
	}
	else
	{
		return ERROR_CODE;
	}
}