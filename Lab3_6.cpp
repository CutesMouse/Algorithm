#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cat {
    string name;
    int pos;
    int age;
};

vector<string> pos_list = {"elder", "nursy", "kit", "warrior", "appentice", "medicent", "deputy", "leader"};

bool cmp(cat &c1, cat &c2) {
    if (c1.pos != c2.pos) {
        return c1.pos < c2.pos;
    }
    if (c1.pos == 4) {
        if (c1.age != c2.age) return c1.age < c2.age;
        return c1.name < c2.name;
    }
    if (c1.age != c2.age) return c1.age > c2.age;
    return c1.name < c2.name;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<cat> cats;
        string a, b;
        int c;
        while (N--) {
            cin >> a >> b >> c;
            cats.push_back({a, (int) (find(pos_list.begin(), pos_list.end(), b) - pos_list.begin()), c});
        }
        sort(cats.begin(), cats.end(), cmp);
        for (int i = 0; i < min(M, (int) cats.size()); i++) cout << cats[i].name << endl;
    }
}
