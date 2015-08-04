#include "Book.h"
#include "Order.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

Book::Book(string symbol)
: m_symbol(symbol)
, m_status("normal")
{
}

void Book::AddOrder(shared_ptr<Order> order) {
    order->SetBook(shared_from_this());
    double price = order->GetPrice();
    int id = order->GetID();
    m_orderIndex[id] = order;
    int timestamp = order->GetTimestamp();
    if (order->GetSide() == 'A') {
        m_asks.push(make_pair(price, make_pair(id, timestamp)));
    } else {
        m_bids.push(make_pair(price, make_pair(id, timestamp)));
    }
    CheckStatus(timestamp);
}

void Book::ModifyOrder(std::shared_ptr<Order> order, int timestamp, int size, double price) {
    int id = order->GetID();
    order->SetValue(timestamp, size, price);
    if (order->GetSide() == 'A') { // ask
        if (size)
            m_asks.push(make_pair(price, make_pair(id, timestamp)));
    } else { // bid
        if (size)
            m_bids.push(make_pair(price, make_pair(id, timestamp)));
    }
    CheckStatus(timestamp);
}

double Book::GetBestBid() {
    while (!m_bids.empty()) {
        auto top = m_bids.top();
        auto id = top.second.first;
        auto timestamp = top.second.second;
        if (GetOrder(id)->GetTimestamp() == timestamp)
            return top.first;
        // else the top is invalid
        m_bids.pop();
    }
    return std::numeric_limits<double>::min();
}

double Book::GetBestAsk() {
    while (!m_asks.empty()) {
        auto top = m_asks.top();
        auto id = top.second.first;
        auto timestamp = top.second.second;
        if (GetOrder(id)->GetTimestamp() == timestamp)
            return top.first;
        // else the top is invalid
        m_asks.pop();
    }
    return std::numeric_limits<double>::max();
}

void Book::CheckStatus(int timestamp) {
    auto best_bid = GetBestBid();
    auto best_ask = GetBestAsk();
    if (best_ask > best_bid) {
        Normal(timestamp);
    } else if (best_ask < best_bid) {
        Cross(timestamp, best_bid, best_ask);
    } else { // best_ask == best_bid
        Lock(timestamp, best_bid, best_ask);
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

shared_ptr<Order> Book::GetOrder(int order_id) {
    return m_orderIndex[order_id];
}

