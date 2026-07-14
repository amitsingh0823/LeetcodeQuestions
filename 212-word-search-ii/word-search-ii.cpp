class Solution
{
public:

    class TrieNode
    {
    public:

        TrieNode* child[26];
        bool isWord;
        string word;

        TrieNode()
        {
            for(int i=0;i<26;i++)
                child[i]=NULL;

            isWord=false;
            word="";
        }
    };

    TrieNode* root=new TrieNode();

    void insert(string word)
    {
        TrieNode* curr=root;

        for(char ch:word)
        {
            int idx=ch-'a';

            if(curr->child[idx]==NULL)
                curr->child[idx]=new TrieNode();

            curr=curr->child[idx];
        }

        curr->isWord=true;
        curr->word=word;
    }

    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* node,
             vector<string>& ans)
    {
        char ch=board[i][j];

        if(ch=='#')
            return;

        if(node->child[ch-'a']==NULL)
            return;

        node=node->child[ch-'a'];

        if(node->isWord)
        {
            ans.push_back(node->word);

            node->isWord=false;
        }

        board[i][j]='#';

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(x>=0 && y>=0 &&
               x<board.size() &&
               y<board[0].size())
            {
                dfs(board,x,y,node,ans);
            }
        }

        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words)
    {
        for(string word:words)
            insert(word);

        vector<string> ans;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                dfs(board,i,j,root,ans);
            }
        }

        return ans;
    }
};