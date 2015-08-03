#include "BookManager.h"
#include <iostream>
using namespace std;

BookManager::BookManager()
{}

void BookManager::AddOrder(int timestamp, string symbol, char type, int size, double price, int order_id) {
    cout << "AddOrder:" << timestamp << " " << symbol << " " << type << " " << size << " " << price << " " << order_id << endl;
}
void BookManager::ModifyOrder(int timestamp, int order_id, int size, double price) {
    cout << "ModifyOrder:" << timestamp << " " << order_id << " " << size << " " << price << endl;
}
