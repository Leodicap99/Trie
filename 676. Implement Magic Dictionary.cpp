class Trie{
      public:
        bool end;
        Trie* children[27];
        Trie(){
            end =false;
            memset(children,NULL,sizeof(children));
        }
    };
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root=new Trie();
    MagicDictionary() {
        
    }
    void insert(string s)
    {
        Trie* node=root;
        for(char c:s)
        {
            if(!node->children[c-'a'])
            {
                node->children[c-'a']=new Trie();
            }
            node=node->children[c-'a'];
        }
        node->end=true;
    }
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string s:dict){
            insert(s);
        }
    }
    bool found(string s)
    {
        Trie* node=root;
        for(char c:s)
        {
            if(!node->children[c-'a'])return false;
            node=node->children[c-'a'];
        }
        return node->end;
    }
    bool search(string word) {
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            for(char c='a';c<='z';c++)
            {
                if(ch==c)continue;
                word[i]=c;
                if(found(word))return true;
            }
            word[i]=ch;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
