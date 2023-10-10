#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Please enter three numbers:\n";
    cin >> a >> b >> c;
    
    int f, s, t;
    
    if (a >= b && b >= c) {
        f = a;
        s = b;
        t = c;
     } //abc
    if (a >= c && c >= b) {
        f = a;
        s = c;
        t = b;
    } //acb
    if (b >= a && a >= c) {
        f = b;
        s = a;
        t = c;
    } //bac
    if (b >= c && c >= a) {
        f = b;
        s = c;
        t = a;
    } //bca
    if (c >= a && a >= b) {
        f = c;
        s = a;
        t = b;
    } //cab
    if (c >= b && b >= a) {
        f = c;
        s = b;
        t = a;
    } //cba
    cout << f << " ";
    if (f == s) cout << "= ";
    else cout << "> ";
    cout << s << " ";
    if (s == t) cout << "= ";
    else cout << "> ";
    cout << t;
}
