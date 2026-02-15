
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <crtdbg.h>

using std::cin;
using std::cout;
using std::endl;
constexpr int NAME_LENGTH = 20;
struct Edge {
    char begin[NAME_LENGTH];
    char end[NAME_LENGTH];
};
struct Graph {
    Edge* edges;
    int capacity = 0;
    int verticesCount=0;
    int edgeCount=0;
};
bool isEdgeExist(const Graph& graph, const Edge& edge) {
    for (int i = 0; i < graph.edgeCount; i++) {
        if (strcmp(edge.begin, graph.edges[i].begin) == 0
            && strcmp(edge.end, graph.edges[i].end) == 0) {
            return true;
        }
    }
    return false;
}

bool isValid(const Graph& graph, const Edge& edge) {
    if (strlen(edge.begin) > 10 || strlen(edge.end)> 10) {
        return false;
    }
    if (strcmp(edge.begin, edge.end) == 0) {
        return false;
    }
    if (isEdgeExist(graph, edge)) {
        return false;
    }
    return true;
}
void deleteGraph(Graph& graph) {
    delete[] graph.edges;
}
void resize(Graph& graph, int newSize) {
    Edge* temp = new Edge[newSize];
    for (int i = 0; i < graph.edgeCount; i++) {
        temp[i] = graph.edges[i];
    }
    deleteGraph(graph);
    graph.edges = temp;
    graph.capacity = newSize;
}
bool isNewVertice(const Graph& graph, const char* vertice) {
    for (int i = 0; i < graph.edgeCount; i++) {
        if (strcmp(graph.edges[i].begin, vertice) == 0
            || strcmp(graph.edges[i].end, vertice) == 0) {
            return false;
        }
    }
    return true;
}
void printEdge(const Edge& edge) {
    cout << edge.begin << " " << edge.end << endl;
}
void printGraph(const Graph& graph) {
    cout << "Edges: " << endl;
    for (int i = 0; i< graph.edgeCount; i++) {
        printEdge(graph.edges[i]);
    }
    cout << "Number of Vertices: " << graph.verticesCount<<endl;
}
void addEdge(Graph& graph, const char* start, const char* end) {
    Edge edge;
    strcpy(edge.begin, start);
    strcpy(edge.end,end);
    
    if (!isValid(graph, edge)) {
        return;
    }
    if (isNewVertice(graph, edge.begin)) {
        graph.verticesCount++;
    }
    if (isNewVertice(graph, edge.end)) {
        graph.verticesCount++;
    }
    if (graph.edgeCount >= graph.capacity) {
        int newSize = graph.edgeCount * 2;
        resize(graph, newSize);
    }
    
    graph.edges[graph.edgeCount] = edge;
    graph.edgeCount++;

}
int findDeg(const Graph& g, const char* vertex) {
    int degCounter = 0;
    for (int i = 0; i < g.edgeCount; i++) {
        if (strcmp(g.edges[i].begin, vertex) == 0) {
            degCounter++;
        }
    }
    return degCounter;
}
void initializeGraph(Graph& graph, const int m) {
    graph.capacity = m;
    graph.edges = new Edge[m];
    char start[NAME_LENGTH];
    char end[NAME_LENGTH];
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        addEdge(graph,start,end);
    }
}
int findIndexToRemove(const Graph& g, const Edge& edge) {
    for (int i = 0; i < g.edgeCount; i++) {
        if (strcmp(g.edges[i].begin, edge.begin) == 0
            && strcmp(g.edges[i].end, edge.end) == 0) {
            return i;
        }
    }
    return -1;
}
//If we want to preserve the order, otherwise we just swap the index with the last element
void remove(Graph& g, const Edge& edge) {
    if (!isEdgeExist(g, edge)) {
        cout << "Edge doesnt exist"<<endl;
        return;
    }
    int index = findIndexToRemove(g, edge);
    for (int i = index + 1; i < g.edgeCount; i++) {
        g.edges[i - 1] = g.edges[i];
    }

    g.edgeCount--;
    if (isNewVertice(g, edge.begin)) {
        g.verticesCount--;
    }
    if (isNewVertice(g, edge.end)) {
        g.verticesCount--;
    }

}
bool isComplete(const Graph& g) {
    if (g.verticesCount < 2) return false;
    return g.edgeCount == g.verticesCount * (g.verticesCount - 1);
}
int main()
{
    int command;
    int m;
    cout << "Enter Number of Edges: " << endl;
    cin >> m;
    Graph graph;
    initializeGraph(graph, m);
    while (true)
    {
        cout << "Choose Command:" << endl;
        cout << "1) - Add" << endl;
        cout << "2) - Find Deg" << endl;
        cout << "3) - Check is Graph Full" << endl;
        cout << "4) - Remove Edge" << endl;
        cout << "5) - Print Graph" << endl;
        cout << "9) - Exit" << endl;
        cin >> command;
        if (command == 9) {
            break;
        }
        else if (command == 1) {
            cout << "Enter Edge: " << endl;
            char start[NAME_LENGTH];
            char end[NAME_LENGTH];
            cin >> start >> end;
            addEdge(graph,start,end);
        }
        else if (command == 2) {
            char vertice[NAME_LENGTH];
            cout << "Enter Vertice Name\n";
            cin >> vertice;
            int degree = findDeg(graph, vertice);
            cout << "Degree of Vertice is: " << degree << endl;
        }
        else if (command == 3) {
            bool isFull = isComplete(graph);
            if (isFull) {
                cout << "Graph is Full" << endl;
            }
            else {
                cout << "Graph is not Full" << endl;
            }
        }
        else if (command == 4) {
            Edge edge;
            cout << "Enter Edge To Remove:\n";
            cin >> edge.begin;
            cin >> edge.end;
            remove(graph, edge);
        }
        else if (command == 5) {
            printGraph(graph);
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
    delete[] graph.edges;
}
