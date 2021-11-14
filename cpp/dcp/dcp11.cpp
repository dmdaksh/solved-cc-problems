#include <bits/stdc++.h>
using namespace std;

#define CHARACTERS 128

class Trie{
    private:
    Trie *letters[CHARACTERS];
    bool isEnd;
    public:
    Trie(){
        this->isEnd = false;
        for(int i = 0; i < CHARACTERS; i++) letters[i] = NULL;
    }
    void insert(string str){
        Trie *curr = this;
        for(int i = 0; i < str.size(); i++){
            if(curr->letters[str[i]] == NULL) curr->letters[str[i]] = new Trie;
            curr = curr->letters[str[i]];   
        }
        curr->isEnd = true;
    }
    bool search(string str){
        Trie *curr = this;
        if(curr == NULL) return false;
        for(int i = 0; i < str.size(); i++){
            curr = curr->letters[str[i]];
            if(curr == NULL) return false;
        }
        return curr->isEnd;
    }
    bool isLast(Trie *&curr){
        for(int i = 0; i < CHARACTERS; i++){
            if(curr->letters[i] != NULL) return false;
        }
        return true;
    }
    void printAllSuggestion(Trie *&curr, string currPrefix){
        if(curr->isEnd){
            cout << currPrefix << endl;
        }
        if(isLast(curr)) return;

        for(int i = 0; i < CHARACTERS; i++){
            if(curr->letters[i]){
                currPrefix.push_back((char)i);
                printAllSuggestion(curr->letters[i], currPrefix);
                currPrefix.pop_back();
            }
        }
    }
    void suggestion(string prefix){
        Trie *curr = this;
        
        for(int i = 0; i < prefix.size(); i++){
            curr = curr->letters[prefix[i]];
            if(curr == NULL) {
                cout << "No word found\n";
                return ;
            }
        }
        bool isWord = curr->isEnd;
        bool _isLast = isLast(curr); 
        if(isWord && _isLast){
             cout << "This is the only Suggestion: " << prefix << endl;
        }
        else{
            printAllSuggestion(curr, prefix);
            return;
        }
    }
};

int main(){
    Trie *t = new Trie;
    string keys[] = {"dog", "dear", "deal"};
    int n = sizeof(keys)/sizeof(keys[0]);
    for(int i = 0; i < n; i++) t->insert(keys[i]);
    t->suggestion("de");
}