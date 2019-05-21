#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph_char.h"

void simple_id_retrieval_test(graph *p_graph, char id) {
    vertex *p_vertex = get_vertex(p_graph, id);

    assert (p_vertex != NULL);
    assert (p_vertex->id == id);
}

void simple_id_retrieval_test_ko(graph *p_graph, char id) {
    assert (get_vertex(p_graph, id) == NULL);
}

void print_shortest_path(graph *p_graph, char id_source, char id_dest) {
    vertex *path[p_graph->vertices_nb];
    int path_size = 0;

    vertex *p_current_vertex = get_vertex(p_graph, id_dest);
    int distance             = p_current_vertex->distance;

    if (p_current_vertex->p_pred == NULL) {
        printf("No path from %c to %c!\n", id_source, id_dest);
        return;
    }

    while (p_current_vertex != NULL) {
        path[path_size]  = p_current_vertex;
        path_size        = path_size + 1;
        p_current_vertex = p_current_vertex->p_pred;
    }

    for (int i = path_size - 1; i >= 0; i--) {
        printf("(%c)%s", path[i]->id,
               i == 0 ? "" : " -> ");
    }


    printf("\nPath size: %d\n", distance);
}

int main(void) {
    graph *p_graph = NULL;

    create_empty_graph(&p_graph);

    add_vertex(p_graph, 'A');
    add_vertex(p_graph, 'B');
    add_vertex(p_graph, 'C');
    add_vertex(p_graph, 'D');
    add_vertex(p_graph, 'E');
    add_vertex(p_graph, 'F');

    printf("Printing graph without edges: \n");
    print_graph(p_graph);

    simple_id_retrieval_test(p_graph, 'A');
    simple_id_retrieval_test(p_graph, 'B');
    simple_id_retrieval_test(p_graph, 'C');
    simple_id_retrieval_test(p_graph, 'D');
    simple_id_retrieval_test(p_graph, 'E');
    simple_id_retrieval_test(p_graph, 'F');

    simple_id_retrieval_test_ko(p_graph, 'G');

    add_edge(p_graph, 'A', 'B', 4);
    add_edge(p_graph, 'A', 'C', 2);
    add_edge(p_graph, 'B', 'C', 3);
    add_edge(p_graph, 'B', 'D', 2);
    add_edge(p_graph, 'B', 'E', 3);
    add_edge(p_graph, 'C', 'B', 1);
    add_edge(p_graph, 'C', 'D', 4);
    add_edge(p_graph, 'C', 'E', 5);
    add_edge(p_graph, 'E', 'D', 1);
    add_edge(p_graph, 'F', 'D', 2);

    printf("\nPrinting graph with edges: \n");
    print_graph(p_graph);

    printf("\nDijkstra with node A as source\n");
    dijkstra(p_graph, 'A');

    for (char c = 'A'; c <= 'F'; c++) {
        printf("\nShortest path between A and %c\n", c);
        print_shortest_path(p_graph, 'A', c);
    }

    printf("\nDijkstra with node C as source\n");
    dijkstra(p_graph, 'C');

    for (char c = 'A'; c <= 'F'; c++) {
        printf("\nShortest path between C and %c\n", c);
        print_shortest_path(p_graph, 'C', c);
    }

    printf("\nDeallocation\n");
    deallocate_graph(p_graph);
    p_graph = NULL;
}
