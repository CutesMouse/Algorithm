#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int get_hash(pair<int, int> obj) {
    return obj.second * 1000 + obj.first;
}

void sort_players(vector<pair<int, int> > &ps)
{
    for (int i = 0; i < ps.size(); i++)
    {
        for (int j = (i+1) ; j < ps.size(); j++)
        {
            if (get_hash(ps[j]) < get_hash(ps[i])) swap(ps[j], ps[i]);
        }
    }
}

int main()
{
    cout << "Please enter the input file name: ";
    string name;
    getline(cin, name);
    ifstream reader(name, ios::in);
    while (!reader)
    {
        cout << "File could not be opened, please enter again: ";
        getline(cin, name);
        reader.open(name, ios::in);
    }
    reader >> name >> name;
    vector<pair<int, int> > ps;
    int id, height;
    while (reader >> id >> height)
    {
        ps.emplace_back(id, height);
    }
    sort_players(ps);
    cout << "Student ID from short to tall: \n";
    for (int i = 0; i < ps.size(); i ++)
    {
        cout << ps[i].first << " ";
    }
    cout << endl;
    auto st = *(ps.end() - 1);
    printf("Student %d is the tallest in the class, with a height of %d cm.", st.first, st.second);
}
