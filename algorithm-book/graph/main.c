#include "adjacencyArray.h"

int main(void)
{
    array_graph* graph = create_graph(10);

    add_vertex(graph,"chino");
    add_vertex(graph,"megu");
    add_vertex(graph,"maya");
    
    add_edge(graph,0,2);
    add_edge(graph,0,1);
    add_edge(graph,1,2);

    display_edge(graph);

    remove_vertex(graph,1);
    display_edge(graph);


}
    
    
