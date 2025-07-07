#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------------------*
 🟠 Approach 1: extra grid (copy‑then‑cook)
 TC: O(m * n)
 SC: O(m * n)
 *-------------------------------------------------------------*/
class SolutionCopy {
    int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},
                      { 0,-1},        { 0,1},
                      { 1,-1},{ 1,0},{ 1,1}};
    int liveCnt(const vector<vector<int>>& b,int r,int c,int m,int n){
        int cnt=0;
        for(auto& d:dirs){
            int nr=r+d[0], nc=c+d[1];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&b[nr][nc]) ++cnt;
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board){
        int m=board.size(), n=board[0].size();
        vector<vector<int>> nxt=board;
        for(int r=0;r<m;r++)
            for(int c=0;c<n;c++){
                int live=liveCnt(board,r,c,m,n);
                nxt[r][c]=board[r][c]?(live==2||live==3):live==3;
            }
        board.swap(nxt);
    }
};

/*-------------------------------------------------------------*
 🟢 Approach 2: in‑place O(1) (marker encode)
   0 → dead , 1 → live
   2 → dead→live , 3 → live→live
 TC: O(m * n)
 SC: O(1)
 *-------------------------------------------------------------*/
class SolutionInPlace {
    int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},
                      { 0,-1},        { 0,1},
                      { 1,-1},{ 1,0},{ 1,1}};
    bool wasLive(int v){ return v==1||v==3; }
public:
    void gameOfLife(vector<vector<int>>& board){
        int m=board.size(), n=board[0].size();
        for(int r=0;r<m;r++)
            for(int c=0;c<n;c++){
                int live=0;
                for(auto& d:dirs){
                    int nr=r+d[0], nc=c+d[1];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&wasLive(board[nr][nc])) ++live;
                }
                if(board[r][c]){
                    if(live==2||live==3) board[r][c]=3;       // stay live
                    // else becomes 0 automatically
                }else if(live==3) board[r][c]=2;              // dead→live
            }
        for(auto& row:board)
            for(int& v:row) v = (v==1)?0 : (v==2||v==3);
    }
};

/*-------------------------------------------------------------*
 🔵 Approach 3 (bonus): sparse hash‑set for theoretically infinite board
   Stores only live cells: O(k) space, k = live cells.
   Useful when grid is huge & sparse.
 TC per generation: O(k) average
 SC: O(k)
 *-------------------------------------------------------------*/
class SolutionSparse {
    struct PairHash{ size_t operator()(const pair<int,int>&p)const{
        return (uint64_t(p.first)<<32) ^ uint32_t(p.second); }};
public:
    void gameOfLife(vector<vector<int>>& board){ /* not applicable */ }

    unordered_set<pair<int,int>,PairHash>
    nextGen(const unordered_set<pair<int,int>,PairHash>& live){
        unordered_map<pair<int,int>,int,PairHash> cnt;
        for(auto &cell:live){
            int r=cell.first,c=cell.second;
            for(int dr=-1;dr<=1;dr++)
                for(int dc=-1;dc<=1;dc++){
                    if(dr==0&&dc==0) continue;
                    cnt[{r+dr,c+dc}]++;
                }
        }
        unordered_set<pair<int,int>,PairHash> nxt;
        for(auto &[cell, k]:cnt){
            if(k==3 || (k==2 && live.count(cell))) nxt.insert(cell);
        }
        return nxt;
    }
};
