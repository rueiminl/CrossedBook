#include "BookManager.h"
#include "Order.h"
#include "Book.h"
#include <iostream>
using namespace std;

BookManager::BookManager()
{
}

void BookManager::AddOrder(int timestamp, char side, string symbol, int size, double price, int order_id) {
    auto book = GetBook(symbol);
    auto order = GetOrder(order_id);
    order->SetSide(side);
    order->SetValue(size, price);
    book->AddOrder(timestamp, order);
}
void BookManager::ModifyOrder(int timestamp, int order_id, int size, double price) {
    auto book = GetBook(order_id);
    auto order = GetOrder(order_id);
    book->ModifyOrder(timestamp, order, size, price);
}

std::shared_ptr<Order> BookManager::GetOrder(int order_id) {
    if (m_orderIndex.find(order_id) == m_orderIndex.end()) {
        m_orderIndex.insert(make_pair(order_id, make_shared<Order>(order_id)));
    }
    return m_orderIndex[order_id];
}

std::shared_ptr<Book> BookManager::GetBook(string symbol) {
    if (m_bookIndex.find(symbol) == m_bookIndex.end()) {
        m_bookIndex.insert(make_pair(symbol, make_shared<Book>(symbol)));
    }
    return m_bookIndex[symbol];
}

std::shared_ptr<Book> BookManager::GetBook(int order_id) {
    return GetOrder(order_id)->GetBook();
}

