#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

struct meal {
    string name;
    int price;
};

struct restaurant {
    string name;
    int delivery_fee;
    vector<meal> meals;
};

typedef restaurant shop;

struct userinfo {
    vector<meal> order;
    bool involved_restaurant[100] = {0};
    bool involved_shop[100] = {0};
    vector<int> delivery_fees;
    string password;
};

string LOGIN_USER;
map<string, userinfo> db;
vector<restaurant> restaurants;
vector<shop> shops;

void main_menu();

void food_delivery_homepage();

void food_delivery_list_restaurant();

void food_delivery_add_cart();

void shop_homepage();

void shop_list_shop();

void shop_add_cart();

void pickup_homepage();

void pickup_list_restaurant();

void pickup_add_cart();

void payment();

void member_system();

void load_member_information();

void login();

void sign_up();

void default_setup();

void show_restaurant_info(restaurant &r, int index);

void show_shop_info(shop &r, int index);

int parseInt(string &s);

vector<string> split(string s, string spliter);

int main() {
    ifstream in("5.in");
    ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    default_setup();
    main_menu();
    return 0;
}

void main_menu() {
    string cmd;
    while (true) {
        cout << "**********************************\n";
        cout << "***   Food Delivery Homepage   ***\n";
        cout << "**********************************\n";
        cout << "Enter 1 to Food Delivery System\n";
        cout << "Enter 2 to Shops System\n";
        cout << "Enter 3 to Pick-Up System\n";
        cout << "Enter 4 to Member System\n";
        cout << "Enter 5 to Payment\n";
        cout << "Enter exit() to quit\n";
        cout << ">>>";
        getline(cin, cmd);

        if (cmd == "exit()") return;
        else if (cmd == "1") food_delivery_homepage();
        else if (cmd == "2") shop_homepage();
        else if (cmd == "3") pickup_homepage();
        else if (cmd == "4") member_system();
        else if (cmd == "5") payment();
        else cout << "Unknown command\n\n";
    }
}

void food_delivery_homepage() {
    string cmd;
    while (true) {
        cout << "\n**********************************\n";
        cout << "***    Food Delivery System    ***\n";
        cout << "**********************************\n";
        cout << "Enter 1 to List Restaurants\n";
        cout << "Enter 2 to Add Items to Cart\n";
        cout << "Enter back to the Homepage\n";
        cout << ">>>";
        getline(cin, cmd);

        if (cmd == "back") {
            cout << endl;
            return;
        } else if (cmd == "1") food_delivery_list_restaurant();
        else if (cmd == "2") food_delivery_add_cart();
        else cout << "Unknown command\n";
    }
}

void food_delivery_list_restaurant() {
    string cmd;
    while (true) {
        cout << "\n*** List Restaurants ***\n";
        cout << "No. Restaurant                         Delivery Fee   \n";
        for (int i = 0; i < restaurants.size(); i++) {
            restaurant r = restaurants[i];
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << r.delivery_fee << endl;
        }
        cout << "Enter number to the restaurant or enter back to the Food Delivery System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > restaurants.size()) {
            cout << "Unknown command\n";
            continue;
        }
        show_restaurant_info(restaurants[selected - 1], selected);
    }
}

void food_delivery_add_cart() {
    if (LOGIN_USER.empty()) {
        cout << "\nPlease log in first.\n";
        return;
    }
    string order;
    cout << "\n*** Add Items to Cart ***\n";
    while (true) {
        cout << "Enter item number to add it to cart: ";
        getline(cin, order);
        vector<string> response = split(order, "-");
        int r_index = parseInt(response[0]) - 1;
        int m_index = parseInt(response[1]) - 1;
        if (r_index < 0 || r_index >= restaurants.size() || m_index < 0 ||
            m_index >= restaurants[r_index].meals.size()) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(restaurants[r_index].meals[m_index]);
        if (!db[LOGIN_USER].involved_restaurant[r_index]) {
            db[LOGIN_USER].involved_restaurant[r_index] = true;
            db[LOGIN_USER].delivery_fees.push_back(restaurants[r_index].delivery_fee);
        }
        cout << "Added successfully!\n";
        break;
    }
}

void shop_homepage() {
    string cmd;
    while (true) {
        cout << "\n**********************************\n";
        cout << "***        Shops System        ***\n";
        cout << "**********************************\n";
        cout << "Enter 1 to List Shops\n";
        cout << "Enter 2 to Add Items to Cart\n";
        cout << "Enter back to the Homepage\n";
        cout << ">>>";
        getline(cin, cmd);

        if (cmd == "back") {
            cout << endl;
            return;
        } else if (cmd == "1") shop_list_shop();
        else if (cmd == "2") shop_add_cart();
        else cout << "Unknown command\n";
    }
}

void shop_list_shop() {
    string cmd;
    while (true) {
        cout << "\n*** List Shops ***\n";
        cout << "No. Shop                               Delivery Fee   \n";
        for (int i = 0; i < shops.size(); i++) {
            shop r = shops[i];
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << r.delivery_fee << endl;
        }
        cout << "Enter number to the shop or enter back to the Shops System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > shops.size()) {
            cout << "Unknown command\n";
            continue;
        }
        show_shop_info(shops[selected - 1], selected);
    }
}

void shop_add_cart() {
    if (LOGIN_USER.empty()) {
        cout << "\nPlease log in first.\n";
        return;
    }
    string order;
    cout << "\n*** Add Items to Cart ***\n";
    while (true) {
        cout << "Enter item number to add it to cart: ";
        getline(cin, order);
        vector<string> response = split(order, "-");
        int r_index = parseInt(response[0]) - 1;
        int m_index = parseInt(response[1]) - 1;
        if (r_index < 0 || r_index >= shops.size() || m_index < 0 || m_index >= shops[r_index].meals.size()) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(shops[r_index].meals[m_index]);
        if (!db[LOGIN_USER].involved_shop[r_index]) {
            db[LOGIN_USER].involved_shop[r_index] = true;
            db[LOGIN_USER].delivery_fees.push_back(shops[r_index].delivery_fee);
        }
        cout << "Added successfully!\n";
        break;
    }
}

void pickup_homepage() {
    string cmd;
    while (true) {
        cout << "\n**********************************\n";
        cout << "***       Pick-Up System       ***\n";
        cout << "**********************************\n";
        cout << "Enter 1 to List Restaurants\n";
        cout << "Enter 2 to Add Items to Cart\n";
        cout << "Enter back to the Homepage\n";
        cout << ">>>";
        getline(cin, cmd);

        if (cmd == "back") {
            cout << endl;
            return;
        } else if (cmd == "1") pickup_list_restaurant();
        else if (cmd == "2") pickup_add_cart();
        else cout << "Unknown command\n";
    }
}

void pickup_list_restaurant() {
    string cmd;
    while (true) {
        cout << "\n*** List Restaurants ***\n";
        cout << "No. Restaurant                         Delivery Fee   \n";
        for (int i = 0; i < restaurants.size(); i++) {
            restaurant r = restaurants[i];
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << 0 << endl;
        }
        cout << "Enter number to the restaurant or enter back to the Pick-Up System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > restaurants.size()) {
            cout << "Unknown command\n";
            continue;
        }
        show_restaurant_info(restaurants[selected - 1], selected);
    }
}

void pickup_add_cart() {
    if (LOGIN_USER.empty()) {
        cout << "\nPlease log in first.\n";
        return;
    }
    string order;
    cout << "\n*** Add Items to Cart ***\n";
    while (true) {
        cout << "Enter item number to add it to cart: ";
        getline(cin, order);
        vector<string> response = split(order, "-");
        int r_index = parseInt(response[0]) - 1;
        int m_index = parseInt(response[1]) - 1;
        if (r_index < 0 || r_index >= restaurants.size() || m_index < 0 ||
            m_index >= restaurants[r_index].meals.size()) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(restaurants[r_index].meals[m_index]);
        cout << "Added successfully!\n";
        break;
    }
}

void payment() {
    cout << "\n*** Payment ***\n";
    if (LOGIN_USER.empty()) {
        cout << "Please log in first.\n\n";
        return;
    }
    vector<meal> meals = db[LOGIN_USER].order;
    if (meals.empty()) {
        cout << "You don't have any item in cart!\n\n";
        return;
    }
    cout << "\n*** This is " << LOGIN_USER << "'s order ***\n";
    cout << "Item                               Price     \n";
    cout << "-------------------------------------------\n";
    int total = 0;
    for (int i = 0; i < meals.size(); i++) {
        cout << left << setw(35) << meals[i].name << "NTD";
        cout << right << setw(5) << meals[i].price << endl;
        total += meals[i].price;
    }
    for (int i = 0; i < db[LOGIN_USER].delivery_fees.size(); i++) {
        int df = db[LOGIN_USER].delivery_fees[i];
        cout << left << setw(35) << "Delivery Fee" << "NTD";
        cout << right << setw(5) << df << endl;
        total += df;
    }
    cout << "-------------------------------------------\n";
    cout << "Total                              NTD" << right << setw(5) << total << endl << endl;
}

void member_system() {
    string cmd;
    while (true) {
        cout << "\n**********************************\n";
        cout << "***       Member system        ***\n";
        cout << "**********************************\n";
        if (db.empty() && LOGIN_USER.empty()) cout << "Enter 1 to Load Member Information\n";
        if (!db.empty() && LOGIN_USER.empty()) cout << "Enter 2 to Log In\n";
        if (!db.empty() && LOGIN_USER.empty()) cout << "Enter 3 to Sign Up\n";
        if (!LOGIN_USER.empty()) cout << "You are log in.\n";
        if (!LOGIN_USER.empty()) cout << "Enter 4 to log out\n";
        cout << "Enter back to the Homepage\n";
        cout << ">>>";
        getline(cin, cmd);
        if (!LOGIN_USER.empty() && cmd == "4") {
            LOGIN_USER = "";
            cout << "You are logging out...\n\n";
            return;
        } else if (db.empty() && cmd == "1") {
            load_member_information();
        } else if (!db.empty() && cmd == "2") {
            login();
        } else if (!db.empty() && cmd == "3") {
            sign_up();
        } else if (cmd == "back") {
            cout << endl;
            return;
        } else {
            cout << "Unknown command\n";
        }
    }

}

void load_member_information() {
    string cmd;
    cout << "\n*** Load Member Information ***\n";
    cout << "Enter the member file name: ";
    getline(cin, cmd);
    ifstream in(cmd);
    if (!in) {
        cout << "File could not be opened.\n";
        return;
    }
    string info, acc, psw;
    in >> info >> info;
    while (in >> acc >> psw) {
        userinfo ifo;
        db[acc].password = psw;
    }
    cout << "The file " << cmd << " has been loaded...\n";
}

void login() {
    string acc, psw;
    cout << "\n*** Log In ***\n";
    cout << "Enter Username: ";
    getline(cin, acc);
    cout << "Enter Password: ";
    getline(cin, psw);
    if (db.count(acc) && db[acc].password == psw) {
        LOGIN_USER = acc;
        cout << "Welcome, " << LOGIN_USER << "!\n";
    } else {
        cout << "Fail to find your data.\n";
        cout << "Please sign up first.\n";
    }
}

void sign_up() {
    string acc, psw;
    cout << "\n*** Sign Up ***\n";
    cout << "Enter Username: ";
    getline(cin, acc);
    cout << "Enter Password: ";
    getline(cin, psw);
    db[acc].password = psw;
    cout << "Welcome! You are now a member of Food Delivery System.\n";
}

void show_restaurant_info(restaurant &r, int index) {
    cout << "\n***   " << r.name << "   ***\n";
    cout << "No. Cuisine                            Price     \n";
    for (int i = 0; i < r.meals.size(); i++) {
        cout << index << "-" << (i + 1) << " ";
        cout << setw(35) << left << r.meals[i].name;
        cout << "NTD" << setw(5) << right << r.meals[i].price << endl;
    }
}

void show_shop_info(shop &r, int index) {
    cout << "\n***   " << r.name << "   ***\n";
    cout << "No. Groceries                          Price     \n";
    for (int i = 0; i < r.meals.size(); i++) {
        cout << index << "-" << (i + 1) << " ";
        cout << setw(35) << left << r.meals[i].name;
        cout << "NTD" << setw(5) << right << r.meals[i].price << endl;
    }
}

void default_setup() {
    restaurants.push_back({"Wang shih jhen sin tang", 29, {{"Bubble Tea", 75}, {"Cheese-Topped Black Tea", 85}}});
    restaurants.push_back({"Taiwan di er jia yan su ji", 49,
                           {{"Boneless Salted Crispy Chicken", 71}, {"Egg Tofu", 78}, {"Green Beans", 52}}});
    restaurants.push_back({"Fang kong nai ba", 39, {{"Sakura Shrimp Fried Rice", 140}, {"Squid Fried Noodles", 130},
                                                    {"Grilled King Oyster Mushrooms", 50}}});
    shops.push_back({"Walmart", 49, {{"Tissue", 124}, {"Light Bulbs", 99}}});
    shops.push_back({"Target", 39, {{"Shampoo", 239}, {"Toothpaste", 129}}});
    shops.push_back({"Costco", 29, {{"Milk", 259}, {"Doritos", 165}, {"Croissant", 199}}});

}

int parseInt(string &s) {
    int val = 0;
    for (int i = 0; i < s.size(); i++) {
        val *= 10;
        val += s[i] - '0';
    }
    return val;
}

vector<string> split(string s, string spliter) {
    vector<string> ans;
    string temp;
    for (int i = 0; i < s.size(); i++) {
        if (s.substr(i, spliter.size()) == spliter) {
            ans.push_back(temp);
            temp = "";
            i += (spliter.size() - 1);
            continue;
        }
        temp += s[i];
    }
    ans.push_back(temp);
    return ans;
}
