/**
 *  Main bulk of HW05, solving the traveling salesperson program
 *  by implementing GraphAlgs.h
 *
 *  @author Brandon Sonoda
 *  date: 12-2-2012
 */

#include "GraphAlgs.h"

using namespace std;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
    vector<NodeID> s;
    return make_pair(s, 0);
}

std::pair<std::vector<NodeID>, EdgeWeight> tour(int* arr, int arr_len, int start, EdgeWeight cur,
                                                std::pair<std::vector<NodeID>, EdgeWeight> best){
    if(arr_len - start == 1){
            //Check to see if this is the best of the best of the best tour. <- MIB reference
    }
    //Check all other perms
    for(int i = start; i<arr_len; i++){
        //Swap arr[start] and ar[i]
        tour(arr, arr_len, start+1, cur+arr[i], best);
        //Swap back to maintain order
    }
}