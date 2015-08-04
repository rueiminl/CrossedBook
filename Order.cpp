#include "Order.h"
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

void Order::SetBook(shared_ptr<Book> book) {
    m_book = book;
}

int Order::GetID() const {
    return m_id;
}

char Order::GetSide() const {
    return m_side;
}

double Order::GetPrice() const {
    return m_price;
}

shared_ptr<Book> Order::GetBook() const {
    return m_book;
}
