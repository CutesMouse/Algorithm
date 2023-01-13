#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

map<int, char> class_table;
map<string, int> price_table;
map<string, int> book_status;
map<string, string> accounts;
map<string, string> borrow_status;
vector<string> members;
string session = "";

class Order
{
public:
    int sum = 0;
    vector<string> books;
    void append(string subject)
    {
        sum += price_table[subject];
        books.push_back(subject);
    }
    vector<string> get_books()
    {
        return books;
    }
    int get_sum()
    {
        return sum;
    }
};

map<int, Order> order_table;


vector<string> books = {"English","Physics","Programming"};

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

void adding_textbook();

void member_center();

void showMember();

void logout();

void member_center_menu();

void borrow_textbook();

void return_textbook();

void show_avaliable();

void load_data();

void insert_book(string name, int price);

void insert_booking_Info(int id, char clas, const vector<pair<string, int> > &booking_info);



int main()
{
    init_price();

    string command;

    while (true)
    {
        cout << "*** Textbook Booking System ***\n";
        cout << "Enter 1 to Booking Textbook\n";
        cout << "Enter 2 to Show Summation\n";
        cout << "Enter 3 to Collecting Money\n";
        cout << "Enter 4 to Adding Textbook\n";
        cout << "Enter 5 to Member Center\n";
        cout << "Enter 6 to Show Every Member\n";
        cout << "Enter 7 to Loading Data\n";
        if (!session.empty()) cout << "Enter 8 to Logout\n";
        cout << "Enter exit() to quit\n>>>";
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
        else if (command == "4")
        {
            adding_textbook();
        }
        else if (command == "5")
        {
            member_center();
        }
        else if (command == "6")
        {
            showMember();
        }
        else if (command == "7")
        {
            load_data();
        }
        else if (command == "8" && !session.empty())
        {
            logout();
        }
        else if (command == "exit()")
        {
            return 0;
        }
        else
        {
            cout << "unknown command\n\n";
        }
    }
}

void insert_book(string name, int price)
{
    books.push_back(name);
    price_table[name] = price;
}

void insert_booking_Info(int id, char clas, const vector<pair<string, int> > &booking_info)
{
    class_table[id] = clas;
    for (int i = 0; i < booking_info.size(); i++)
    {
        if (booking_info[i].second)
        {
            for (int k = 0; k < booking_info[i].second; k++)
            {
                string subject = booking_info[i].first;
                book_status[subject] ++;
                order_table[id].append(subject);
            }
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
    if (class_table.count(student_id))
    {
        if (class_table[student_id] != class_name)
        {
            cout << "The stdID and the class is not match!\n\n";
            return;
        }
    }
    if (class_name != 'A' && class_name != 'B')
    {
        cout << "unknown command\n\n";
        return;
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
    if (!class_table.count(id))
    {
        cout << "unknown command\n\n";
        cin.get();
        return;
    }
    cin.get();
    cout << "class "<<class_table[id] << " $"<<order_table[id].get_sum() << endl;
    cout << "Booked: ";
    string k;
    if (order_table[id].get_books().size() == 1)
    {
        cout << order_table[id].get_books()[0] << endl << endl;
        return;
    }
    else
    {
        vector<string> booksd = order_table[id].get_books();
        for (int i = 0 ; i < booksd.size()-1; i++)
        {
            k += ", " + booksd[i];
        }
        k += " and " + *(booksd.end()-1);
    }

    cout << k.substr(2) << endl;
    cout <<endl;
}

void adding_textbook()
{
    string name;
    cout << "\n*** Adding Textbook ***\n";
    cout << "Please enter the textbook name and price\n";
    cout << "name: ";
    getline(cin,name);
    if (price_table.count(name))
    {
        cout << "The book has already existed in the booklist.";
        cout << endl << endl;
        return;
    }
    cout << "price: ";
    int price;
    cin >> price;
    cin.get();
    insert_book(name, price);
    cout << endl;
}

void member_center()
{
    if (!session.empty())
    {
        cout << "\n***Booking system Member Center***\n";
        cout << "Hi "<<session<<"~\n";
        cout << "How can I help you?\n";
        member_center_menu();
        cout <<endl;
        return;
    }
    char response;
    cout << "\n***Booking system Member Center***\n";
    cout << "Do you have the membership? (y/n) ";
    cin >> response;
    cin.get();
    if (response == 'y')
    {
        cout << "Enter Username: ";
        string us, pw;
        getline(cin, us);
        if (!accounts.count(us))
        {
            cout << "You didn't sign up\n";
        }
        else
        {
            cout << "Enter Password: ";
            getline(cin, pw);
            if (pw != accounts[us])
            {
                cout << "The username and the password don't matched.\n\n";
                return;
            }
            cout << "*** Welcome back "<<us<<" ***\n\n";
            session = us;
            return;
        }
    }
    cout << "Would you like to sign up? (y/n) ";
    cin >>response;
    cin.get();
    if (response == 'n')
    {
        cout << "Okay! Have a nice day :)\n\n";
        return;
    }
    string us;
    string pw;
    cout << "Enter Username: ";
    getline(cin,us);
    cout << "Enter Password: ";
    getline(cin,pw);
    accounts[us] = pw;
    members.push_back(us);
    cout << "Welcome! You are now a member of the Booking system.\n";
    cout << "Please log in again.\n\n";

}

void member_center_menu()
{
    cout << "Enter 1 to Borrow Textbook\n";
    cout << "Enter 2 to Return Textbook\n";
    cout << "Enter 3 to Show Available Textbooks\n";
    cout << "Enter 4 to go back to Main menu\n";
    cout << ">>>";
    string command;
    getline(cin,command);
    if (command == "1")
    {
        borrow_textbook();
    }
    else if (command == "2")
    {
        return_textbook();
    }
    else if (command == "3")
    {
        show_avaliable();
    }
    else if (command == "4")
    {

    }
}

void borrow_textbook()
{
    string subj;
    cout << "Which textbook do you want to borrow: ";
    getline(cin, subj);
    if (borrow_status.count(subj) && !borrow_status[subj].empty())
    {
        if (borrow_status[subj] == session)
        {
            cout << "You have already borrowed "<<subj<<"...\n";
            return;
        }
        cout << "The textbook has been borrowed...\n";
        return;
    }
    borrow_status[subj] = session;
    cout << "You have borrowed "<<subj<<"...\n";
}

void return_textbook()
{
    string subj;
    cout << "Which textbook do you want to return: ";
    getline(cin, subj);
    if (!borrow_status.count(subj) || borrow_status[subj] != session)
    {
        cout << "You didn't borrow this textbook...\n";
    }
    else
    {
        borrow_status[subj] = "";
        cout << "You have returned "<<subj<<"...\n";
    }
}

void show_avaliable()
{
    cout << "***Status of textbooks***\n";
    for (int i = 0; i < books.size(); i++)
    {
        string book = books[i];
        cout << setw(14) << left << book;
        if (borrow_status.count(book) && !borrow_status[book].empty()) cout << "Unavailable";
        else cout << "Available";
        cout << endl;
    }
}

void showMember()
{
    cout << "\n*** Show Every Member ***\n";
    if (!members.size())
    {
        cout << "There isn't any member in the booking system.\n\n";
        return;
    }
    cout << "Member:\n";
    for (string &user : members)
    {
        cout << user << endl;
    }
    cout << endl;
}

void logout()
{
    if (session.empty())
    {
        cout << "You didn't login!!!\n\n";
        return;
    }
    cout << "Bye "<<session<<"~ \n\n";
    session = "";
}

void load_data()
{
    cout << "\n*** Loading Data ***\n";
    cout << "Please enter the input file name: ";
    string fname;
    getline(cin, fname);
    ifstream reader(fname, ios::in);
    if (!reader)
    {
        cout << "File could not be opened.\n\n";
        return;
    }
    // loading textbooks
    string input;
    while (reader >> input)
    {
        if (input == "Price") break;
    }
    string name;
    int price;
    while (true)
    {
        reader >> name;
        if (name == "#") break;
        reader >> price;
        insert_book(name, price);
    }
    //loading book textbooks
    while (reader >> input)
    {
        if (input == "Class") break;
    }
    string ignore;
    int id;
    char clas;
    stringstream handler;
    getline(reader, ignore);
    handler << ignore;
    string book_name;
    vector<string> orders;
    while (handler >> book_name)
    {
        orders.push_back(book_name);
    }
    while (reader >> id >> clas && !reader.eof())
    {
        int order;
        vector<pair<string, int> > info;
        for (int i = 0; i < orders.size(); i++)
        {
            reader >> order;
            info.emplace_back(orders[i], order);
        }
        insert_booking_Info(id, clas, info);
        getline(reader, ignore);
    }

    cout << "The file is successfully loaded to the system.\n";
    cout << endl;
}
