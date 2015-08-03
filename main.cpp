#include "IBookManager.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    auto manager = IBookManager::create();
    while (cin.good()) {
        int timestamp;
        char type; // 'A': add; 'M': modify
        string symbol;
        char side; // 'A': ask; 'B': bid
        int order_id;
        int size;
        double price;
        cin >> timestamp >> type;
        if (type == 'A') {
            cin >> symbol >> side >> size >> price >> order_id;
            manager->AddOrder(timestamp, symbol, side, size, price, order_id);
        } else {
            cin >> order_id >> size >> price;
            manager->ModifyOrder(timestamp, order_id, size, price);
        }
    }
    return 0;
}