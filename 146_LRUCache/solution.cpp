#include "../IOLib.hpp"

/**
Use hashmap and doubly-linkedlist.
Time: Get: O(1), Put: O(1)
Space: O(capacity)
**/

class LRUCache {
    class node{
    public:
        int key;
        int value;
        node* prev;
        node* next;
        node(int k, int v): key(k), value(v){
            prev = NULL;
            next = NULL;
        }
    };
    private:
    node* head;
    node* tail;
    unordered_map<int, node*> dict;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end())
            return -1;
        node* ptr = dict[key];
        if(ptr != head){
            if(ptr != tail){
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            else{
                ptr->prev->next = NULL;
                tail = ptr->prev;
            }
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        return ptr->value;
    }
    
    void put(int key, int value) {
        if(dict.find(key) != dict.end()){
            this->get(key);
            head->value = value;
            return;
        }
        node* ptr = new node(key, value);
        if(head){
            ptr->next = head;
            head->prev = ptr;
        }
        else{
            tail = ptr;
        }
        head = ptr;
        dict[key] = ptr;
        if(dict.size() > capacity){
            dict.erase(tail->key);
            tail->prev->next = NULL;
            tail = tail->prev;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
