#include "Book.h"
#include "Order.h"
#include <iostream>
#include <sstream>
using namespace std;

Book::Book(string symbol)
: m_symbol(symbol)
, m_status("normal")
{
}

void Book::AddOrder(int timestamp, shared_ptr<Order> order) {
    order->SetBook(shared_from_this());
    double price = order->GetPrice();
    if (order->GetSide() == 'A') {
        m_asks.insert(make_pair(price, order));
    } else {
        m_bids.insert(make_pair(price, order));
    }
    cout << *this << endl;
}

void Book::ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price) {
    order->SetValue(size, price);
    cout << "Book::ModifyOrder:" << timestamp << " " << *order << " " << size << " " << price << endl;
}

std::string Book::str() const {
    stringstream ss;
    for (auto ask : m_asks) {
        ss << *ask.second << endl;
    }
    for (auto bid : m_bids) {
        ss << *bid.second << endl;
    }
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, Book const &book) {
    return os << book.str();
}

