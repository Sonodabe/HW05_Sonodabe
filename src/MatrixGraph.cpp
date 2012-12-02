#include "MatrixGraph.h"
#include <iostream>


MatrixGraph::MatrixGraph(unsigned num_nodes) {
	M.resize(num_nodes);

}

MatrixGraph::~MatrixGraph() {
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	return NULL;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {

}

unsigned MatrixGraph::degree(NodeID u) const {

}

unsigned MatrixGraph::size() const {
	return 0;
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
}