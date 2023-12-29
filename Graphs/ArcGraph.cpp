#include "ArcGraph.h"

#include <cassert>
#include <unordered_set>
#include "IGraph.h"


std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < VerticesCount());
    std::vector<int> next_v;
    for (const auto& pair : pairs){
        if (pair.first == vertex){
            next_v.push_back(pair.second);
        }
    }
    return next_v;
}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < VerticesCount());
    assert(0 <= to && to < VerticesCount());
    pairs.insert({from, to});
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < VerticesCount());
    std::vector<int> prev_v;
    for (const auto& pair : pairs){
        if (pair.second == vertex){
            prev_v.push_back(pair.first);
        }
    }
    return prev_v;
}


int ArcGraph::VerticesCount() const {
    std::unordered_set<int> vertices;
    for (const auto& [from, to] : pairs) {
        vertices.insert(from);
        vertices.insert(to);
    }
    return vertices.size();
}
ArcGraph::ArcGraph(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            pairs.insert({i, j});
        }
    }
}


ArcGraph::ArcGraph(const IGraph &graph) {
    for (int i = 0; i < graph.VerticesCount(); i++){
        for (int j: graph.GetNextVertices(i)){
            pairs.insert({i, j});
        }
    }
}

ArcGraph::~ArcGraph() noexcept = default;
