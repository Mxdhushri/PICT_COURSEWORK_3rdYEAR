#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<bool>>&board,int row,vector<bool>&cols,vector<bool>&diags,vector<bool>&rdiags)
{
    if(row==board[0].size())
    {
        for(int i=0;i<board[0].size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                cout<<board[i][j]<<" ";

            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int col=0;col<board[0].size();col++)
    {
        if(cols[col]==false && diags[row+col]==false && rdiags[row-col+board[0].size()-1]==false)
        {
            board[row][col]=true;
            cols[col]=true;
            diags[row+col]=true;
            rdiags[row-col+board[0].size()-1]=true;
            
            solve(board,row+1,cols,diags,rdiags);
            cols[col]=false;
            diags[row+col]=false;
            rdiags[row-col+board[0].size()-1]=false;
            board[row][col]=false;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of queens to be arranged : "<<endl;
    cin>>n;
    vector<vector<bool>>board(n,vector<bool>(n,false));
    vector<bool>cols(n,false);
    vector<bool>diags(2*n-1,false);
    vector<bool>rdiags(2*n-1,false);
    cout<<"Total possible arrangements : "<<endl;  
    solve(board,0,cols,diags,rdiags);
    return 0;
}