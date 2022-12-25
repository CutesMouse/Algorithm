#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<stack<string> > prt;
stack<string> function_stack;

void push(string s)
{
    function_stack.push(s);
    prt.push_back(function_stack);
}

void pop()
{
    function_stack.pop();
    prt.push_back(function_stack);
}

int fib(int n)
{
    if (n == 0) return 0;
    push("Fibonacci("+to_string(n)+")");
    if (n == 1)
    {
        pop();
        return 1;
    }
    int r = fib(n-1);
    r += fib(n-2);
    pop();
    return r;
}

string nth(int k) {
    if (k == 11 || k == 12 || k == 13) return "th";
    switch (k%10) {
    case 1:
        return "st";
    case 2:
        return "nd";
    case 3:
        return "rd";
    default:
        return "th";
    }
}

int main()
{
    push("OS");
    push("main()");
    cout << "Input an integer: ";
    int i;
    cin >> i;
    int f = fib(i);
    cout << "The "<<i<<nth(i)<<" in fisher sequence is " <<f << endl;
    cout << endl;
    cout << "Begin of function call stacks"<<endl;
    pop();
    pop();
    for (auto iter = prt.begin(); iter != prt.end(); iter++) {
        cout << endl;
        while (iter->size()) {
            cout << iter->top() << endl;
            iter->pop();
        }
    }
    cout << "End of function call stacks";
}
