#include "graph.hpp"
#include "numeric_cost.hpp"

#include "range/v3/view/zip.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, const NumericCost &numericCost)
{
    os << numericCost.cost;
    return os;
}

int main()
{
    Graph<int, NumericCost, 5> graph;

    graph.addEdge(0, 1, NumericCost{4});
    graph.addEdge(0, 2, NumericCost{1});
    graph.addEdge(1, 3, NumericCost{1});
    graph.addEdge(2, 1, NumericCost{2});
    graph.addEdge(2, 3, NumericCost{5});
    graph.addEdge(3, 4, NumericCost{3});

    std::array<int, 5> vertices{0, 1, 2, 3, 4};

    auto distances = Dijkstra::shortestPath(graph, 0);

    for (const auto &[vertex, distance] :
         ::ranges::views::zip(vertices, distances)) {
        std::cout << vertex << " " << distance << std::endl;
    }
}
