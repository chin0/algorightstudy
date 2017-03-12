#include "adjacencyList.h"

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = NULL;
    graph->VertexCount = 0;
    return graph;
}

void DestroyGraph(Graph* G)
{
    while(G->Vertices != NULL)
    {
        Vertex* Vertices = G->Vertices->Next;
        DestroyVertex(G->Vertices);
        G->Vertices = Vertices;
    }
    free(G);
}

Vertex* CreateVertex(ElementType Data)
{
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));

    V->Data = Data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex(Vertex* V)
{
    while(V->AdjacencyList != NULL)
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge(V->AdjacencyList);
        
        V->AdjacencyList = Edge;
    }

    free(V);
}

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight)
{
    Edge* E = (Edge*)malloc(sizeof(Edge));
    E->From = From;
    E->Target = Target;
    E->Next = NULL;
    E->Weight = Weight;

    return E;
}



    

