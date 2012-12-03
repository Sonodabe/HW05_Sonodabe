/**
 *  Main bulk of HW05, solving the traveling salesperson program
 *  by implementing GraphAlgs.h
 *
 *  @author Brandon Sonoda
 *  date: 12-2-2012
 */

#include "GraphAlgs.h"
#include <iostream>
#include <math.h>

using namespace std;

int temp, comp;
EdgeWeight posCur;
std::pair< std::vector<NodeID>, EdgeWeight > best;
std::pair< std::vector<NodeID>, EdgeWeight > best2;
EdgeWeight dist(std::vector<NodeID> nums, Graph* g);
void tour(int* arr, int arr_len, int start, Graph* g);
void tour2(int* arr, int arr_len, int start, Graph* g, EdgeWeight cur);

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
    best2 = std::make_pair(ids, bsf);
    comp = 0;
    tour(arr, arr_len, 0, G);
    comp = 0;
    tour2(arr, arr_len, 1, G, 0);
    cout << "tour: " << best.second << " tour2: "<< best2.second << endl;
    cout << "Comparison count: " << comp << endl;
    
    cout << endl << "W1: " << dist(best.first, G) << " W2: " << dist(best2.first, G) << endl << endl;
    
    return best;
}

EdgeWeight dist(std::vector<NodeID> nums, Graph* g){
    EdgeWeight sum = 0;
    for(int i = 1; i<nums.size(); i++)
        sum += g->weight(nums[i], nums[i-1]);
    sum += g->weight(nums[0], nums[nums.size()-1]);
    return sum;
}

void tour(int* arr, int arr_len, int start, Graph* g){
     if(arr_len - start == 1){
         comp++;
        EdgeWeight final = 0;
        for(int i = 1; i<arr_len; i++)
            final+=g->weight(arr[i], arr[i-1]);
        final += g->weight(arr[0], arr[arr_len-1]);
        if(final < best.second){
            std::vector<NodeID> temp;
            temp.resize(arr_len);
            for(int i = 0; i<arr_len; i++)
                temp[i] = arr[i];
            best = std::make_pair(temp, final);
        }
    } else {
        for(int i = start; i<arr_len; i++){
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            tour(arr, arr_len, start+1, g);
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    } 
}

void tour2(int* arr, int arr_len, int start, Graph* g, EdgeWeight cur){
    if(arr_len - start == 1){
        comp++;
        EdgeWeight tempw = cur + g->weight(arr[0], arr[arr_len-1]);
        if(tempw < best2.second){
            std::vector<NodeID> temp;
            temp.resize(arr_len);
            for(int i = 0; i<arr_len; i++){
                temp[i] = arr[i];
            }
            best2 = std::make_pair(temp, tempw);
        }
    } else {
        for(int i = start; i<arr_len; i++){
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            
            EdgeWeight pos = cur+g->weight(arr[start], arr[start-1]);
            if(pos < best2.second)
                tour2(arr, arr_len, start+1, g, pos);
            
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    } 
}