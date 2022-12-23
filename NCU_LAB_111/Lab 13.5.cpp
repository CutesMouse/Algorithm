#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
public:
    string name;
    bool gender; //male = 1, female = 0
    double weight;
    double height;

    double get_ideal() {
        if (gender) return 0.7 * (height - 80);
        return 0.6 * (height - 70);
    }

    string get_modifier() {
        return gender ? "his" : "her";
    }

    void print_ideal_string() {
        double ideal = get_ideal();
        cout << fixed << setprecision(2) << ideal * 0.9 << " to " << ideal * 1.1;
    }

    void print_status() {
        double ideal = get_ideal();
        double ratio = weight / ideal;
        cout << name << " is ";
        if (ratio < 0.8) cout << "severely underweight";
        else if (ratio < 0.9) cout << "underweight";
        else if (ratio < 1.1) cout << "in standard weight";
        else if (ratio < 1.2) cout << "overweight";
        else cout << "severely overweight";
        cout << ", and " << get_modifier() << " ideal weight range is ";
        print_ideal_string();
        cout << " kg.\n";
    }
};

bool comp(const Student &a, const Student &b) {
    for (int k = 0; k < min(a.name.size(), b.name.size()); k++) {
        if (a.name[k] > b.name[k]) return false;
        if (a.name[k] == b.name[k]) continue;
        return true;
    }
    return a.name.size() < b.name.size();
}

int main() {
    string name, gender;
    double weight;
    double height;

    vector<Student> students;

    while (cin >> name >> gender >> weight >> height) {
        Student s = {name, gender == "Male", weight, height};
        students.push_back(s);
    }
    sort(students.begin(), students.end(), comp);
    for (auto &student: students) student.print_status();
}
