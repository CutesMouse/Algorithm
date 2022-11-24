#include <iostream>
using namespace std;
int second_place_1();
int second_place_2();
int second_place_3();

int main()
{

    int d1, d2;

    cout << "Please choose the first place: (1 km = $ 0.5)\n";
    cout << "1. Taipei (50 km)\n2. Tainan (270 km)\n3. Hualien (204 km)\n";
    cin >> d1;
    switch (d1)
    {
    case 1:
        d1 = 50;
        d2 = second_place_1();
        break;
    case 2:
        d1 = 270;
        d2 = second_place_2();
        break;
    case 3:
        d1 = 204;
        d2 = second_place_3();
        break;
    }
    int dis = d1+d2;
    int cost = 0.5 * dis;
    printf("Distance: %d km\nCost: %d",dis,cost);
}
int second_place_1()
{
    int place;
    cout << "Please choose the second place: (1 km = $ 0.5)\n";
    cout << "1. National Palace Museum (10 km)\n";
    cout << "2. Longshan Temple (8 km)\n";
    cin >> place;
    if (place == 1) return 10;
    return 8;
}
int second_place_2()
{
    int place;
    cout << "Please choose the second place: (1 km = $ 0.5)\n";
    cout << "1. Anping Old Street (6 km)\n";
    cout << "2. Chimei Museum (10 km)\n";
    cin >> place;
    if (place == 1) return 6;
    return 10;
}
int second_place_3()
{
    int place;
    cout << "Please choose the second place: (1 km = $ 0.5)\n";
    cout << "1. Emerald Valley (16 km)\n";
    cin >> place;
    return 16;
}

