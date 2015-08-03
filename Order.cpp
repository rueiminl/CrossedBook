#include "Order.h"
#include <string>
#include <iostream>
using namespace std;

Order::Order(int id)
: m_id(id)
{}

void Order::SetSide(char side) {
    m_side = side;
}
void Order::SetValue(int size, double price) {
    m_size = size;
    m_price = price;
}

void Order::SetBook(std::shared_ptr<Book> book) {
    m_book = book;
}

std::shared_ptr<Book> Order::GetBook() const {
    return m_book;
}

string Order::str() const {
    string s;
    s += to_string(m_id);
    s.push_back(' ');
    s.push_back(m_side);
    s.push_back(' ');
    s += to_string(m_size);
    s.push_back(' ');
    s += to_string(m_price);
    return s;
}

std::ostream &operator<<(std::ostream &os, Order const &order) {
    return os << order.str();
}