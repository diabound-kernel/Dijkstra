#ifndef DIJKSTRA_GRAPH_HPP
#define DIJKSTRA_GRAPH_HPP

#include <array>
#include <list>
#include <set>
#include <vector>
#include <limits>

template<typename T, typename Cost, std::size_t N>
struct graph
{
    using vertex_type = T;
    using cost_type = Cost;

    graph() = default;
    ~graph() = default;

    void addEdge(const T& fVertex, const T& tVertex, Cost cost)
    {
        adjacencyList[fVertex].push_back(std::make_pair(tVertex, cost));
    }

    std::size_t size() const
    {
        return adjacencyList.size();
    }

    std::array<std::list<std::pair<T, Cost>>, N> adjacencyList{};
};

struct dijkstra
{
    template<typename Graph>
    static auto shortestPath(const Graph& graph, const typename Graph::vertex_type& startVertex)
    {
        const auto infinitive = Graph::cost_type::max_value();
        std::vector<typename Graph::cost_type> distance(graph.size(), infinitive);
        std::set<std::pair<typename Graph::vertex_type, typename Graph::cost_type>> vertexQueue;

        vertexQueue.insert(std::pair(startVertex, typename Graph::cost_type()));
        distance[startVertex] = typename Graph::cost_type();

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
