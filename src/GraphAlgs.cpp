/**
 *  Main bulk of HW05, solving the traveling salesperson program
 *  by implementing GraphAlgs.h
 *
 *  @author Brandon Sonoda
 *  date: 12-2-2012
 */

#include "GraphAlgs.h"
#include <iostream>
//include <math.h>

using namespace std;

int temp, top, val, random, ns;
std::vector<NodeID> temp2;
//std::pair< std::vector<NodeID>, EdgeWeight > best;
std::pair< std::vector<NodeID>, EdgeWeight > best2;
//EdgeWeight dist(std::vector<NodeID> nums, Graph* g);
//void tour(int* arr, int arr_len, int start, Graph* g);
void tour2(int* arr, int arr_len, int start, Graph* g, EdgeWeight cur);

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
    int arr_len = G->size();
    int* arr = new int[arr_len];
    std::vector<NodeID> ids, id2;
    EdgeWeight bsf, bsf2;
    bsf = bsf2 = 0;

    ids.resize(arr_len);
    id2.resize(arr_len);

	arr[0] = 0;
    ids[0] = 0;
    id2[0] = 0;
    for(int i = 1; i<arr_len; i++){
        arr[i] = i;
        ids[i] = i;
        id2[i] = i;
        bsf += G->weight(i, i-1);
    }
    bsf+=G->weight(arr_len-1, 0);
    
    //int val, random, ns;
    //best = std::make_pair(ids, bsf);

    //Do some random tests
	top = arr_len*(arr_len/2);
	if(arr_len > 3){
    for(int times = 0; times < top; times++){
        for(ns = 1; ns<arr_len-1; ns++){
            random = rand()%(arr_len-ns);
            val = ids[ns]; 
            id2[ns] = id2[random+ns];
            id2[ns+random] = val;
        }
        
        for(ns = 1; ns<arr_len; ns++)
            bsf2 += G->weight(id2[ns], id2[ns-1]);
        bsf2 += G->weight(id2[0], id2[arr_len-1]);
        
        if(bsf2 < bsf){
            bsf = bsf2;
            ids = id2;
        }
    }
	}
    
    best2 = std::make_pair(ids, bsf);
    
    tour2(arr, arr_len, 1, G, 0);
    delete [] arr;
    return best2;
}

/*
EdgeWeight dist(std::vector<NodeID> nums, Graph* g){
    EdgeWeight sum = 0;
    for(int i = 1; i<nums.size(); i++)
        sum += g->weight(nums[i], nums[i-1]);
    sum += g->weight(nums[0], nums[nums.size()-1]);
    return sum;
}


void tour(int* arr, int arr_len, int start, Graph* g){
     if(arr_len - start == 1){
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
*/

void tour2(int* arr, int arr_len, int start, Graph* g, EdgeWeight cur){
    if(arr_len - start == 1){
         cur += g->weight(arr[0], arr[arr_len-1]) + g->weight(arr[arr_len-2], arr[arr_len-1]);
        if(cur < best2.second){
            temp2.resize(arr_len);
            for(int i = 0; i<arr_len; i++){
                temp2[i] = arr[i];
            }
            best2 = std::make_pair(temp2, cur);
        }
    } else {
		EdgeWeight pos;
        for(int i = start; i<arr_len; i++){
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp; 
            
            pos = cur+g->weight(arr[start], arr[start-1]);
            if(pos < best2.second){
                tour2(arr, arr_len, start+1, g, pos);
			}
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp; 
        }
    } 
}