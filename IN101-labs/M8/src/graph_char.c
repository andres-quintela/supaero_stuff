#include <stdio.h>
#include <stdlib.h>

#include "graph_char.h"

// auxiliary functions
void print_edge(edge *p_edge) {
    printf("    ");
    printf("(%c): %d\n", p_edge->p_destination->id,
           p_edge->weight);
}

void print_vertex(vertex *p_vertex) {
    printf("(%c):\n", p_vertex->id);

    for (int i = 0; i < p_vertex->adjacency_size; i++) {
        print_edge(p_vertex->adjacency_array[i]);
    }
}


// functions from the signature
void create_empty_graph(graph **p_p_graph) {
    *p_p_graph = malloc(sizeof(graph));

    if (p_p_graph == NULL) {
        printf("cannot allocate memory for graph in "
               "create_empty_graph!\n");
    }

    (*p_p_graph)->vertices_nb = 0;
}

void add_vertex(graph *p_graph, char id) {
    vertex *p_new_vertex = malloc(sizeof(vertex));

    if (p_new_vertex == NULL) {
        printf("cannot allocate memory for vertex in "
               " add_vertex!\n");
    }

    p_new_vertex->id             = id;
    p_new_vertex->adjacency_size = 0;
    p_new_vertex->distance       = 0;
    p_new_vertex->p_pred         = NULL;

    p_graph->vertices_array[p_graph->vertices_nb] = p_new_vertex;
    p_graph->vertices_nb = p_graph->vertices_nb + 1;
}

vertex *get_vertex(graph *p_graph, char id) {
    return NULL;
}

void add_edge(graph *p_graph, char id_source, char id_dest, int weight) {

}

void dijkstra(graph *p_graph, char id_source) {

}

void print_graph(graph *p_graph) {
    for (int i = 0; i < p_graph->vertices_nb; i++) {
        print_vertex(p_graph->vertices_array[i]);
    }
}

void deallocate_graph(graph *p_graph) {

}
