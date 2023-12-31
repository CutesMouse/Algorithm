#include <iostream>
using namespace std;

typedef long long int lli;

struct range {
    lli from;
    lli to;
    bool left_open;
    bool right_open;
};

lli readVal() {
    char c;
    bool neg = false;
    bool inf = false;
    lli val = 0;
    while ((c = cin.get()) != ' ') {
        if (inf) continue;
        if (c == '-') {
            neg = true;
            continue;
        }
        if (c == 'i' || c == '+') {
            inf = true;
            continue;
        }
        val *= 10;
        val += (c - '0');
    }
    if (inf) val = (1L<<32);
    return neg ? -val : val;
}

bool isEmpty(range &r) {
    return (r.left_open && r.right_open && !(r.from) && !(r.to)); 
}

bool isLinked(range &r1, range &r2) {
    return (r1.to == r2.from && (r1.right_open ^ r2.left_open)) || (r2.to == r1.from && (r1.left_open ^ r2.right_open));
}

range readRange() {
    char c;
    range r;
    c = cin.get();
    if (c == 'o') {
        cin.get();
        return {0, 0, true, true};
    }
    if (c == '[') r.left_open = false;
    else r.left_open = true;
    cin.get();
    r.from = readVal();
    r.to = readVal();
    c = cin.get();
    if (c == ']') r.right_open = false;
    else r.right_open = true;
    cin.get();
    return r;
}

range intersection(range r1, range r2) {
    if (isEmpty(r1) || isEmpty(r2)) return {0, 0, true, true};
    range nr;
    nr.left_open = false;
    nr.right_open = false;
    lli from = max(r1.from, r2.from);
    lli to = min(r1.to, r2.to);
    if (from > to) return {0, 0, true, true};
    if (from == r1.from) {
        nr.left_open = r1.left_open;
    }
    if (from == r2.from) {
        nr.left_open |= r2.left_open;
    }
    if (to == r1.to) {
        nr.right_open = r1.right_open;
    }
    if (to == r2.to) {
        nr.right_open |= r2.right_open;
    }
    if (from == to && (nr.right_open || nr.left_open)) return {0, 0, true, true};
    nr.from = from;
    nr.to = to;
    return nr;
}

range range_union(range r1, range r2) {
    if (isEmpty(r1)) return r2;
    if (isEmpty(r2)) return r1;
    range r = intersection(r1, r2);
    if (isEmpty(r) && !isLinked(r1, r2)) {
        r.from = (1L<<33);
        return r;
    }
    r.left_open = true;
    r.right_open = true;
    lli from = min(r1.from, r2.from);
    lli to = max(r1.to, r2.to);
    if (from == r1.from) {
        r.left_open = r1.left_open;
    }
    if (from == r2.from) {
        r.left_open &= r2.left_open;
    }
    if (to == r1.to) {
        r.right_open = r1.right_open;
    }
    if (to == r2.to) {
        r.right_open &= r2.right_open;
    }
    r.from = from;
    r.to = to;
    return r;
}

void print_range(range &r) {
    if (r.left_open && r.right_open && !(r.from) && !(r.to)) {
        cout << "o";
        return;
    }
    if (r.left_open) cout << "( ";
    else cout << "[ ";
    if (r.from == (1L<<32)) cout << "+inf";
    else if (r.from == -(1L<<32)) cout << "-inf";
    else cout << r.from;
    cout << " ";
    if (r.to == (1L<<32)) cout << "+inf";
    else if (r.to == -(1L<<32)) cout << "-inf";
    else cout << r.to;
    cout << " ";
    if (r.right_open) cout << ")";
    else cout << "]";
}

int main() {
    char c;
    range r = readRange();
    range r2, r3;
    while ((c = cin.get()) != 'E') {
        //cout << "THREAD" << endl;
        cin.get();
        r2 = readRange();
        if (c == 'I') {
            r = intersection(r, r2);
        } else {
            r3 = range_union(r, r2);
            if (r3.from == (1L<<33)) {
                cout << "Fail to simplify! Please enter again!\n";
            } else r = r3;
        }
    }
    cout << "Simplified interval: ";
    print_range(r);
}
