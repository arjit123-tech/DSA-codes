#include<iostream>
#include<string>
#include<vector>
using namespace std;
void printboard(vector<vector<char>> board, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"---------------------"<<endl;
}
bool isSafe(vector<vector<char>> board, int row,int col){
    int n=board.size();
    for(int j=0;j<n;j++){
         if(board[row][j]=='Q'){//horizontal
        return false;
         }
    }
   for(int i=0;i<n;i++){
    if(board[i][col]=='Q'){//vertical
        return false;
    }
   }
   //diagonal left
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
     if(board[i][j]=='Q'){
          return false;
     }
    }
    //diagonal right
    for(int i=row,j=col;i>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
void nqueen(vector<vector<char>> board, int row){
    int n=board.size();
    if(row==n){
        printboard(board,n);
        return;
    }
    for(int j=0;j<n;j++){
        board[row][j]='Q';
        nqueen(board, row+1);
        board[row][j]='.';
    }
}
int main(){
    int n=4;
    vector<vector<char>> board;
    for(int i=0;i<n;i++){
        vector<char> row;
        for(int j=0;j<n;j++){
            row.push_back('.');
        }
        board.push_back(row);
    }
    printboard(board, n);
    nqueen(board, 0);
    return 0;
}