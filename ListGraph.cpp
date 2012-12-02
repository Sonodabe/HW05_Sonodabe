#include "ListGraph.h"


ListGraph::ListGraph(int numNodes){
    edgeList.resize(numNodes);
    num_edges = 0;
}

ListGraph::~ListGraph(){}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
    edgeList[u].push_back(std::make_pair(v, weight));
    edgeList[v].push_back(std::make_pair(u, weight));
    num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
    EList::const_iterator iter;
    for(iter = edgeList[u].begin(); iter!=edgeList[u].end(); iter++){
        NWPair cur = *iter;
        if(cur.first == v)
            return cur.second;
    }
    return 0;
}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
    return edgeList[u];
}
unsigned ListGraph::degree(NodeID u) const{
    return (unsigned)edgeList[u].size();
}
unsigned ListGraph::size() const{
    return (unsigned)edgeList.size();
}
unsigned ListGraph::numEdges() const{
    return num_edges;
}