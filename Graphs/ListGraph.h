#ifndef GRAPH_AISD_LISTGRAPH_H
#define GRAPH_AISD_LISTGRAPH_H


#include <cassert>
#include "IGraph.h"

struct ListGraph: public IGraph
{
public:
    explicit ListGraph(int size);
    explicit ListGraph(const IGraph &graph);


    ~ListGraph() override;

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;

    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif //GRAPH_AISD_LISTGRAPH_H
