#pragma once
#include <string>
#include <memory>
#include <vector>
#include <queue>
#include <unordered_map>
class Order;
class Book : public std::enable_shared_from_this<Book> {
public:
    Book(std::string symbol);
    void AddOrder(std::shared_ptr<Order> order);
    void ModifyOrder(std::shared_ptr<Order> order, int timestamp, int size, double price);
private:
    std::shared_ptr<Order> GetOrder(int order_id);
    double GetBestBid();
    double GetBestAsk();
    void CheckStatus(int timestamp);
    void Output(int timestamp, double best_bid, double best_ask);
    void Output(int timestamp);
    void Normal(int timestamp);
    void Lock(int timestamp, double best_bid, double best_ask);
    void Cross(int timestamp, double best_bid, double best_ask);
    std::string m_symbol;
    std::string m_status;
    typedef std::pair<double, std::pair<int,int> > Tuple;
    std::priority_queue<Tuple, std::vector<Tuple> > m_bids;
    std::priority_queue<Tuple, std::vector<Tuple>, std::greater<Tuple> > m_asks;
    std::unordered_map<int, std::shared_ptr<Order> > m_orderIndex;
};
