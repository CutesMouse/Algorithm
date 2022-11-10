#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int get_priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
    }
    return -1;
}

int main() {
    stringstream sstream;
    string formula;
    while (getline(cin,formula)) {
        sstream.clear();
        string ss;
        string temp;
        stack<char> operators;
        stack<string> operands;
        char c;
        for (auto iter = formula.begin(); iter != formula.end(); iter++) {
            c = *iter;
            if (c == ' ') continue;
            if (c == '(' || c == ')' || get_priority(c) != -1) {
                if (!ss.empty()) {
                    operands.push(ss);
                    ss = "";
                }

                if (c == ')') {
                    char opr = operators.top();
                    while (opr != '(') {
                        string a = operands.top();
                        operands.pop();
                        string b = operands.top();
                        operands.pop();
                        string s = b + " " + a + " " + string(1,opr);
                        operands.push(s);
                        operators.pop();
                        opr = operators.top();
                    }
                    operators.pop();
                    continue;
                }
                if (operators.empty() || get_priority(operators.top()) < get_priority(c) || c == '(') {
                    operators.push(c);
                } else {
                    char opr = operators.top();
                    while (get_priority(opr) >= get_priority(c)) {
                        string a = operands.top();
                        operands.pop();
                        string b = operands.top();
                        operands.pop();
                        string s = b + " " + a + " " + opr;
                        operands.push(s);
                        operators.pop();
                        if (operators.empty()) break;
                        opr = operators.top();
                    }
                    operators.push(c);
                }
                continue;
            }
            ss.append(string(1, c));
        }
        if (!ss.empty()) operands.push(ss);
        while (!operators.empty()) {
            c = operators.top();
            operators.pop();
            string a = operands.top();
            operands.pop();
            string b = operands.top();
            operands.pop();
            string s = b + " " + a + " " + c;
            operands.push(s);
        }
        //cout << operands.top() << endl;
        sstream << operands.top();
        stack<int> calc;
        while (sstream >> temp) {
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "%") {
                int b = calc.top();
                calc.pop();
                int a = calc.top();
                calc.pop();
                int c;
                switch (temp[0]) {
                    case '+':
                        c = a + b;
                        break;
                    case '-':
                        c = a - b;
                        break;
                    case '*':
                        c = a * b;
                        break;
                    case '/':
                        c = a / b;
                        break;
                    case '%':
                        c = a % b;
                        break;
                }
                calc.push(c);
                continue;
            }
            calc.push(stoi(temp));
        }
        cout << calc.top() << endl;
    }
}
