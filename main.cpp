#include "graph.hpp"

#include <iostream>
#include <ranges>

auto main() -> int {

    graph<int, 5> g;

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    std::array<int, 5> v{0, 1, 2, 3, 4};
    auto d = dijkstra::shortestPath(g, 0);

    for (const auto& [vertex, distance] : std::views::zip(v, d)) {
        std::cout << vertex << " " << distance << std::endl;
    }
}
