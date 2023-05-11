#pragma once

#include <array>
#include <limits>
#include <set>
#include <vector>

template<typename T, typename Cost, std::size_t N>
struct Graph
{
    using vertex_type = T;
    using cost_type = Cost;

    Graph() = default;
    ~Graph() = default;

    void addEdge(const T &fVertex, const T &tVertex, const Cost &cost)
    {
        adjacencyList[fVertex].push_back(std::make_pair(tVertex, cost));
    }

    std::size_t size() const
    {
        return adjacencyList.size();
    }

    std::array<std::vector<std::pair<T, Cost>>, N> adjacencyList{};
};

struct Dijkstra
{
    template<typename Graph>
    static std::vector<typename Graph::cost_type> shortestPath(
        const Graph &graph, const typename Graph::vertex_type &startVertex)
    {
        const auto infinitive = Graph::cost_type::max_value();

        std::vector<typename Graph::cost_type> distance(
            graph.size(), infinitive);

        std::set<
            std::pair<typename Graph::vertex_type, typename Graph::cost_type>>
            vertexQueue;

        vertexQueue.insert(std::pair(startVertex, typename Graph::cost_type()));
        distance[startVertex] = typename Graph::cost_type();

        while (!vertexQueue.empty()) {
            auto currVertex = vertexQueue.begin()->first;

            vertexQueue.erase(vertexQueue.begin());

            for (const auto &[vertex, cost] : graph.adjacencyList[currVertex]) {

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
