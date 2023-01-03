#ifndef DIJKSTRA_NUMERIC_COST_HPP
#define DIJKSTRA_NUMERIC_COST_HPP

#include <iostream>

struct NumericCost
{
    static auto max_value()
    {
        return NumericCost{std::numeric_limits<int>::max()};
    }

    auto operator+(const NumericCost &other)
    {
        return NumericCost{cost + other.cost};
    }

    auto operator>(const NumericCost &other)
    {
        return cost > other.cost;
    }

    auto operator<(const NumericCost &other) const noexcept
    {
        return cost < other.cost;
    }

    auto operator!=(const NumericCost &other)
    {
        return cost != other.cost;
    }

    int cost{};
};

#endif  // DIJKSTRA_NUMERIC_COST_HPP
