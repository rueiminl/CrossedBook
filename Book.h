#pragma once
#include <string>
#include <memory>
#include <map>
class Order;
class Book : public std::enable_shared_from_this<Book> {
public:
    Book(std::string symbol);
    void AddOrder(int timestamp, std::shared_ptr<Order> order);
    void ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price);
    std::string str() const;
private:
    std::string m_symbol;
    std::string m_status;
    std::multimap<double, std::shared_ptr<Order> > m_bids;
    std::multimap<double, std::shared_ptr<Order>, std::greater<double> > m_asks;
};

std::ostream &operator<<(std::ostream &os, Book const &book);
