#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void io1() {
    cout << "Enter string input: \n";

    string input1 = "";
    getline(cin, input1);
    
    cout << "Given Input: \n" << input1 << endl;

    int n;
    cout << "Enter Size of Array: \n";
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "Output: \n";
    for (auto &i: v)
        cout << i << " ";
}

void io2() {
    int userNumber;

    cout << "Enter a positive integer: ";
    while (!(cin >> userNumber) || userNumber <= 0) {
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); // Ignore bad input
        cout << "Invalid input. Please enter a positive "
                "integer: ";
    }

    cout << "You entered a positive integer: " << userNumber
         << endl;
}

void io3() {
    string input = "";
    getline(cin, input);
    
    char del;
    cin >> del;

    stringstream ss(input);

    string temp = "";
    while (getline(ss, temp, del)) {
        cout << temp << endl;
    }
}

int main() {
    io3();
}