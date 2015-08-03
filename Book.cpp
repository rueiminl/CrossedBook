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
    if (m_status == "normal" && !m_asks.empty() && !m_bids.empty()) {
        auto best_bid = m_bids.begin()->first;
        auto best_ask = m_asks.begin()->first;
        if (best_ask == best_bid) {
            Lock(timestamp, best_bid, best_ask);
        } else if (best_ask < best_bid) {
            Cross(timestamp, best_bid, best_ask);
        }
    }
}

void Book::ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price) {
    order->SetValue(size, price);
    cout << "Book::ModifyOrder:" << timestamp << " " << *order << " " << size << " " << price << endl;
}

void Book::Output(int timestamp, double best_bid, double best_ask) {
    cout << timestamp << " " << m_symbol << " " << m_status << " " << best_bid << " " << best_ask << endl;
}

void Book::Lock(int timestamp, double best_bid, double best_ask) {
    m_status = "locked";
    Output(timestamp, best_bid, best_ask);
}

void Book::Cross(int timestamp, double best_bid, double best_ask) {
    m_status = "crossed";
    Output(timestamp, best_bid, best_ask);
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

