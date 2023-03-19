class WordDictionary {
public:
    int n;
    struct node {
        node* link[26];
        bool flag=false;
        
        void put(char c) {
            link[c-'a']=new node();
        }
        
        node* get(char c) {
            return link[c-'a'];
        }
        
        void putend(){
            flag=true;
        }
        
        bool isend() {
            return flag;
        }
    };
    
    
    node* root;
    
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node* t=root;
        for(auto p:word) {
            if(t->link[p-'a']==NULL)
                t->link[p-'a']=new node();
            t=t->link[p-'a'];
        }
        t->putend();
    }
    
    bool search(string word) {
        //n=word.size();
        node* t=root;
        return helper(0,t,word);
    }
    
    bool helper(int i,node* t,string word) {
      //  cout<<word<<"-->"<<word[i]<<"-->"<<i<<endl;
        if(i==word.size()) {
            if(t->isend())
                return true;
            return false;
        }
        
        if(!t)
            return false;
        
        if(word[i]=='.') {
            node* tmp = t;
            for(int j=0;j<26;j++) {
                if(tmp->link[j]!=NULL) {
                    t=tmp->link[j];
                    if(helper(i+1,t,word))
                        return true;
                }
            }
            return false;
        }
        
        else {
            if(t->link[word[i]-'a']) { 
                if(helper(i+1,t->get(word[i]),word)) {
                    return true;
                }
                return false;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */