#ifndef DIJKSTRA_GRAPH_HPP
#define DIJKSTRA_GRAPH_HPP

#include <array>
#include <list>
#include <set>
#include <vector>
#include <limits>

template<typename T, std::size_t N>
struct graph
{
    using vertex_type = T;

    graph() = default;
    ~graph() = default;

    void addEdge(T fVertex, T tVertex, int cost)
    {
        adjacencyList[fVertex].push_back(std::make_pair(tVertex, cost));
    }

    std::size_t size()
    {
        return adjacencyList.size();
    }

    std::array<std::list<std::pair<T, int>>, N> adjacencyList{};
};

struct dijkstra
{
    template<typename Graph>
    static auto shortPath(Graph graph, typename Graph::vertex_type startVertex)
    {
        const auto infinitive = std::numeric_limits<int>::max();
        std::vector<int> distance(graph.size(), infinitive);
        std::set<std::pair<typename Graph::vertex_type, int>> vertexQueue;

        vertexQueue.insert(std::pair(startVertex, 0));
        distance[startVertex] = 0;

        while (!vertexQueue.empty()) {
            auto currVertex = vertexQueue.begin()->first;

            vertexQueue.erase(vertexQueue.begin());

            for (const auto& [vertex, cost] : graph.adjacencyList[currVertex]) {

                if (distance[vertex] > distance[currVertex] + cost) {

                    if (distance[vertex] != infinitive) {
                        vertexQueue.erase(std::pair{vertex, distance[vertex]});
                    }

                    distance[vertex] = distance[currVertex] + cost;
                    vertexQueue.insert(std::pair{vertex, distance[vertex]});
                }
            }
        }

        return distance;
    }
};


#endif //DIJKSTRA_GRAPH_HPP
