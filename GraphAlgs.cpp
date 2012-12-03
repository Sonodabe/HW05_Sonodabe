/**
 *  Main bulk of HW05, solving the traveling salesperson program
 *  by implementing GraphAlgs.h
 *
 *  @author Brandon Sonoda
 *  date: 12-2-2012
 */

#include "GraphAlgs.h"
#include <iostream>
std::pair<std::vector<NodeID>, EdgeWeight> tour(int* arr, int arr_len, int start, EdgeWeight cur,
                                                std::pair<std::vector<NodeID>, EdgeWeight> best, Graph* g);

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
    int arr_len = G->size();
    int* arr = new int[arr_len];
    std::vector<NodeID> ids;
    EdgeWeight bsf = 0.0;
    ids.resize(arr_len);
    for(int i = 0; i<arr_len; i++){
        arr[i] = i;
        ids[i] = i;
        if(i>0)
            bsf += G->weight(i, i-1);
    }
    bsf+=G->weight(arr_len-1, 0);
    return tour(arr, arr_len, 0, 0.0, std::make_pair(ids, bsf), G);
}

std::pair<std::vector<NodeID>, EdgeWeight> tour(int* arr, int arr_len, int start, EdgeWeight cur,
                                                std::pair<std::vector<NodeID>, EdgeWeight> best, Graph* g){
    std::pair<std::vector<NodeID>, EdgeWeight> ret;
    if(arr_len - start == 1){
        EdgeWeight final = 0/*cur + g->weight(arr[0], arr[arr_len-1])*/;
        for(int i = 1; i<arr_len; i++)
            final+=g->weight(arr[i], arr[i-1]);
        final += g->weight(arr[0], arr[arr_len-1]);
            //Check to see if this is the best of the best of the best tour. <- MIB reference
        if(final < best.second){
            std::vector<NodeID> temp;
            temp.resize(arr_len);
            for(int i = 0; i<arr_len; i++)
                temp[i] = arr[i];
            
            ret = std::make_pair(temp, final);
        }
        
    } else {
        for(int i = start; i<arr_len; i++){
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = arr[start];
            ret = tour(arr, arr_len, start+1, cur/*+g->weight(arr[i], arr[i-1])*/, best, g);
            arr[i] = arr[start];
            arr[start] = temp;
        }
    }
    return ret;
}