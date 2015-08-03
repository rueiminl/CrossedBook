#include "Book.h"
#include "Order.h"
#include <iostream>
using namespace std;

Book::Book(string symbol)
: m_symbol(symbol)
{
}

void Book::AddOrder(int timestamp, shared_ptr<Order> order) {
    cout << "Book::AddOrder:" << timestamp << " " << order->side << " " << order->size << " " << order->price << " " << order->id << endl;
}
}

void Book::ModifyOrder(int timestamp, int order_id,  int size, double price) {
    cout << "Book::ModifyOrder:" << timestamp << " " << order_id << " " << size << " " << price << endl;
}
