#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long



struct node{
    vector<node*> children {2,NULL};
    vector<int> count{2, 0};
    bool end=false;
    
    bool iskeyexists(bool bit){
        return children[bit]!=NULL;
    }
    void createkey(bool bit,node* newnode){
        children[bit]=newnode;
    }
    node* getkeynode(bool bit){
        return children[bit];
    }
    void setend(){
        end=true;
    }
    bool getend(){
        return end;
    }
    void countinc(int var){
        count[var]++;
    }
    void countdec(int var){
        count[var]--;
    }
    int getcount(int var){
        return count[var];
    }
};


class Trie {
    private:
        node* root;
public:
    Trie() {
        root=new node;
    }
    
    void insert(int num) {
        node* head=root;
        for(int i=30;i>=0;i--){
            bool c=(num & 1<<i);
            if(!head->iskeyexists(c)){
                head->createkey(c,new node);
            }
            head->countinc(c);
            head=head->getkeynode(c);
            
        }
        head->setend();
    }
    void deletenum(int num) {
        node* head=root;
        for(int i=30;i>=0;i--){
            bool c=(num & 1<<i);
            head->countdec(c);
            head=head->getkeynode(c);
        }
    }
    int maxxor(int num){
        node* head=root;
        int ans=0;
        for(int i=30;i>=0;i--){
            bool c=(num>>i & 1);
            if(head->iskeyexists(int(1-c)) && head->getcount(int(1-c))){
                ans=ans+(1<<i);
                head=head->getkeynode(int(1-c));
            }
            else{
                head=head->getkeynode((int)c);
            }
        }
        return ans;
    }
};
