#include <iostream>

void encryption (int &data, int key, int mod) { // YOU ALSO NEED TO FILL IN THIS BLANK
    // DON'T REMOVE THIS LINE
    // YOU CAN ONLY WRITE HERE!!!
    // CODE BEGIN
    int cpy = 1;
    for (int i = 0; i < key; i++) {
        cpy = (cpy * data) % mod;
    }
    data = cpy;
    // CODE END
    // DON'T REMOVE THIS LINE
}

int main (void) {
    int data, key, mod;

    std::cout << "Please enter the data: ";
    std::cin >> data;
    std::cout << "Please enter the key: ";
    std::cin >> key;
    std::cout << "Please enter the mod: ";
    std::cin >> mod;

    std::cout << "Before encrypted, data is = " << data << std::endl;
    encryption(data, key, mod); // YOU ALSO NEED TO FILL IN THIS BLANK
    std::cout << "After encrypted, data is = " << data << std::endl;

    return 0;
}
