/**
 * Implements a Adjacency Matrix, as defined by MatrixGraph.h
 * 
 * @author Brandon Sonoda
 * date: 12-2-2012
 */
#include "MatrixGraph.h"


MatrixGraph::MatrixGraph(unsigned num_nodes) {
	M.resize(num_nodes);
    for(int i = 0; i<num_nodes; i++){
        M[i].resize(num_nodes);
        for(int j = 0; j<num_nodes; j++)
            M[i][j] = 0;
    }
    num_edges = 0;
}

MatrixGraph::~MatrixGraph() {
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
    /* I'm a fan of using the double initialize line */
    M[u][v] = M[v][u] = weight;
    num_edges++;
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
    EList* adj = new EList();
    for(int i = 0; i<M[u].size(); i++)
        if(M[u][i]!= 0)
            adj->push_back(std::make_pair(i, M[u][i]));
    
    return *adj;
}

unsigned MatrixGraph::degree(NodeID u) const {
    unsigned count = 0;
    for(int i = 0; i<M[u].size(); i++){
        if(M[u][i] != 0) count++;
    }
    return count;
}

unsigned MatrixGraph::size() const {
	return (unsigned)(M.size());
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
}