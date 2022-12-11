#include "range/v3/view/zip.hpp"
#include "graph.hpp"
#include "numeric_cost.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const NumericCost& numericCost)
{
    os << numericCost.cost;
    return os;
}

auto main() -> int {

    graph<int, NumericCost, 5> g;

    g.addEdge(0, 1, NumericCost{4});
    g.addEdge(0, 2, NumericCost{1});
    g.addEdge(1, 3, NumericCost{1});
    g.addEdge(2, 1, NumericCost{2});
    g.addEdge(2, 3, NumericCost{5});
    g.addEdge(3, 4, NumericCost{3});

    std::array<int, 5> v{0, 1, 2, 3, 4};
    auto d = dijkstra::shortestPath(g, 0);

    for (const auto& [vertex, distance] : ::ranges::views::zip(v, d)) {
        std::cout << vertex << " " << distance << std::endl;
    }
}
