#pragma once
#include "IBookManager.h"
#include <unordered_map>
class Order;
class Book;
class BookManager : public IBookManager {
public:
    BookManager();
    virtual void AddOrder(int timestamp, char side, std::string symbol, int size, double price, int order_id);
    virtual void ModifyOrder(int timestamp, int order_id, int size, double price);
private:
    std::shared_ptr<Order> GetOrder(int order_id);
    std::shared_ptr<Book> GetBook(std::string symbol);
    std::shared_ptr<Book> GetBook(int order_id);
    std::unordered_map<int, std::shared_ptr<Order> > m_orderIndex;
    std::unordered_map<std::string, std::shared_ptr<Book> > m_bookIndex;
};