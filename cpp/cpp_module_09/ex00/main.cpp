#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file" << std::endl;
        return 1;
    }
    Btc btc; 
    if (!btc.getReadFlag())
        return 1;
    btc.readData(av[1]);

}