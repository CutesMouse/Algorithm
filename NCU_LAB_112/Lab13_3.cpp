#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

struct meal {
    string name;
    int price;
    string number;
    int r_index;
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
    string identity;
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

void show_restaurant_info(restaurant &r);

void show_shop_info(shop &r);

void add_shop();

void add_shop_wizard(int mode);

meal* get_meal(string &order, vector<restaurant> &v);

int parseInt(string &s);

vector<string> split(string s, string spliter);

int main() {
    /*ifstream in("5.in");
    ofstream out("out.txt");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());*/

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
        if (!LOGIN_USER.empty() && db[LOGIN_USER].identity == "seller") cout << "Enter 6 to Add Stores\n";
        cout << "Enter exit() to quit\n";
        cout << ">>>";
        getline(cin, cmd);

        if (cmd == "exit()") return;
        else if (cmd == "1") food_delivery_homepage();
        else if (cmd == "2") shop_homepage();
        else if (cmd == "3") pickup_homepage();
        else if (cmd == "4") member_system();
        else if (cmd == "5") payment();
        else if (!LOGIN_USER.empty() && db[LOGIN_USER].identity == "seller" && cmd == "6") add_shop();
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
        cout << "No. Restaurant                         Delivery Fee\n";
        for (int i = 0; i < restaurants.size(); i++) {
            restaurant r = restaurants[i];
            if (r.name.empty()) continue;
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << r.delivery_fee << endl;
        }
        cout << "Enter number to the restaurant or enter back to the Food Delivery System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > restaurants.size() || restaurants[selected-1].name.empty()) {
            cout << "Unknown command\n";
            continue;
        }
        show_restaurant_info(restaurants[selected - 1]);
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
        meal* m = get_meal(order, restaurants);
        if (!m) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(*m);
        if (!db[LOGIN_USER].involved_restaurant[m->r_index]) {
            db[LOGIN_USER].involved_restaurant[m->r_index] = true;
            db[LOGIN_USER].delivery_fees.push_back(restaurants[m->r_index].delivery_fee);
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
        cout << "No. Shop                               Delivery Fee\n";
        for (int i = 0; i < shops.size(); i++) {
            shop r = shops[i];
            if (r.name.empty()) continue;
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << r.delivery_fee << endl;
        }
        cout << "Enter number to the shop or enter back to the Shops System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > shops.size() || shops[selected - 1].name.empty()) {
            cout << "Unknown command\n";
            continue;
        }
        show_shop_info(shops[selected - 1]);
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
        meal* m = get_meal(order, shops);
        if (!m) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(*m);
        if (!db[LOGIN_USER].involved_shop[m->r_index]) {
            db[LOGIN_USER].involved_shop[m->r_index] = true;
            db[LOGIN_USER].delivery_fees.push_back(shops[m->r_index].delivery_fee);
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
        cout << "No. Restaurant                         Delivery Fee\n";
        for (int i = 0; i < restaurants.size(); i++) {
            restaurant r = restaurants[i];
            if (r.name.empty()) continue;
            cout << left << setw(4) << (i + 1);
            cout << setw(35) << r.name << "NTD";
            cout << right << setw(5) << 0 << endl;
        }
        cout << "Enter number to the restaurant or enter back to the Pick-Up System\n>>>";
        getline(cin, cmd);
        if (cmd == "back") break;
        int selected = parseInt(cmd);
        if (selected > restaurants.size() || restaurants[selected - 1].name.empty()) {
            cout << "Unknown command\n";
            continue;
        }
        show_restaurant_info(restaurants[selected - 1]);
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
        meal* m = get_meal(order, restaurants);
        if (!m) {
            cout << "Wrong number, please enter again!\n";
            continue;
        }
        db[LOGIN_USER].order.push_back(*m);
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
    cout << "Item                               Price\n";
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
        } else if (!db.empty() && cmd == "2" && LOGIN_USER.empty()) {
            login();
        } else if (!db.empty() && cmd == "3" && LOGIN_USER.empty()) {
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
    string info, acc, psw, idt;
    in >> info >> info >> info;
    while (in >> acc >> psw >> idt) {
        userinfo ifo;
        db[acc].password = psw;
        db[acc].identity = idt;
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
    string acc, psw, idt;
    cout << "\n*** Sign Up ***\n";
    cout << "Enter Username: ";
    getline(cin, acc);
    cout << "Enter Password: ";
    getline(cin, psw);
    cout << "Which identity do you want to sign up for?\n";
    cout << "Enter 1 to become a customer\n";
    cout << "Enter 2 to become a seller\n";
    cout << ">>>";
    getline(cin, idt);
    if (idt == "1") {
        db[acc].identity = "customer";
    } else if (idt == "2") {
        db[acc].identity = "seller";
    } else {
        cout << "Unknown command\n";
        cout << "Fail to sign up! Go back to the Member system.\n";
        return;
    }
    db[acc].password = psw;
    cout << "Welcome! You are now a member of Food Delivery System.\n";
}

void show_restaurant_info(restaurant &r) {
    cout << "\n*** " << r.name << " ***\n";
    cout << "No. Cuisine                            Price\n";
    for (int i = 0; i < r.meals.size(); i++) {
        cout << r.meals[i].number << " ";
        cout << setw(35) << left << r.meals[i].name;
        cout << "NTD" << setw(5) << right << r.meals[i].price << endl;
    }
}

void show_shop_info(shop &r) {
    cout << "\n*** " << r.name << " ***\n";
    cout << "No. Groceries                          Price\n";
    for (int i = 0; i < r.meals.size(); i++) {
        cout << r.meals[i].number << " ";
        cout << setw(35) << left << r.meals[i].name;
        cout << "NTD" << setw(5) << right << r.meals[i].price << endl;
    }
}

void add_shop() {
    string cmd;
    while (true) {
        cout << "\n*** Add Store ***\n";
        cout << "Enter 1 to add restaurants\n";
        cout << "Enter 2 to add shops\n";
        cout << "Enter back to the Homepage\n";
        cout << ">>>";
        getline(cin, cmd);
        if (cmd == "1") {
            add_shop_wizard(1);
        } else if (cmd == "2") {
            add_shop_wizard(2);
        } else if (cmd == "back") {
            cout << endl;
            return;
        } else {
            cout << "Unknown command\n";
        }
    }
}

void add_shop_wizard(int mode) {
    string shop = (mode == 1 ? "restaurant" : "shop");
    string groceries = (mode == 1 ? "cuisine" : "groceries");
    string number, name, fee;
    cout << "\nEnter the " << shop << " number: ";
    getline(cin, number);
    cout << "Enter the " << shop << " name: ";
    getline(cin, name);
    cout << "Enter the delivery fee: ";
    getline(cin, fee);
    restaurant r = {name, parseInt(fee), {}};
    int num = parseInt(number);
    cout << "\nAdd items...\n";

    while (true) {
        string cnum, cname, cprice, cmd;
        int p;
        cout << "Enter the " << groceries << " number: ";
        getline(cin, cnum);
        cout << "Enter the " << groceries << " name: ";
        getline(cin, cname);
        cout << "Enter the " << groceries << " price: ";
        getline(cin, cprice);
        p = parseInt(cprice);
        meal m = {cname, p, cnum, num-1};
        r.meals.push_back(m);
        cout << "Add item successfully~ Continue? (y/n) ";
        getline(cin, cmd);
        if (cmd == "n") break;
        cout << endl;
    }

    if (mode == 1) {
        if (restaurants.size() < num) {
            restaurants.resize(num);
        }
        restaurants[num - 1] = r;
    } else {
        if (shops.size() < num) {
            shops.resize(num);
        }
        shops[num - 1] = r;
    }
}

void default_setup() {
    restaurants.push_back({"Wang shih jhen sin tang", 29,{
        {"Bubble Tea", 75, "1-1", 0},
        {"Cheese-Topped Black Tea", 85, "1-2", 0}}});
    restaurants.push_back({"Taiwan di er jia yan su ji", 49,{
        {"Boneless Salted Crispy Chicken", 71, "2-1", 1},
        {"Egg Tofu", 78, "2-2", 1},
        {"Green Beans", 52, "2-3", 1}}});
    restaurants.push_back({"Fang kong nai ba", 39, {
        {"Sakura Shrimp Fried Rice", 140, "3-1", 2},
        {"Squid Fried Noodles", 130, "3-2", 2},
        {"Grilled King Oyster Mushrooms", 50, "3-3", 2}}});
    shops.push_back({"Walmart", 49,{
        {"Tissue", 124, "1-1", 0},
        {"Light Bulbs", 99, "1-2", 0}}});
    shops.push_back({"Target", 39, {
        {"Shampoo", 239, "2-1", 1},
        {"Toothpaste", 129, "2-2", 1}}});
    shops.push_back({"Costco", 29, {
        {"Milk", 259, "3-1", 2},
        {"Doritos", 165, "3-2", 2},
        {"Croissant", 199, "3-3", 2}}});
}

meal* get_meal(string &order, vector<restaurant> &v) {
    for (auto &r : v) {
        for (auto &m : r.meals) {
            if (m.number == order) return &m;
        }
    }
    return nullptr;
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
