#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long



struct node{
    vector<node*> children{26,NULL};
    bool end=false;
    
    bool iskeyexists(char c){
        return children[c-'a']!=NULL;
    }
    void createkey(char c,node* newnode){
        children[c-'a']=newnode;
    }
    node* getkeynode(char c){
        return children[c-'a'];
    }
    void setend(){
        end=true;
    }
    void unsetend(){
        end = false;
    }
    bool getend(){
        return end;
    }
};


class Trie {
    private:
        node* root;
    public:
        Trie() {
            root=new node;
        }
        
        void insert(string word) {
            node* head=root;
            for(char c:word)
                if(!head->iskeyexists(c)){
                    head->createkey(c,new node);
                head=head->getkeynode(c);
            }
            head->setend();
        }
        
        void deleteStr(string word) {
            node* head=root;
            for(char c:word)
                head=head->getkeynode(c);
            head->unsetend();
        }

        bool search(string word) {
            node* head=root;
            for(char c:word){
                if(!head->iskeyexists(c))
                    return false;
                head=head->getkeynode(c);
            }
            return head->getend();
        }
        
        bool startsWith(string prefix) {
            node* head=root;
            for(char c:prefix){
                if(!head->iskeyexists(c))
                    return false;
                head=head->getkeynode(c);
            }
            return true;
        }
};
