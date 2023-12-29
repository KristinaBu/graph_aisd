#ifndef GRAPH_AISD_MATRIXGRAPH_H
#define GRAPH_AISD_MATRIXGRAPH_H


#include <cassert>
#include "IGraph.h"

struct MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(int size);
    explicit MatrixGraph(const IGraph &graph);

    ~MatrixGraph() override;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<bool>> matrix;
};



#endif //GRAPH_AISD_MATRIXGRAPH_H
