#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int CARRY = 10;
map<char, int> val;

class Hex {
public:
    Hex(string n) {
        this->number = n;
        sign = false;
        if (n.empty()) {
            number = "0";
            return;
        }
        if (n[0] == '-') {
            sign = true;
            this->number = string(n.begin() + 1, n.end());
        }
        auto ptr = number.begin();
        for (int i = 0; i < number.size() - 1; i++) {
            if (number[i] == '0') ptr++;
            else break;
        }
        number = string(ptr, number.end());
    }

    bool operator>(const Hex h) const {
        if (sign && !h.sign) return false;
        if (!sign && h.sign) return true;
        if (number == h.number) return false;
        bool num_comparison = false; // true -> this greater
        if (number.size() > h.number.size()) num_comparison = true;
        if (number.size() == h.number.size()) {
            for (int i = 0; i < number.size(); i++) {
                if (number[i] == h.number[i]) continue;
                num_comparison = val[number[i]] > val[h.number[i]];
                break;
            }
        }
        return sign == !num_comparison;
    }

    bool operator==(const Hex h) const {
        return h.number == number && sign == h.sign;
    }

    bool operator>=(const Hex h) const {
        return (*this) == h || (*this) > h;
    }

    bool operator<=(const Hex h) const {
        return !((*this) > h);
    }

    bool operator<(const Hex h) const {
        if (h.number == number && sign == h.sign) return false;
        return (*this) <= h;
    }

    Hex operator+(const Hex h) const {
        if (h.sign && sign) {
            Hex r = Hex(h.number) + Hex(number);
            r.inverse();
            return r;
        }
        if (h.sign) {
            return (*this) - Hex(h.number);
        }
        if (sign) return Hex(h.number) - (*this);
        string rs;
        int offset = 0;
        for (int pos = 0; pos < max(h.number.size(), number.size()); pos++) {
            int va = (pos >= h.number.size()) ? 0 : val[h.number[h.number.size() - pos - 1]];
            int vb = (pos >= number.size()) ? 0 : val[number[number.size() - pos - 1]];
            int result = va + vb + offset;
            offset = 0;
            if (result >= CARRY) {
                offset++;
                result -= CARRY;
            }
            rs.push_back(static_cast<char>(val[result]));
        }
        if (offset) {
            rs.push_back(static_cast<char>(val[offset]));
        }
        return {string(rs.rbegin(), rs.rend())};
    }

    Hex operator-(const Hex h) const {
        if ((*this) == h) return Hex("0");
        if ((*this) < h) {
            Hex result = (h) - (*this);
            result.inverse();
            return result;
        }
        if (h.sign) {
            return (*this) + Hex(h.number);
        }
        int offset = 0;
        string rs;
        for (int pos = 0; pos < max(h.number.size(), number.size()); pos++) {
            int va = (pos >= number.size()) ? 0 : val[number[number.size() - pos - 1]];
            int vb = (pos >= h.number.size()) ? 0 : val[h.number[h.number.size() - pos - 1]];
            int result = va - vb + offset;
            offset = 0;
            if (result < 0) {
                offset--;
                result = CARRY + result;
            }
            rs.push_back(static_cast<char>(val[result]));
        }
        return {string(rs.rbegin(), rs.rend())};
    }

    Hex operator*(const Hex h) const {
        bool new_sign = false;
        new_sign = (h.sign && !sign) || (!h.sign && sign);
        Hex result("0");
        for (int i = 0; i < h.number.size(); i++) {
            Hex tmp("0");
            int vb = val[h.number[h.number.size() - i - 1]];
            for (int j = 0; j < vb; j++) {
                tmp = tmp + (*this);
            }
            for (int k = 0; k < i; k++) tmp.number.push_back('0');
            result = result + tmp;
        }
        result.set_sign(new_sign);
        return result;
    }

    Hex operator/(const Hex h) const {
        bool new_sign = false;
        new_sign = (h.sign && !sign) || (!h.sign && sign);
        Hex abs_a = Hex(number);
        Hex abs_b = Hex(h.number);
        string k = div(abs_a, abs_b, abs_b);
        Hex result(k);
        result.set_sign(new_sign);
        return result;
    }

    Hex operator%(const Hex h) const {
        bool new_sign = false;
        new_sign = (h.sign && !sign) || (!h.sign && sign);
        Hex abs_a = Hex(number);
        Hex abs_b = Hex(h.number);
        Hex offset = (*this) / h;
        Hex result = Hex(number) - offset.abs() * Hex(h);
        result.set_sign(new_sign);
        return result;
    }

    void inverse() {
        sign = !sign;
    }

    void set_sign(bool sign) {
        this->sign = sign;
    }

    void set_number(string num) {
        this->number = num;
    }

    string get_number() {
        if (number == "0") sign = false;
        return (sign ? "-" : "") + number;
    }

    Hex abs() const {
        return Hex(number);
    }

private:
    string number; //number
    bool sign; // true => neg false => pos
    string div(Hex &a, Hex &b, Hex ptr) const {
        string result;
        if (a >= ptr * Hex("10")) {
            result = div(a, b, ptr * Hex("10"));
        }
        int times = 0;
        while (a >= ptr) {
            a = a - ptr;
            times++;
        }
        result += val[times];
        return result;
    }
};

int main() {
    for (int i = 0; i < CARRY; i++) {
        if (i < 10) {
            val[i] = '0' + i;
            val['0' + i] = i;
            continue;
        }
        val[i] = 'A' + (i - 10);
        val['A' + (i - 10)] = i;
    }
    string a, b;
    while (cin >> a >> b) {
        Hex ha(a), hb(b);
        cout << (ha/hb).get_number() << "    " << (ha%hb).get_number() << endl;
    }
}
