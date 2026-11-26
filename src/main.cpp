#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    while (true) {
        cout << "$ " << flush;

        if(!getline(cin, input)) {
            break;
        }

        if (input == "exit") {
            break;
        }

        if (input.starts_with("echo ") || input == "echo") {
            if (input.length() > 4) {
                cout << input.substr(5) << '\n';
            } else {
                cout << '\n';
            }        
        } else if (input.starts_with("type ") || input == "type") {
            if(input.length() > 4) {
                string command = input.substr(5);

                if (command.empty()) {
                    cout << '\n';
                } else if (command == "echo" || command == "exit" || command == "type") {
                    cout << command << " is a shell builtin" << '\n';
                } else {
                    cout << command << ": not found" << '\n';
                }
            } else {
                cout << '\n';
            }
        } else {
            cout << "You entered: " << input << '\n';
        }
    }
}
