#include <stdio.h> 
#include <iostream>
#include <queue>
#include <vector>

#define MAX 100

using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};




bool visited[MAX][MAX];
int MAP[MAX][MAX];
int dist[MAX][MAX];

void Input();
void BFS(int x, int y);
void DFS();

int main(void)
{
    
    
    Input();
    BFS(0,0);
    cout << dist[N-1][M-1];
    return 0;
}


void Input(){
    cin >> N >> M;
    
    string row;
    
    for(int i = 0; i < N; i++){
        cin >> row;
        for(int j = 0; j < M; j++){
            MAP[i][j] = row[j]-'0';
        }
    }
}

void BFS(int x, int y){
    visited[x][y] = true;
    
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    dist[x][y]++;
    
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M || !MAP[nx][ny]) continue;
            
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}


void DFS(int x, int y){
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!visited[nx][ny]) DFS(nx, ny);    
    }
}



void BFS(int x, int y){
    visited[x][y] = ture;
    
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        
    }
    
}

/*
void BFS(int x, int y){
    visited[x][y] = true;
    
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}


void DFS(int x, int y){
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(!visited[nx][ny]) DFS(nx, ny);    
    }
}

*/
