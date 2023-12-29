/*
Буйдина Кристина

Дан базовый интерфейс для представления ориентированного графа:
struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

Необходимо написать несколько реализаций интерфейса:
ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
        SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
ArcGraph, хранящий граф в виде одного массива пар {from, to}.
Также необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор должен скопировать переданный граф в создаваемый объект.
Для каждого класса создавайте отдельные h и cpp файлы.
Число вершин графа задается в конструкторе каждой реализации.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <functional>
#include <cassert>
#include "Graphs/IGraph.h"
#include "Graphs/ListGraph.h"
#include "Graphs/ArcGraph.h"
#include "Graphs/MatrixGraph.h"
#include "Graphs/SetGraph.h"


void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::function<void(int)> &func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void BFS(const IGraph &graph, std::function<void(int)> func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            BFS(graph, i, visited, func);
    }
}

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::function<void(int)> &func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, func);
    }
}

void DFS(const IGraph &graph, std::function<void(int)> func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            DFS(graph, i, visited, func);
    }
}

void topologicalSort(const IGraph &graph, int vertex, std::vector<bool> &visited, std::deque<int> &sorted)
{
    visited[vertex] = true;

    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            topologicalSort(graph, nextVertex, visited, sorted);
    }

    sorted.push_front(vertex);
}

std::deque<int> topologicalSort(const IGraph &graph)
{
    std::deque<int> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            topologicalSort(graph, i, visited, sorted);
    }

    return sorted;
}


int main() {
    ListGraph listGraph(9);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    listGraph.AddEdge(7, 8);

    ArcGraph arcGraph(listGraph);
    MatrixGraph matrixGraph(listGraph);
    SetGraph setGraph(matrixGraph);

    // Применение BFS, DFS и topologicalSort к каждому графу

    // ListGraph
    BFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    DFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    for (int vertex: topologicalSort(listGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;

    // ArcGraph
    BFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    DFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    for (int vertex: topologicalSort(arcGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;

    // MatrixGraph
    BFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    DFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    for (int vertex: topologicalSort(matrixGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;


    // SetGraph
    BFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    DFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    for (int vertex: topologicalSort(setGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;



    return 0;
}
