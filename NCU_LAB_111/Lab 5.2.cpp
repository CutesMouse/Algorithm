#include <iostream>
using namespace std;

int main()
{
    int num_shoes=0, num_item=0;
    float money=0, save=0;

    do
    {
        cout << "How many pairs of shoes does the customer buy: ";
        cin >> num_shoes;
        if(num_shoes > 3 || num_shoes <= 0)
        {
            cout << "Wrong input, please enter again!!!" <<endl;
        }
    } while(num_shoes > 3 || num_shoes <=0);

    do
    {
        cout << "How many item (except shoes) does the customer buy: ";
        cin >> num_item;
        if (num_item<=0 || num_item>5)
        {
            cout << "Wrong input, please enter again!!!" <<endl;
        }
    }
    while(num_item<=0 || num_item>5);

    int shoes_1=0, shoes_2=0, shoes_3=0;//price of shoes
    int item_1=0, item_2=0, item_3=0, item_4=0, item_5=0; //price of item

    cout << "Please enter each price of shoes: ";
    switch (num_shoes)
    {
    case 1:
        cin >> shoes_1;
        money = shoes_1;
        break;
    case 2:
        cin >> shoes_1 >> shoes_2;
        money = (shoes_1+shoes_2)*0.8;
        save = (shoes_1+shoes_2)*0.2;
        break;
    case 3:
        cin >> shoes_1 >> shoes_2 >> shoes_3;
        money =(shoes_1+shoes_2+shoes_3)*0.7;
        save = (shoes_1+shoes_2+shoes_3)*0.3;
        break;
    default:
        break;
    }

    cout << "Please enter each price of item (except shoes): ";
    switch(num_item)
    {
    case 1:
        cin >>item_1;
        money = money+item_1;
        break;
    case 2:
        cin >>item_1>>item_2;
        money = money+item_1+item_2;
        break;
    case 3:
        cin >>item_1>>item_2>>item_3;
        money = money+(item_1+item_2+item_3)*0.75;
        save = save+(item_1+item_2+item_3)*0.25;
        break;
    case 4:
        cin >>item_1>>item_2>>item_3>>item_4;
        money = money+(item_1+item_2+item_3+item_4)*0.75;
        save = save+(item_1+item_2+item_3+item_4)*0.25;
        break;
    case 5:
        cin >> item_1>>item_2>>item_3>>item_4>>item_5;
        money = money+(item_1+item_2+item_3+item_4+item_5)*0.75;
        save = save+(item_1+item_2+item_3+item_4+item_5)*0.25;
        break;
    default:
        break;
    }
    cout << "The customer needs to pay "<< money << " dollars, and save "<<save << " dollars!";

}
