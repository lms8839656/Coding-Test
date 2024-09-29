#include <stdio.h> 
#include <iostream>
#include <queue>
#include <math.h>

#define MAX 50

//BFS or DFS sum 구할때 범위 나눠진곳 연합끼리만 평균  

using namespace std;

int N, day, L, R;

int MAP[MAX][MAX];
int visited[MAX][MAX];
int DFSvisited[MAX][MAX];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


void Input();
void DebugOutput();
void MoveHuman();
void BFS(int x, int y);
void DFS(int x, int y);
void CalDFS(int x, int y);
void ResetVisited();

int sum = 0;
int DFScnt = 0;
bool FlagEnd = false;
int temp = 0;
int tempvisited = 0;

int main(void)
{
    Input();
    
    
    while(!FlagEnd){
        MoveHuman();
        
        ResetVisited();
    }
    
    
    //DebugOutput();
    cout << day;
    
    return 0;
}

void Input(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }    
}

void MoveHuman(){
    temp = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            temp++;
            BFS(x, y);
        }
    }
    
    sum = 0;
    int cnt = 0;
    //DebugOutput();
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(visited[x][y] > 0) {
                DFScnt = 0;
                sum = 0;
                tempvisited = visited[x][y];
                DFS(x, y);
                CalDFS(x, y);
                
                cnt++;
            }
        }
    }
    
    
    if(cnt == 0){
        FlagEnd = true;
        return;
    }
    day++;   
}

void BFS(int x, int y){
    //visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    
    int nx, ny;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(abs(MAP[x][y]-MAP[nx][ny]) < L || abs(MAP[x][y]-MAP[nx][ny]) > R) continue;
            if(x < 0 || y < 0 || x >= N || y >= N || visited[nx][ny]) continue;
            
            
            if(!visited[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = temp;
            }
        }
    }
}

void ResetVisited(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            visited[x][y] = false;
            DFSvisited[x][y] = false;
        }
    }
}


void DFS(int x, int y){
    DFSvisited[x][y] = visited[x][y];
    visited[x][y] = false;
    
    DFScnt++;
    sum = sum + MAP[x][y];
    
    
    int nx, ny;
    
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || tempvisited != visited[nx][ny] || !visited[nx][ny]) continue;
        
        DFS(nx, ny);
    }
}

void CalDFS(int x, int y){
    DFSvisited[x][y] = false;
    MAP[x][y] = sum / DFScnt;
    
    int nx, ny;
    
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || tempvisited != DFSvisited[nx][ny] || !DFSvisited[nx][ny]) continue;
        
        CalDFS(nx, ny);
    }
}

