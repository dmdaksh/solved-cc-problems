#include<bits/stdc++.h>
using namespace std;

#define ALPHABETS 128

class Trie{
    private:
    Trie *children[ALPHABETS];
    bool isEndOfWord;

    public:
    Trie(){
        this->isEndOfWord = false;
        for(int i = 0; i < ALPHABETS; i++) children[i] = NULL;
    }    
    void insert(string str){
        Trie *curr = this;
        for(int i = 0; i < str.size(); i++){
            if(curr->children[str[i]] == NULL) curr->children[str[i]] = new Trie;
            curr = curr->children[str[i]];
        }
        curr->isEndOfWord = true;
    }
    bool search(string str){
        if(this == NULL) return false;
        Trie *curr = this;
        for(int i = 0; i < str.size(); i++){
            curr = curr->children[str[i]];
            if(!curr) return false;
        }
        return curr->isEndOfWord;
    }
    bool haveChildren(Trie* &curr){
        if(curr == NULL) return false;
        for(int i = 0; i < ALPHABETS; i++){
            if(curr->children[i]) return true;
        }
        return false;
    }
    bool deletion(Trie* &curr, string str){
        if(curr == NULL) return false;
        if(str.size()){
            if(curr != NULL && curr->children[str[0]] != NULL && deletion(curr->children[str[0]], str.substr(1)) && curr->isEndOfWord == false){
                if(!haveChildren(curr)){
                    delete curr;
                    curr = NULL;
                    return true;
                }
                else return false; 
            }
        }
        if(str.size() == 0 && curr->isEndOfWord){
            if(!haveChildren(curr)){
                delete curr;
                curr = NULL;
                return true;
            }
            else{
                curr->isEndOfWord = false;
                return false;
            }
        }
        return false;
    }
};

int main(){
    string keys[] = {"My", "name" , "is", "Daksh", "Maheshwari", "and", "I", "am", "coding", "Trie", "for", "Google"};
    int n = sizeof(keys)/sizeof(keys[0]);

    Trie *root = new Trie;

    for(int i = 0; i < n; i++)  root->insert(keys[i]);

    root->search("Maheshwari") ? cout << "Yes" << endl: cout << "No" << endl;
    root->deletion(root, "Maheshwari");
    root->search("Maheshwari") ? cout << "Yes" << endl: cout << "No" << endl;
}