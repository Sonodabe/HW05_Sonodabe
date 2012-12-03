/**
 *  Main bulk of HW05, solving the traveling salesperson program
 *  by implementing GraphAlgs.h
 *
 *  @author Brandon Sonoda
 *  date: 12-2-2012
 */

#include "GraphAlgs.h"
#include <iostream>

using namespace std;
std::pair< std::vector<NodeID>, EdgeWeight > best;
void tour(int* arr, int arr_len, int start, Graph* g);

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
    best = std::make_pair(ids, bsf);
    for(int i = 0; i<arr_len; i++)
        cout<<best.first[i]<< endl;
    tour(arr, arr_len, 0, G);
    for(int i = 0; i<arr_len; i++)
        cout<<best.first[i]<< endl;

    return best;
}

void tour(int* arr, int arr_len, int start, Graph* g){
    /* if(arr_len - start == 1){
        EdgeWeight final = 0;
        for(int i = 1; i<arr_len; i++)
            final+=g->weight(arr[i], arr[i-1]);
        final += g->weight(arr[0], arr[arr_len-1]);
            //Check to see if this is the best of the best of the best tour. <- MIB reference
        if(final < best.second){
            std::vector<NodeID> temp;
            temp.resize(arr_len);
            for(int i = 0; i<arr_len; i++)
                temp[i] = arr[i];
            best = std::make_pair(temp, final);
        }
        
    } else {
        for(int i = start; i<arr_len; i++){
            arr[start] += arr[i];
            arr[i] = arr[start] - arr[i];
            arr[start] -= arr[i];
            
            tour(arr, arr_len, start+1, g);
            
            arr[start] += arr[i];
            arr[i] = arr[start] - arr[i];
            arr[start] -= arr[i];
        }
    } */
    
    do {
        EdgeWeight final = 0;
        for(int i = 1; i<arr_len; i++)
            final+=g->weight(arr[i], arr[i-1]);
        final += g->weight(arr[0], arr[arr_len-1]);
        //Check to see if this is the best of the best of the best tour. <- MIB reference
        if(final < best.second){
            std::vector<NodeID> temp;
            temp.resize(arr_len);
            for(int i = 0; i<arr_len; i++)
                temp[i] = arr[i];
            best = std::make_pair(temp, final);
        }
    } while(next_permutation(arr, arr+arr_len));
}