#include "SetGraph.h"

#include <queue>

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySets.size());
    std::vector<int> next_v(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
    return next_v;
}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencySets.size());
    assert(0 <= to && to < adjacencySets.size());
    adjacencySets[from].insert(to);
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySets.size());
    std::vector<int> prev_v;
    for (int from = 0; from < adjacencySets.size(); from++){
        if (adjacencySets[from].count(vertex)){
            prev_v.push_back(from);
        }
    }
    return prev_v;
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacencySets.size());
}

SetGraph::SetGraph(int size) : adjacencySets(size) {}

SetGraph::SetGraph(const IGraph &graph) : adjacencySets(graph.VerticesCount()){
    for (int i = 0; i < graph.VerticesCount(); i++){
        for (int j: graph.GetNextVertices(i)){
            adjacencySets[i].insert(j);
        }
    }
}

SetGraph::~SetGraph() noexcept = default;

