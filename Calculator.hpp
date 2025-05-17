#ifndef __CALCULATOR
#define __CALCULATOR

#include "LinkedList.hpp"
#include <stack>
#include <stdexcept>
#include <iostream>

class Calculator {
    public: 
        /// @brief Total number of all logs saved.
        uint64_t numberOfLogsSaved;

    private:
        /// @brief A log containing all previously saved user input with the value.
        LinkedList historyLog;
    
        /// @brief Current value stored.
        double currentValue;

        /// @brief Newest user input to be processed.
        std::string userInput;

        /// @brief A lookup table for all functions / operators taking a single parameter.
        /// Maps strings denoting a function / operator to a function pointer using a custom hash function. 
        std::unordered_map<std::string, std::function<double(double)>> unaryOperatorLookupTable;

        /// @brief A lookup table for all functions / operators taking two parameters.
        /// Maps strings denoting a function / operator to a function pointer using a custom hash function.
        const std::unordered_map<std::string, std::function<double(double, double)>> binaryOperatorLookupTable;

        /// @brief A lookup table containing the precedence of all operators and functions.
        /// Maps strings of function names to their assigned precedence order. 
        const std::unordered_map<std::string, int> operatorPrecedenceLookupTable;

        /// @brief A lookup table for looking up function names. 
        std::unordered_map<std::string, int> functionLookupTable;

        /// @brief A stack containing all parsed operators to be consumed.
        /// Operators are ordered from lowest to highest precedence.
        std::stack<std::string> operatorStack;

        /// @brief A vector containing all parsed numbers to be consumed.
        /// Numbers are ordered from lowest to highest precedence.
        std::vector<std::string> outputQueue;
        
        /// @brief Private method for parsing numbers from the given substring.
        /// @param start Starting index of the number.
        /// @param index Pointer to the current index to update.
        /// @param errorMessage Reference to a string containing an error message.
        /// @param numberConverter Reference to a stringstream object for converting an index to a number.
        /// @returns Parsed number in the form of a string.
        /// @throws invalid_argument error if the string cannot be parsed as a number.
        /// Examples:
        /// 100000.00 (valid).
        /// -1.2e+1 (valid). 
        /// 1e3 (valid).
        /// -9.20e-3 (valid).
        /// 1..0 (invalid).
        /// 1.-2 (invalid).
        /// 2ee2 (invalid).
        /// 223,3 (invalid).
        /// 23.a (invalid).
        /// 2e(-12) (invalid). 
        /// 23e12e (will be parsed as 23e12).
        std::string parseNumberFromInputString(const size_t start, size_t* index, std::string& errorMessage, std::stringstream& numberConverter);

        /// @brief Private method for checking the validity of a given input string by probing for the expected character.
        /// @param expectedCharacter Character to expect.
        /// @param expectedIndex Index of expected character.
        /// @throws invalid_argument error if the expected character is not found.
        void expect(char expectedCharacter, size_t expectedIndex);

        /// @brief Private method for getting all tokens in a given expression.
        /// @returns Vector containing all parsed tokens.
        std::vector<std::string> tokenizeExpression();

        /// @brief Private method for generating postfix expression from user input.
        /// @param tokens A vector containing all parsed tokens.
        /// @throws invalid_argument error if the postfix notation cannot be generated.
        void generatePostfixNotation(std::vector<std::string> tokens);

    public:

        /// @brief Constructor for the calculator class.
        Calculator();

        /// @brief Method for evaluating the generated postfix notation.
        /// @throws invalid_argument error if the expression cannot be evaluated.
        void evaluatePostfixNotation();

        /// @brief Method for querying the user for an input string.
        void getExpressionFromUser();

        /// @brief Method for printing user history.
        void printHistory();

        /// @brief Method for undoing an evaluation.
        /// @returns true if the undo action is successful. Returns false otherwise. 
        bool undoOperation();

        /// @brief Method for clearing all saved user logs.
        void clearHistory();

        /// @brief Destructor for the calculator class.
        ~Calculator();

        /// @brief Method for accessing the current value.
        double getCurrentValue();  
};

/// @brief Function for calculating the factorial of a number.
/// @param operand Input operand.
/// @return (operand)! if param is an integer.
/// @throws invalid_argument error if operand < 0 or operand is not an integer.
double factorial(double operand);

/// @brief Function for calculating the square root of a number
/// @param operand Input operand. 
/// @return sqrt(operand) if operand >= 0;
/// @throws invalid_argument error if operand < 0.
double squareRoot(double operand);

/// @brief Function for calculating tangent of an angle in radian(s).
/// @param angle Input angle.
/// @return tan(angle) if cos(angle) != 0.
/// @throws invalid_argument error if cos(angle) == 0.
double tangent(double angle);

/// @brief Function for calculating the secant of an angle in radian(s).
/// @param angle Input angle.
/// @return sec(angle) if cos(angle) != 0._M_checknum
/// @throws invalid_argument error if cos(angle) == 0.
double secant(double angle);

/// @brief Function for calculating the cosecant of an angle in radian(s).
/// @param angle Input angle.
/// @return csc(angle) if sin(angle) != 0.
/// @throws invalid_argument error if sin(angle) == 0.
double cosecant(double angle);

/// @brief Function for calculating the cotanget of an angle in radian(s).
/// @param angle Input angle.
/// @return cot(angle) if sin(angle) != 0.
/// @throws invalid_argument error if sin(angle) == 0.
double cotangent(double angle);

/// @brief Function for calculating arcsine of a number.
/// @param operand Input operand.
/// @return asin(operand) if -1 <= operand <= 1.
/// @throws invalid_argument error if operand > 1 or operand < -1.
double arcsin(double operand);

/// @brief Function for calculating arccos of a number.
/// @param operand Input operand.
/// @return acos(operand) if -1 <= operand <= 1;
/// @throws invalid_argument error if operand > 1 or operand < -1.
double arccos(double operand);

/// @brief Function for calculating hyperbolic arccos of a number
/// @param operand Input operand.
/// @return acosh(operand) if operand >= 1.
/// @throws invalid_argument error if operand < 1. 
double arccosh(double operand);

/// @brief Function for calculating hyperbolic arctan of a number.
/// @param operand Input operand.
/// @return atanh(operand) if -1 < operand < 1.
/// @throws invalid_argument error if operand >= 1 or operand =< -1.
double arctanh(double operand);

/// @brief Function for calculating the natural logarithm fo a number. 
/// @param operand Input operand.
/// @return ln(operand) if operand > 0.
/// @throws invalid_argument error if operand <= 0.
double naturalLogarithm(double operand);

/// @brief Function for calculating base 2 logarithm of a number. 
/// @param operand Input operand.
/// @return log2(operand) if operand > 0.
/// @throws invalid_argument error if operand <= 0.
double base2Logarithm(double operand);

/// @brief Function for calculating base 10 logarithm of a number. 
/// @param operand Input operand.
/// @return log10(operand) if operand > 0.
/// @throws invalid_argument error if operand <= 0.
double base10Logarithm(double operand);

/// @brief Function for calculating logarithm of a number with a specified base.
/// Formula = log_base(operand) = log2(operand)/log2(base)
/// @param base Specified logarithm base.
/// @param operand Input operand.
/// @return log_base(operand) if base > 0, base != 1, and operand > 0.
/// @throws invalid_argument error if base == 1 or base <= 0 or operand <= 0.  
double logarithm(double base, double operand);

/// @brief Function for calculating the result of raising a base by an exponent.
/// @param power Number to raise the base.
/// @param base Base operand.
/// @return base ^ power if base is > 0 or base < 0 and power is an integer.
/// @throws invalid_argument error if base is < 0 and power is not an integer.
double power(double power, double base);

/// @brief Function for adding two numbers.
/// @param firstOperand First operand.
/// @param secondOperand Second operand.
/// @return firstOperand + secondOperand.
double add(double firstOperand, double secondOperand);

/// @brief Function for subtracting two numbers.
/// @param firstOperand First operand.
/// @param secondOperand Second operand.
/// @return firstOperand - secondOperand.
double subtract(double firstOperand, double secondOperand);

/// @brief Function for multiplying two numbers.
/// @param firstOperand First operand.
/// @param secondOperand Second operand.
/// @return firstOperand * secondOperand.
double multiply(double firstOperand, double secondOperand);

/// @brief Function for dividing two operands.
/// @param denominator Divisor operand.
/// @param numerator Dividend operand.
/// @return numerator / denominator if denominator != 0.
/// @throws invalid_argument error if denominator == 0.
double divide(double denominator, double numerator);

/// @brief Function for finding the remainder between two operands.
/// @param divisor Divisor operand.
/// @param dividend Dividend operand.
/// @return dividend % divisor if divisor != 0.
/// @throws invalid_argument error if divisor == 0.
double modulo(double divisor, double dividend);

/// @brief Function for handling negative sign.
/// @param operand Input operand.
/// @returns -(operand).
double negate(double operand);

#endif