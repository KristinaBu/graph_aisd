#ifndef GRAPH_AISD_SETGRAPH_H
#define GRAPH_AISD_SETGRAPH_H


#include <cassert>
#include <set>
#include "IGraph.h"

struct SetGraph: public IGraph {
public:
    explicit SetGraph(int size);
    explicit SetGraph(const IGraph &graph);

    ~SetGraph() override;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> adjacencySets;
};


#endif //GRAPH_AISD_SETGRAPH_H
