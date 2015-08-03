#pragma once
#include <string>
#include <memory>
#include <map>
#include <unordered_map>
class Order;
class Book : public std::enable_shared_from_this<Book> {
public:
    Book(std::string symbol);
    void AddOrder(int timestamp, std::shared_ptr<Order> order);
    void ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price);
    std::string str() const;
private:
    void CheckStatus(int timestamp);
    void Output(int timestamp, double best_bid, double best_ask);
    void Output(int timestamp);
    void Normal(int timestamp);
    void Lock(int timestamp, double best_bid, double best_ask);
    void Cross(int timestamp, double best_bid, double best_ask);
    std::string m_symbol;
    std::string m_status;
    std::map<std::pair<double,int>, std::shared_ptr<Order>, std::greater<std::pair<double,int> > > m_bids;
    std::map<std::pair<double,int>, std::shared_ptr<Order> > m_asks;
};

std::ostream &operator<<(std::ostream &os, Book const &book);
