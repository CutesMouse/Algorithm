#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

map<int, char> class_table;
map<string, int> price_table;
map<string, int> book_status;

class Order
{
public:
    int English = 0;
    int Physics = 0;
    int Programming = 0;
    void append(string subject) {
        if (subject == "English") English++;
        else if (subject == "Physics") Physics++;
        else if (subject == "Programming") Programming++;
    }
    int get_sum() {
        return English * price_table["English"] + Physics * price_table["Physics"] + Programming * price_table["Programming"];
    }
};

map<int, Order> order_table;


string books[] = {"English","Physics","Programming"};

void init_price()
{
    price_table["English"] = 1000;
    price_table["Physics"] = 2000;
    price_table["Programming"] = 1500;

    book_status["English"] = 0;
    book_status["Physics"] = 0;
    book_status["Programming"] = 0;
}

void book_textbook();

void show_summation();

void collect_money();



int main()
{
    init_price();

    string command;

    while (true)
    {
        cout << "*** Textbook Booking System ***\nEnter 1 to Booking Textbook\nEnter 2 to Show Summation\nEnter 3 to Collecting Money\nEnter exit() to quit\n>>>";
        getline(cin,command);
        if (command == "1")
        {
            book_textbook();
        }
        else if (command == "2")
        {
            show_summation();
        }
        else if (command == "3")
        {
            collect_money();
        }
        else if (command == "exit()")
        {
            return 0;
        }
        else {
            cout << "unknown command\n\n";
        }
    }
}

void book_textbook()
{
    string subject;
    int student_id;
    char class_name;

    cout << "\n*** Booking Textbook ***\n";
    cout << "subject: ";
    getline(cin,subject);
    if (!price_table.count(subject))
    {
        cout << "unknown command\n\n";
        return;
    }
    cout << "student ID: ";
    cin >> student_id;
    cout << "class: ";
    cin >> class_name;
    cin.get();
    if (class_name != 'A' && class_name != 'B') {
        cout << "unknown command\n\n";
        return;
    }
    if (class_table.count(student_id))
    {
        if (class_table[student_id] != class_name)
        {
            cout << "The stdID and the class is not match!\n\n";
            return;
        }
    }
    class_table[student_id] = class_name;
    book_status[subject]++;
    order_table[student_id].append(subject);
    cout << endl;
}

void show_summation()
{
    cout << "\n*** Show summation ***\n";
    cout << left<<setw(12) << "Textbook"<<setw(12)<<"Price"<<setw(12)<<"Book"<<setw(12)<<"Total" << "\n";
    for (string &s : books)
    {
        cout <<left << setw(12) << s<<setw(12) <<price_table[s]<<setw(12) << book_status[s]<<setw(12)<<price_table[s]*book_status[s]<<"\n";
    }
    cout << endl;
}

void collect_money()
{
    int id;
    cout << "\n*** Collecting Money ***\n";
    cout << "student ID: ";
    cin >> id;
    cin.get();
    cout << "class "<<class_table[id] << " $"<<order_table[id].get_sum() << endl<<endl;
}
