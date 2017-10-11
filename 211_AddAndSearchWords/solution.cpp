#include "../IOLib.hpp"

class WordDictionary {
    class Node{
    public:
        bool isword;
        vector<Node*> child;
        Node(){
            isword = false;
            child = vector<Node*>(26, NULL);
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* ptr = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(ptr->child[idx] == nullptr)
                ptr->child[idx] = new Node;
            ptr = ptr->child[idx];
        }
        ptr->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int start, Node* ptr){
        if(ptr == nullptr) return false;
        if(start == word.size()) return ptr->isword;
        if(word[start] == '.'){
            for(int i = 0; i < 26; i++){
                if(dfs(word, start+1, ptr->child[i]))
                    return true;
            }
            return false;
        }
        return dfs(word, start+1, ptr->child[word[start]-'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
