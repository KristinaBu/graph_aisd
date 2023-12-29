#ifndef GRAPH_AISD_ARCGRAPH_H
#define GRAPH_AISD_ARCGRAPH_H

#include <cassert>
#include <set>
#include "IGraph.h"

struct ArcGraph: public IGraph {
public:
    explicit ArcGraph(int size);
    explicit ArcGraph(const IGraph &graph);

    ~ArcGraph() override;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::set<std::pair<int, int>> pairs;
};



#endif //GRAPH_AISD_ARCGRAPH_H
