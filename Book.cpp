#include "Book.h"
#include "Order.h"
#include <iostream>
using namespace std;

Book::Book(string symbol)
: m_symbol(symbol)
{
}

void Book::AddOrder(int timestamp, shared_ptr<Order> order) {
    order->SetBook(shared_from_this());
    cout << "Book::AddOrder:" << timestamp << " " << *order << endl;
}

void Book::ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price) {
    cout << "Book::ModifyOrder:" << timestamp << " " << *order << " " << size << " " << price << endl;
}
