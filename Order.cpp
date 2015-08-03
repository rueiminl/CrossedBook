#include "Order.h"

Order::Order(int id)
: m_id(id)
{}

void Order::SetSide(char side) {
    m_side = side;
}
void Order::SetValue(int size, double price) {
    m_size = size;
    m_price = price;
}
