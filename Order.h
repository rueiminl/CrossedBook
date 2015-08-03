#pragma once
#include <iostream>
#include <string>
#include <memory>
class Book;
class Order {
public:
    Order(int id);
    void SetSide(char side);
    void SetValue(int size, double price);
    void SetBook(std::shared_ptr<Book> book);
    std::shared_ptr<Book> GetBook() const;
    std::string str() const;
private:
    int m_id;
    char m_side;
    int m_size;
    double m_price;
    std::shared_ptr<Book> m_book;
};

std::ostream &operator<<(std::ostream &os, Order const &order);
