#pragma once
#include <string>
#include <memory>
class Book;
class Order {
public:
    Order(int id);
    void SetSide(char side);
    void SetValue(int timestamp, int size, double price);
    void SetBook(std::shared_ptr<Book> book);
    int GetID() const;
    char GetSide() const;
    int GetTimestamp() const;
    double GetPrice() const;
    std::shared_ptr<Book> GetBook() const;
private:
    int m_id;
    char m_side;
    int m_size;
    double m_price;
    int m_timestamp;
    std::shared_ptr<Book> m_book;
};
