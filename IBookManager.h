#pragma once
#include <string>
#include <memory>

class IBookManager {
public:
    static std::shared_ptr<IBookManager> create();
    virtual void AddOrder(int timestamp, std::string symbol, char side, int size, double price, int order_id) = 0;
    virtual void ModifyOrder(int timestamp, int order_id, int size, double price) = 0;
};