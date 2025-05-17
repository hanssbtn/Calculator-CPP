#include "Calculator.hpp"

double secant(double operand) {
    if (cos(operand) == 0) {
        std::string errorMessage = "DomainError: sec(";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + ") is not defined.\n";
        throw std::invalid_argument(errorMessage);
    }
    return 1 / cos(operand);
}

double cosecant(double angle){
    if (sin(angle) == 0) {
        std::string errorMessage = "DomainError: csc(";
        std::stringstream errorStringStream;
        errorStringStream << angle;
        errorMessage += errorStringStream.str() + ") is not defined.\n";
        throw std::invalid_argument(errorMessage);
    }
    return 1 / sin(angle);
}

double cotangent(double angle) {
    if (sin(angle) == 0) {
        std::string errorMessage = "DomainError: cot(";
        std::stringstream errorStringStream;
        errorStringStream << angle;
        errorMessage += errorStringStream.str() + ") is not defined.\n";
        throw std::invalid_argument(errorMessage);
    }
    return cos(angle) / sin(angle);
}

double arcsin(double operand) {
    if (operand > 1 || operand < -1) {
        std::string errorMessage = "DomainError: asin(";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + ") is not defined (-1 <= x <= 1).\n";
        throw std::invalid_argument(errorMessage);
    }
    return asin(operand);
}

double arccos(double operand){
    if (operand > 1 || operand < -1) {
        std::string errorMessage = "DomainError: acos(";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + ") is not defined (-1 <= x <= 1).\n";
        throw std::invalid_argument(errorMessage);
    }
    return acos(operand);
}

double arccosh(double operand) {
    if (operand < 1) {
        std::string errorMessage = "DomainError: acosh(";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + ") is not defined (x < 1).\n";
        throw std::invalid_argument(errorMessage);
    }
    return acosh(operand);
}

double tangent(double angle) {
    if (cos(angle) == 0) {
        std::string errorMessage = "DomainError: tan(";
        std::stringstream errorStringStream;
        errorStringStream << angle;
        errorMessage += errorStringStream.str() + ") is not defined.\n";
        throw std::invalid_argument(errorMessage);
    }
    return tan(angle);
}

double arctanh(double operand) {
    if (operand >= 1 || operand <= -1) {
        std::string errorMessage = "DomainError: atanh(";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + ") is not defined (-1 < x < 1).\n";
        throw std::invalid_argument(errorMessage);
    }
    return atanh(operand);
}

double squareRoot(double operand) {
    if (operand <= 0) {
        std::string errorMessage = "DomainError: Negative input given to sqrt function (found operand: ";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + " < 0).\n";
        throw std::invalid_argument(errorMessage);
    }
    return sqrt(operand);
}

double naturalLogarithm(double operand) {
    if (operand <= 0){
        std::string errorMessage = "DomainError: Input given is outside domain of ln (found operand: ";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + " < 0).\n";
        throw std::invalid_argument(errorMessage);
    }
    return log(operand);
}

double base2Logarithm(double operand) {
    if (operand <= 0){
        std::string errorMessage = "DomainError: Input given is outside domain of log2 (found operand: ";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + " < 0).\n";
        throw std::invalid_argument(errorMessage);
    }
    return log2(operand);   
}

double base10Logarithm(double operand){
    if (operand <= 0){
        std::string errorMessage = "DomainError: Input given is outside domain of log10 (found operand: ";
        std::stringstream errorStringStream;
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + " < 0).\n";
        throw std::invalid_argument(errorMessage);
    }
    return log10(operand);
}

double logarithm(double base, double power){
    if (power <= 0 || base == 1 || base <= 0) {
        std::string errorMessage = "DivisionByZeroError: Log_";
        std::stringstream errorStringStream;
        errorStringStream << power;
        errorMessage += errorStringStream.str() + "(";
        errorStringStream.clear();
        errorStringStream << base;
        errorMessage += errorStringStream.str() + ") is not defined. (base > 0, base != 1, power > 0).\n";
        throw std::invalid_argument(errorMessage);
    }
    return log2(power) / log2(base);
}

double factorial(double operand){
    // Check if the argument is negative / non integer. If yes, throw invalid_argument error.
    if (operand < 0) {
        throw std::invalid_argument("Math error: Negative input given to factorial function.");
    }
    if (operand != static_cast<uint64_t>(operand)) {
        throw std::invalid_argument("Math error: Non-integer input given to factorial function.");
    }

    // Convert the argument into a 64-bit unsigned integer.
    uint64_t inputParameter = static_cast<uint64_t>(operand);

    // Initialize variable to store result.
    double result = 1.0;
    for (; inputParameter > 1; inputParameter--) {
        // Compute the factorial by multiplying the result with the input parameter, and decrementing.
        // For example, 5 * 4 * 3 * 2 * 1.
        result *= inputParameter;

        // Check if the input overflows. If yes, throw error
        if (result == INFINITY) {
            throw std::overflow_error("Factorial result overflowed.");
        }
    }

    // Return the result of the factorial.
    return result;    
}

double add(double firstOperand, double secondOperand) {
    return firstOperand + secondOperand;
}

double subtract(double firstOperand, double secondOperand) {
    return firstOperand - secondOperand;
}

double multiply(double firstOperand, double secondOperand){
    return firstOperand * secondOperand;
}

double divide(double numerator, double denominator){
    if (denominator == 0) {
        std::string errorMessage = "DivisionByZeroError: Attempted to divide by 0 (found numerator: ";
        std::stringstream errorStringStream;
        errorStringStream << numerator;
        errorMessage += errorStringStream.str() + ").\n";
        throw std::invalid_argument(errorMessage);
    }
    return numerator / denominator;
}

double modulo(double operand, double divisor) {
    if (divisor == 0) {
        std::string errorMessage = "DomainError: ";
        std::stringstream errorStringStream;
        errorStringStream << divisor;
        errorMessage += errorStringStream.str() + " modulo ";
        errorStringStream.clear();
        errorStringStream << operand;
        errorMessage += errorStringStream.str() + " is not defined.\n";
        throw std::invalid_argument(errorMessage);
    }
    return std::fmod(operand, divisor);
}

double power(double base, double exponent){
    if (exponent == 0 || base == 1.0) return 1.0;
    if (base < 0 && exponent != static_cast<int64_t>(exponent)) {
        std::string errorMessage = "Math error: Negative base and non integer power given to exponent (^) operator (found base: ";
        std::stringstream errorStringStream;
        errorStringStream << base;
        errorMessage += errorStringStream.str() + ", exponent: ";
        errorStringStream.clear();
        errorStringStream << exponent;
        errorMessage += errorStringStream.str() + ").\n";
        throw std::invalid_argument(errorMessage);
    }
    return pow(base, exponent);
}

double negate(double number){
    return (double)-number;
}

// Initialize maps with the corresponding functions and operators. 
Calculator::Calculator() : numberOfLogsSaved(0), historyLog(LinkedList()), currentValue(0), unaryOperatorLookupTable({
    {"sec", secant}, {"csc", cosecant}, {"cosec", cosecant}, {"cot", cotangent}, {"sqrt", squareRoot}, 
    {"ln", naturalLogarithm}, {"log2", base2Logarithm}, {"log", base10Logarithm}, {"cbrt", cbrt}, {"abs", fabs}, 
    {"!", factorial}, {"exp", exp}, {"ceil", ceil}, {"floor", floor},{"sin", sin}, {"asin", arcsin}, 
    {"sinh", sinh}, {"asinh", asinh}, {"cos", cos}, {"acos", arccos}, {"cosh", cosh}, {"acosh", arccosh}, 
    {"tan", tangent}, {"atan", atan}, {"tanh", tanh}, {"atanh", arctanh}, {"round", round}, {"neg", negate}
}), binaryOperatorLookupTable({
    {"log_", logarithm}, {"+", add}, {"-", subtract}, {"*", multiply}, {"/", divide}, 
    {"%", modulo}, {"^", power}
}), operatorPrecedenceLookupTable({
    {"sqrt", 2}, {"ln", 2}, {"log2", 2}, {"log", 2}, {"!", 3}, {"exp", 2}, {"cbrt", 2}, 
    {"ceil", 2}, {"floor", 2}, {"sec", 2},{"sin", 2}, {"asin", 2}, {"sinh", 2}, {"asinh", 2}, 
    {"cos", 2}, {"acos", 2}, {"cosh", 2}, {"acosh", 2}, {"tan", 2}, {"atan", 2},{"tanh", 2}, 
    {"atanh", 2}, {"round", 2}, {"csc", 2}, {"cosec", 2}, {"cot", 2}, {"log_", 2}, {"+", 0}, 
    {"-", 0}, {"*", 1}, {"/", 1}, {"%", 1}, {"^", 2}, {"(", 4}, {"neg", 3}, {"abs", 2}
}), functionLookupTable({
    {"abs", 111}, {"asin", 1}, {"acos", 3}, {"atan", 5}, {"asinh", 7}, {"acosh", 9}, {"atanh", 11},
    {"cos", 13}, {"cosh", 15}, {"ceil", 17}, {"cbrt", 19}, {"cot", 21}, {"cosec", 23}, {"csc", 25},
    {"e", 272}, {"exp", 27}, 
    {"floor", 29},
    {"ln", 31}, {"log2", 33}, {"log", 35}, {"log_", 2}, 
    {"sin", 37}, {"sec", 39}, {"sinh", 41}, {"sqrt", 43},
    {"tan", 45}, {"tanh", 47}, 
    {"pi", 314}, {"phi", 1618},
    {"round", 49},
    {"+", 2}, {"-", 4}, {"*", 6}, {"/", 8}, {"%", 10}, {"^", 12}, {"neg", 51}, {"!", 53}, {")", 90}, {"(", 23}
}) {}


void Calculator::expect(char expectedCharacter, size_t expectedIndex){
    // Return early if the character at the expected index matches the expected character.
    if (this->userInput.at(expectedIndex) == expectedCharacter) return;
    
    // Initialize a string containing the error message.
    std::string errorMessage = "MathError: Missing token (expected ";
    errorMessage += expectedCharacter + ", got " + this->userInput.at(expectedIndex);
    errorMessage += ").\n";

    // Throw an invalid_argument error with the constructed error message.
    throw std::invalid_argument(errorMessage);
}

void Calculator::clearHistory(){
    // Reinitialize the linked list and reset the nodes. 
    // Clear input string.
    // Reset the number of logs saved and the value held to 0.
    this->numberOfLogsSaved = 0;
    this->userInput.clear();
    this->currentValue = 0;
    this->historyLog = LinkedList();
}

void Calculator::printHistory(){
    this->historyLog.traverseLinkedList();
}

void Calculator::getExpressionFromUser(){
    // Ask user for input, then store the value inside userInput.
    std::cout << "Insert expression: ";
    std::getline(std::cin, this->userInput);

    // Handle empty string expression.
    if (this->userInput.empty()) std::cout << "Cannot parse empty string. Would you like to try again?\n";
}

std::vector<std::string> Calculator::tokenizeExpression(){

    // Initialize vector of string objects to store all tokens.
    std::vector<std::string> tokens;

    // Initialize variable to store length of parsed number and store checkpoints.
    size_t checkpoint = 0;

    // Initialize variables to determine the state of the token generator.
    // Start of expression / after parsing operator -> negative sign.
    // After parsing number / Before left parentheses / after right parentheses / before / after functions -> subtraction operator. 
    bool isNegativeSign = true;

    // Declare string variable to temporarily hold parsed token.
    std::string token, substring;

    // Declare string variable to hold error messages.
    std::string errorMessage;

    // Declare string stream to convert number to string using .str() method.
    std::stringstream numberConverter;
    
    // Initialize variables to store number of parenthesis pairs.
    int64_t numberOfLeftBrackets = 0, numberOfRightBrackets = 0;
    size_t index = 0;

    // Iterate over the user expression and store parsed tokens into the vector. 
    for (; index < this->userInput.size(); index++){
        switch (this->userInput.at(index)) {
            case ' ':
                // Go to the next index if whitespace.
                continue;

            case '-':
                // Parse '-' operator / sign according to the state of the tokenizer.
                // Append the appropriate token to the string variable.
                if (isNegativeSign == false) {
                    token += '-';

                    // Update the state to true as '-' is an operator.
                    isNegativeSign = true;
                } else if (isNegativeSign == true){
                    token += "neg";
                }
                break;

            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': 
                checkpoint = index;
                token += this->parseNumberFromInputString(checkpoint, &index, errorMessage, numberConverter);
                isNegativeSign = false;
                break;

            case 'p': case 'e': case 'a': case 'c': case 'f': case 's': case 't': case 'r': case 'l':
                // Parse all non-single character operator.
                // Set a checkpoint at current index.
                checkpoint = index;
                
                // Iterate over the token and get the length of the character.
                while (index < this->userInput.size() && std::islower(this->userInput.at(index))) index++;

                // Create a substring to parse the token.
                substring = this->userInput.substr(checkpoint, index - checkpoint);

                // Handle case if token is "log2", "log10", or "log_".                    
                if (substring == "log" && (this->userInput.at(index) == '_' || this->userInput.at(index) == '2')) {
                    substring += this->userInput.at(index);
                    index++;
                }

                // Throw invalid_argument error if the substring is not a valid token. 
                if (this->functionLookupTable.find(substring) == this->functionLookupTable.end()) {
                    // Construct the error message.
                    errorMessage = "MathError: Unrecognized token " + substring;
                    errorMessage += " at index ";

                    // Convert the index to a string, and append to the error message.
                    numberConverter << index;
                    errorMessage += numberConverter.str() + ".\n"; 

                    // Throw invalid_argument error with the constructed error message.
                    throw std::invalid_argument(errorMessage);
                }
                
                // Handle case where token is "e", "pi", or "log_" using a switch statement.
                switch (this->functionLookupTable.at(substring)) {
                    case 272: case 314: case 1618:
                        // If the token is "e" or "pi", update the state of the tokenizer and break the statement.
                        isNegativeSign = false;
                        index--;
                        break;
                    case 2:
                        // If the token is "log_", break the statement.
                        index--;
                        break;

                    default:
                        try {
                            // Ignore all whitespaces after the index, check if there is a '('.
                            while (this->userInput.at(index) == ' ') index++;
                            expect('(', index);

                            // Decrement the index to not skip the '('.
                            index--;
                        } catch (std::out_of_range&) {
                            // Construct error message.
                            errorMessage = "MathError: Failed to parse " + substring;
                            errorMessage += "() at index ";

                            // Convert index to string, then append to the error message along with the token.
                            numberConverter << index;
                            errorMessage += numberConverter.str() + " (cannot find corresponding parenthesis).\n";

                            // Throw invalid_argument error with the constructed error message.
                            throw std::invalid_argument(errorMessage);                    
                        }
                        break;
                }

                // Append the token to the string variable.
                token += substring;
                break;
    
            case '/': case '+': case '^': case '*': case '!': case '%':
                // Parse all single character operators.
                token += this->userInput.at(index);
                isNegativeSign = true;
                break;

            case '(':
                // Check if there is already a token stored in the string variable.
                // If yes, push it into the vector and clear the string.
                // Append the token to the string variable.
                token += '(';

                // Increment the number of left brackets, update the state of the tokenizer, and break the statement.
                numberOfLeftBrackets++;
                isNegativeSign = true;
                break;

            case ')':
                // Append the token to the string variable.
                token += ")";

                // Increment the number of right brackets, update the state of the tokenizer, and break the statement.
                numberOfRightBrackets++;
                isNegativeSign = false;
                break;
            
            default:
                // Handle unrecognized token exception.
                // Initialize error message to display to the user.
                errorMessage = "MathError: Found unrecognized token at index ";

                // Convert index to string and append it to the error message string.
                numberConverter << index;
                errorMessage += numberConverter.str(); 

                // Tell the user the unrecognized token found. 
                errorMessage += " (found " + this->userInput.at(index);
                errorMessage += ").\n";

                // Throw an invalid_argument error with the constructed error message. 
                throw std::invalid_argument(errorMessage);
        }
        
        // Insert the token at the end of the vector.
        tokens.push_back(token);

        // Clear the string for reuse.
        token.clear();
    }

    // Handle no token expression.
    if (tokens.size() == 0){
        // Throw invalid_argument error with an appropriate error message. 
        throw std::invalid_argument("ParseError: Found 0 tokens to parse.\n");  
    }

    

    // Handle mismatching brackets exception.
    if (numberOfLeftBrackets != numberOfRightBrackets) {
        // Construct error message to display to the user.
        errorMessage = "MathError: Found mismatched brackets (found ";

        // Convert the difference between the number of bracket(s) to string and append it to the error message string.
        numberConverter << abs(numberOfLeftBrackets - numberOfRightBrackets);
        errorMessage += numberConverter.str() + " unmatched";

        // Customize error message string depending on which bracket(S) cannot be matched.
        (numberOfLeftBrackets > numberOfRightBrackets) ? errorMessage += " left bracket(s)).\n" : errorMessage += " right bracket(s)).\n"; 

        // Throw the error with the constructed error message. 
        throw std::invalid_argument(errorMessage);
    }

    // Return all tokens parsed.
    return tokens;
}

void Calculator::generatePostfixNotation(std::vector<std::string> tokens){
    // Loop over the token vector and proceed accordingly.
    for (size_t element = 0; element < tokens.size(); element++){
        if (std::isdigit(tokens[element][0]) || tokens[element][0] == '.') {
            this->outputQueue.push_back(tokens[element]);
            continue;
        }
        switch (this->functionLookupTable.at(tokens[element])) {
            case 272: case 314: case 1618:
                this->outputQueue.push_back(tokens[element]);
                continue;

            case 90:
                while(!this->operatorStack.empty() && this->operatorStack.top() != "(") {
                    this->outputQueue.push_back(this->operatorStack.top());
                    this->operatorStack.pop();
                }
                if (!this->operatorStack.empty() && this->operatorStack.top() == "("){
                    this->operatorStack.pop();
                } else {
                    throw std::invalid_argument("MathError: Failed to find parenthesis pair.\n");
                }
                break;
            
            case 23:
                this->operatorStack.push(tokens[element]);
                break;

            default:
                while (!this->operatorStack.empty() && this->operatorStack.top() != "(" && this->operatorPrecedenceLookupTable.at(this->operatorStack.top()) >= this->operatorPrecedenceLookupTable.at(tokens[element])) {
                    this->outputQueue.push_back(this->operatorStack.top());
                    this->operatorStack.pop();
                }
                this->operatorStack.push(tokens[element]);
                break;
        }
    }

    while (!this->operatorStack.empty()) {
        if (this->operatorStack.top() == "(" || this->operatorStack.top() == ")") {
            throw std::invalid_argument("MathError: Failed to find parenthesis pair when clearing stack.\n");
        }
        this->outputQueue.push_back(this->operatorStack.top());
        this->operatorStack.pop();
    }
}

void Calculator::evaluatePostfixNotation(){
    // Parse the input string and generate the postfix notation.
    // Assign the postfixNotation to outputQueue.
    std::vector<std::string> tokens = this->tokenizeExpression();
    this->generatePostfixNotation(tokens);

    // Declare variable to store operands and current result.
    double result = 0; 
    std::string firstOperand, secondOperand;

    // Declare lambda variable to check if number is close to 0.
    auto isZero = [](double number) {
        return fabs(number) < 0.0000000000001;
    };

    // Declare string stream variable to convert number to string.
    std::stringstream numberConverter;

    // Loop over outputQueue and evaluate the expression.
    std::cout << "Calculating...\n";
    for (auto &token : this->outputQueue){
        // If the token is a number, push them into the stack.
        if (token[0] == '.' || std::isdigit(token[0])) {; 
            this->operatorStack.push(token);
            continue;
        }

        this->functionLookupTable.at(token);

        switch (this->functionLookupTable.at(token)) {
            // If the token is a special constant (e, pi, phi), push them into the stack.
            case 272:
                this->operatorStack.push("2.718281828459045235360287471352662498L");
                continue;
            case 314:
                this->operatorStack.push("3.141592653589793238462643383279502884L");
                continue;
            case 1618:
                this->operatorStack.push("1.618033988749894848204586834365638118L");
                continue;

            default:
                // If the number assigned is odd, search the unary operator table.
                // Else, search the binary operator table.
                if (this->functionLookupTable.at(token) & 1){
                    // Throw error if there is an excess operand.
                    if (this->operatorStack.empty()) throw std::invalid_argument("EvalError: Found excess operator(s).\n");

                    // Convert the number string to a double, then call the function on the number.
                    result = this->unaryOperatorLookupTable.at(token)(std::stod(this->operatorStack.top()));
                    numberConverter << result;
                    
                    // Convert the result to a string and push to the stack.
                    // Pop the stack after calculating the result.
                    this->operatorStack.pop();

                    // Check if the result is close to 0, if yes, push 0 instead.
                    (!isZero(result)) ? this->operatorStack.push(numberConverter.str()) : this->operatorStack.push("0");
                } else {
                    // Throw error if there is an excess operand.
                    if (this->operatorStack.empty()) {
                        std::string errorMessage = "EvalError: Found excess operator(s) (found " + token;
                        errorMessage += ").\n"; 
                        throw std::invalid_argument(errorMessage);
                    }

                    // Assign the first number to a string variable and pop the stack.
                    secondOperand = this->operatorStack.top();
                    this->operatorStack.pop();

                    // Throw error if there is not enough arguments.
                    if (this->operatorStack.empty()) {
                        std::string errorMessage = "EvalError: Failed to find second argument for " + token;
                        errorMessage += ".\n"; 
                        throw std::invalid_argument(errorMessage);
                    }

                    // Assign the second number to a string variable and pop the stack.
                    firstOperand = this->operatorStack.top();
                    this->operatorStack.pop();
                    
                    // Convert the number string to a double, then call the function on the numbers.
                    result = this->binaryOperatorLookupTable.at(token)(std::stod(firstOperand), std::stod(secondOperand));
                    
                    // Convert the result to a string, and push it to the stack.
                    numberConverter << result;

                    // Check if the result is close to 0, if yes, push 0 instead.
                    (!isZero(result)) ? this->operatorStack.push(numberConverter.str()) : this->operatorStack.push("0");

                    // Clear the string variables for later use.
                    firstOperand.clear();
                    secondOperand.clear();
                }                

                // Clear the string stream for later use.
                numberConverter.clear();
                numberConverter.str("");
                break;
        }
    }

    this->currentValue = std::stod(this->operatorStack.top());
    
    // Output the evaluated value.
    std::cout << "Result: " << this->currentValue << '\n';

    // Handle not enough memory exception. 
    if (!historyLog.insertNode(this->userInput, this->currentValue)) throw std::runtime_error("Failed to allocate node.\n");

    // Increment the number of logs saved.
    this->numberOfLogsSaved++;

    // Call reset() to reinitialize the member attributes required for calculations.
    this->reset();
    return;
}

bool Calculator::undoOperation(){
    // Check if there are any saved logs. If no, return false.
    if (this->numberOfLogsSaved == 0) return false;

    // Change the current value to the previous value.
    this->currentValue = this->historyLog.getTailNode().result;

    this->numberOfLogsSaved--;
    // Delete the last node on the linked list and return true;
    this->historyLog.deleteTailNode();
    return true;
}

std::string Calculator::parseNumberFromInputString(const size_t start, size_t* index, std::string& errorMessage, std::stringstream& numberConverter){
    // Set a checkpoint at the starting index.
    size_t length = start;
    
    // Get the first decimal digits before the exponent / floating point.
    while (length < this->userInput.size() && std::isdigit(this->userInput.at(length))) length++;
    
    // Handle all valid number formats.
    // Case 1: no exponent / no floating point.
    // Case 2: no exponent with floating point.
    // Case 3: exponent without floating point.
    // Case 4: exponent with floating point.
    // Case 5: only floating point.
    // Check if the end of the string has been reached.
    if (length < this->userInput.size()) { 
        // If not, check if the number has a floating point and / or exponent.
        if (this->userInput.at(length) == '.') {
            // Increment length, and floating point number.
            length++;

            // If there is no digit after floating point, throw invalid_argument error.
            if (length >= this->userInput.size() || !std::isdigit(this->userInput.at(length))) {
                // Construct the error message.
                errorMessage = "MathError: Failed to parse number at index ";

                // Convert starting index to a string, and append at the error message.
                numberConverter << start;
                errorMessage += numberConverter.str() + "(found floating point without proceeding digit(s)).\n";

                // Throw invalid_argument error with the constructed error message.
                throw std::invalid_argument(errorMessage);
            }
            // Parse the numbers after the floating point.
            while (length < this->userInput.size() && std::isdigit(this->userInput.at(length))) length++;

            // If there is another floating point, throw invalid_argument error.
            if (length < this->userInput.size() && this->userInput.at(length) == '.') {
                // Construct the error message.
                errorMessage = "MathError: Failed to parse number at index ";
                
                // Convert starting index to a string, and append at the error message.
                numberConverter << start;
                errorMessage += numberConverter.str() + "(found extra floating point).\n";
                
                // Throw invalid_argument error with the constructed error message.
                throw std::invalid_argument(errorMessage);
            }
        }

        // Handle case where the number has an exponent.
        if (length < this->userInput.size() && this->userInput.at(length) == 'e') {
            // Increment length, then parse the exponent.
            length++;

            // If there is no digit after floating point, throw invalid_argument error.
            if (length >= this->userInput.size() || !(std::isdigit(this->userInput.at(length)) || this->userInput.at(length) == '-' || this->userInput.at(length) == '+')) {
                // Construct the error message.
                errorMessage = "MathError: Failed to parse number at index ";

                // Convert starting index to a string, and append at the error message.
                numberConverter << start;
                errorMessage += numberConverter.str() + "(found exponent symbol without proceeding digit(s)).\n";
                
                // Throw invalid_argument error with the constructed error message.
                throw std::invalid_argument(errorMessage);
            }

            // Increment length if there is a preceding '-' or '+' sign.
            if (this->userInput.at(length) == '-' || this->userInput.at(length) == '+') length++;

            // If there is no digit after '+' or '-' sign, throw invalid_argument error. 
            if (length >= this->userInput.size()) {
                errorMessage = "MathError: Failed to parse number at index ";
                numberConverter << start;
                errorMessage += numberConverter.str() + "(found +- sign without proceeding digit(s)).\n";
                throw std::invalid_argument(errorMessage);
            }

            // Parse the exponent.
            while (length < this->userInput.size() && std::isdigit(this->userInput.at(length))) length++;
        } 
    }        

    // Decrement the length of the parsed string.
    // Update the index to the next character on the string.
    *index = length - 1;

    // Return the parsed number.
    return this->userInput.substr(start, length - start);
}

void Calculator::reset(){
    // Reset the output queue, user input string, and operator stack variables.
    this->outputQueue.clear();
    std::stack<std::string> empty;
    this->operatorStack = empty;
}

double Calculator::getCurrentValue(){
    // Return the current value held.
    if (this->numberOfLogsSaved != 0) return this->currentValue;
    return NAN;
}

Calculator::~Calculator() {
    // Call the destructor for the LinkedLIst object.
    historyLog.~LinkedList();
}