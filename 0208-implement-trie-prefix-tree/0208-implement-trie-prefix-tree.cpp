struct node {
    node* link[26];
    bool flag=false;
    
    bool checkkey(char c) {
        return link[c-'a']!=NULL;
    }
    
    void put(char c,node* t) {
        link[c-'a']=t;
    }
    
    node* get(char c) {
        return link[c-'a'];
    }
    
    void setend() {
        flag=true;
    }
    
    bool isend() {
        return flag;
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root= new node();
    }
    
    void insert(string word) {
        node* n=root;
        
        for(auto p:word) {
            if(!n->checkkey(p))
                n->put(p, new node());
            n=n->get(p);
        }
        n->setend();
    }
    
    bool search(string word) {
        node* n=root;
        
        for(auto p:word) {
            if(!n->checkkey(p))
                return false;
            n=n->get(p);
        }
        return n->isend();
        
    }
    
    bool startsWith(string prefix) {
        node* n=root;
        
        for(auto p:prefix) {
            if(!n->checkkey(p))
                return false;
            n=n->get(p);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */