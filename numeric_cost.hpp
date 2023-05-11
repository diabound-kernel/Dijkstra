#pragma once

#include <iostream>

struct NumericCost
{
    static NumericCost max_value()
    {
        return NumericCost{std::numeric_limits<int>::max()};
    }

    friend NumericCost operator+(const NumericCost &lhs, const NumericCost &rhs)
    {
        return NumericCost{lhs.cost + rhs.cost};
    }

    friend bool operator>(const NumericCost &lhs, const NumericCost &rhs)
    {
        return lhs.cost > rhs.cost;
    }

    friend bool
    operator<(const NumericCost &lhs, const NumericCost &rhs) noexcept
    {
        return lhs.cost < rhs.cost;
    }

    friend bool operator!=(const NumericCost &lhs, const NumericCost &rhs)
    {
        return lhs.cost != rhs.cost;
    }

    int cost{};
};
