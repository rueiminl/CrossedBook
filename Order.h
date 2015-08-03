#pragma once
class Order {
public:
    Order(int id);
    void SetSide(char side);
    void SetValue(int size, double price);
private:
    int m_id;
    char m_side;
    int m_size;
    double m_price;
};