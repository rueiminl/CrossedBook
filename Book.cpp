#include "Book.h"
#include "Order.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Book::Book(string symbol)
: m_symbol(symbol)
, m_status("normal")
{
}

void Book::AddOrder(int timestamp, shared_ptr<Order> order) {
    order->SetBook(shared_from_this());
    double price = order->GetPrice();
    int id = order->GetID();
    if (order->GetSide() == 'A') {
        m_asks.insert(make_pair(make_pair(price, id), order));
    } else {
        m_bids.insert(make_pair(make_pair(price, id), order));
    }
    CheckStatus(timestamp);
}

void Book::ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price) {
    int id = order->GetID();
    double oldPrice = order->GetPrice();
    order->SetValue(size, price);
    if (order->GetSide() == 'A') {
        m_asks.erase(make_pair(oldPrice, id));
        if (size)
            m_asks.insert(make_pair(make_pair(price, id), order));
    } else {
        m_bids.erase(make_pair(oldPrice, id));
        if (size)
            m_bids.insert(make_pair(make_pair(price, id), order));
    }
    CheckStatus(timestamp);
}

void Book::CheckStatus(int timestamp) {
    if (!m_asks.empty() && !m_bids.empty()) {
        auto best_bid = m_bids.begin()->first.first;
        auto best_ask = m_asks.begin()->first.first;
        if (best_ask > best_bid) {
            Normal(timestamp);
        } else if (best_ask < best_bid) {
            Cross(timestamp, best_bid, best_ask);
        } else { // best_ask == best_bid
            Lock(timestamp, best_bid, best_ask);
        }
    } else {
        Normal(timestamp);
    }
}

void Book::Output(int timestamp, double best_bid, double best_ask) {
    cout << timestamp << " " << m_symbol << " " << m_status << " ";
    cout.setf(ios::fixed);
    cout << setprecision(4) << best_bid << " " << best_ask << endl;
}
void Book::Output(int timestamp) {
    cout << timestamp << " " << m_symbol << " " << m_status << endl;
}

void Book::Normal(int timestamp) {
    if (m_status != "normal") {
        m_status = "normal";
        Output(timestamp);
    }
}
void Book::Lock(int timestamp, double best_bid, double best_ask) {
    if (m_status == "normal") {
        m_status = "locked";
        Output(timestamp, best_bid, best_ask);
    }
}

void Book::Cross(int timestamp, double best_bid, double best_ask) {
    if (m_status == "normal") {
        m_status = "crossed";
        Output(timestamp, best_bid, best_ask);
    }
}

