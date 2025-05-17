#include "Calculator.hpp"

#include <iostream>

using namespace std;

int main(void){
    // Create calculator object.
    Calculator calculator;

    // Declare variable to store user command.
    int command;

    // Greet the user.
    cout << "Welcome\n";

    while(1) {
        // Print currently held value if there is a number.
        if (std::isnan(calculator.getCurrentValue())) cout << "Options:\n0: Insert expression\n1: Print history\n2: Undo operation\n3: Clear history\n9: Quit\nInsert command: ";
        else cout << "Options:\n0: Insert expression\n1: Print history\n2: Undo operation\n3: Clear history\n9: Quit\nCurrent value: " << calculator.getCurrentValue() << "\nInsert command: ";

        // Ask for input and handle invalid command.
        if (!(cin >> command)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid command (Not a number). Insert 9 to quit.\nInsert command: ";
            while (!(cin >> command)) {
                cout << "Invalid command (Not a number). Insert 9 to quit.\nInsert command: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (command == 9) return 0;
        }
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        switch (command) {
            case 0:
                try {
                    calculator.getExpressionFromUser();
                    calculator.evaluatePostfixNotation();
                } catch (std::runtime_error &r) {
                    cout << "Got " << r.what();
                } catch (std::invalid_argument &e) {
                    cout << "Got " << e.what();
                    calculator.reset();
                }
                break;
                
            case 1: 
                if (calculator.numberOfLogsSaved == 0) {
                    cout << "No logs saved.\n";
                    break;
                }
                cout << "Total logs: " << calculator.numberOfLogsSaved << '\n';
                calculator.printHistory();

                break;

            case 2:
                if (!calculator.undoOperation()) {
                    cout << "Failed to undo operation (No logs saved).\n";
                }
                break;

            case 3: 
                cout << "Cleared history.\n";
                calculator.clearHistory();
                break;
            
            case 9:
                return 0;

            default:
                cout << "Invalid command (Not a number). Insert 9 to quit.\nInsert command: ";
                while (!(cin >> command)) {
                    cout << "Invalid command (Not a number). Insert 9 to quit.\nInsert command: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                if (command == 9) return 0;
                break;
        }

    }    
}