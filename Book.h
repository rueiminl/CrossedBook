#pragma once
#include <string>
#include <memory>
class Order;
class Book : public std::enable_shared_from_this<Book> {
public:
    Book(std::string symbol);
    void AddOrder(int timestamp, std::shared_ptr<Order> order);
    void ModifyOrder(int timestamp, std::shared_ptr<Order> order, int size, double price);
private:
    std::string m_symbol;
};