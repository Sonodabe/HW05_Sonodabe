#include "ListGraph.h"


ListGraph::ListGraph(int numNodes){
    
}

ListGraph::~ListGraph(){}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
    return 0.0;
}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
    EList* adj = new EList();
    return *adj;
}
unsigned ListGraph::degree(NodeID u) const{
    return 0;
}
unsigned ListGraph::size() const{
    return 0;
}
unsigned ListGraph::numEdges() const{
    return 0;
}