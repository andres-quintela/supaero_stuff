/**
 * @file graph_char.h
 *
 * @brief Simple definition of graphs with vertices containing `char` values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a graph containing `char`
 * values implemented using adjacency lists represented by arrays.
 * Warning: the vertices pointers should not be shared as deallocation
 * of a graph deallocates the memory space reserved for the vertices!
 *
 * The API of the graph is defined as follows:
 *
 * - a function to create an empty graph
 * - a function to add a vertex
 * - a function to get a pointer to a vertex
 * - a function to add an edge
 * - a function to compute shortest paths from a given vertex to all
 *   other vertices in the graph
 * - a function to print a graph
 * - a function to deallocate a graph
 */

#ifndef GRAPH_CHAR_H
#define GRAPH_CHAR_H

/** The maximum number of vertices in the graph. */
#define MAX_VERTICES_NB  100

/** The maximum number of neighbors for a vertex. */
#define MAX_NEIGHBORS_NB 100

/** A constant representing infinity */
#define INFINITY         1000000

/**
 * @brief An alias to the struct representing the graph.
 */
typedef struct graph  graph;

/**
 * @brief An alias to the struct representing the vertices.
 */
typedef struct vertex vertex;

/**
 * @brief An alias to the struct representing the edges.
 */
typedef struct edge   edge;

/**
 * @brief The structure representing the edges of the
 *        graph.
 */
struct edge {
    /** The weight associated to the edge */
    int     weight;
    /** The destination vertex associated to the edge */
    vertex *p_destination;
};

/**
 * @brief The structure representing the vertices of the
 *        graph.
 */
struct vertex {
    /** An `char` value representing the id of the vertex */
    char    id;

    /** An array containing pointers to edges representing the
     * adjacency list of the vertex. */
    edge   *adjacency_array[MAX_NEIGHBORS_NB];

    /** The size of the list, i.e. the index from which the vertices
     * in the array are not necessary neighbors of the vertex.*/
    int     adjacency_size;

    /** The minimum distance from the source vertex. May change when
     * Disjkstra's algorithm is called. */
    int     distance;

    /** The predecessor in the shortest path from the source vertex.
     * May change when Disjkstra's algorithm is called.*/
    vertex *p_pred;
};

/**
 * @brief The structure representing the graph.
 */
struct graph {
    /** The list of vertices in the graph. */
    vertex *vertices_array[MAX_VERTICES_NB];

    /** The number of vertices in the graph, i.e. the index from wich
     * the values in the array may not be vertices in the graph. */
    int     vertices_nb;
};

/**
 * @brief Create an empty graph.
 *
 * @param p_p_graph  a pointer to a pointer to a graph
 * @pre `p_p_graph` must not be null.
 *
 * @post The graph pointed by `*p_p_graph` is initialized as an empty
 *       graph (no vertex, no edge).
 */
void create_empty_graph(graph **p_p_graph);

/**
 * @brief Add a new vertex in the graph.
 *
 * @param p_graph  a pointer to the graph in which the vertex
 *                 has to be added
 * @param id       the identifier of the vertex
 * @pre `id` should not be an existing vertex identifier
 *
 * @post A new vertex is added in the graph and its identifier is `id`.
 */
void add_vertex(graph *p_graph, char id);

/**
 * @brief Get a vertex by its identifier.
 *
 * @param  p_graph  a pointer to the graph in which the vertex
 *                  is searched
 * @param id        the identifier of the vertex
 *
 * @return a pointer to the corresponding vertex if it exists in
 *         the graph, `NULL` else
 */
vertex *get_vertex(graph *p_graph, char id);

/**
 * @brief Add an edge in the graph.
 *
 * @param  p_graph   a pointer to the graph in which the edge
 *                   has to be inserted
 * @param id_source  the identifier of the source vertex
 * @param id_dest    the identifier of the destination vertex
 * @param weight     the weight of the edge
 * @pre `id_source` and `id_dest` should be valid vertices identifiers
 *       in the graph.
 *
 * @post `id_destination` is added in the adjacency list of `id_source`
 *        with a weight of `weight`.
 */
void add_edge(graph *p_graph, char id_source, char id_dest, int weight);

/**
 * @brief Compute the shortest paths from a given vertex to the
 *        other vertices.
 *
 * @param  p_graph   a pointer to the graph
 * @param id_source  the identifier of the source vertex
 *
 * @pre `id_source` should be a valid vertex identifier
 *       in the graph.
 *
 * @post For each vertex in the graph, its minimum distance from `id_source`
 *       is updated and correct and its predecessor field contains a pointer
 *       to the vertex predecessor in the shortest path from `id_source`.
 */
void dijkstra(graph *p_graph, char id_source);

/**
 * @brief Print the graph.
 *
 * Prints each node of the graph and their adjacency lists.
 *
 * @param p_graph  a pointer to the graph to be printed
 */
void print_graph(graph *p_graph);

/**
 * @brief Deallocate the graph.
 *
 * Deallocate each vertex and edge of the graph, as well as the graph
 * structure itself.
 *
 * @param p_graph  a pointer to the graph to be deallocated
 *
 * @post After the call, the pointer `p_graph` is no more valid.
 */
void deallocate_graph(graph *p_graph);

#endif
