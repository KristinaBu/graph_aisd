#include <queue>
#include "MatrixGraph.h"


std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> next_v;
    for (int to = 0; to < matrix.size(); to++){
        if (matrix[vertex][to]){
            next_v.push_back(to);
        }
    }
    return next_v;
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < matrix.size());
    assert(0 <= to && to < matrix.size());
    matrix[from][to] = true;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < matrix.size());
    std::vector<int> prev_v;
    for (int from = 0; from < matrix.size(); from++){
        if (matrix[from][vertex]){
            prev_v.push_back(from);
        }
    }
    return prev_v;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix.size());
}

MatrixGraph::MatrixGraph(int size) {
    matrix.reserve(size);
    for (int i = 0; i < size; i++)
        matrix.emplace_back(size);

}


MatrixGraph::MatrixGraph(const IGraph &graph) : matrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)){
    for (int i = 0; i < graph.VerticesCount(); i++)
        for (int j: graph.GetNextVertices(i))
            matrix[i][j] = true;


}

MatrixGraph::~MatrixGraph() noexcept = default;


