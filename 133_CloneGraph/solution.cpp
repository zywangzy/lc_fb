#include "../IOLib.hpp"

/***
(1) This method takes 2 round BFS. The first one to get all node labels,
the second round to copy all the edges.
Time: O(m+n)
Space: O(m+n)
(2) There's an even faster method. Just take one round BFS.
Use a map to map old nodes to new nodes, and do the copy while doing DFS.
***/



/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_set<int> labels;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode* ptr = q.front();
            q.pop();
            if(labels.find(ptr->label) != labels.end()) continue;
            labels.insert(ptr->label);
            for(auto next: ptr->neighbors){
                if(labels.find(next->label) != labels.end()) continue;
                q.push(next);
            }
        }
        unordered_map<int, UndirectedGraphNode*> nodes;
        for(auto it = labels.begin(); it != labels.end(); it++){
            UndirectedGraphNode* temp = new UndirectedGraphNode(*it);
            nodes[*it] = temp;
        }
        //q.clear();
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode* ptr = q.front();
            q.pop();
            if(labels.find(ptr->label) == labels.end()) continue;
            labels.erase(ptr->label);
            for(auto next: ptr->neighbors){
                nodes[ptr->label]->neighbors.push_back(nodes[next->label]);
                q.push(next);
            }
        }
        return nodes[node->label];
    }
};
