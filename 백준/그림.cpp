#include <stdio.h> 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 501

int n, m;

bool visited[MAX][MAX];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int map[MAX][MAX];
vector<int> v;
queue< pair<int,int> > q;
void BFS(int x, int y);
int s = 1;

void DFS(int x, int y);
void Input();
bool compare(int i, int j);

int main(void)
{
    int cnt = 0;
    Input();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 1 && visited[i][j] == 0){
                BFS(i, j);
                v.push_back(s);
                cnt++;
                s=1;
            }
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
    cout << cnt << "\n";
    
    if(cnt == 0){
        cout << 0 << "\n";
    }
    else cout << v[0] << "\n";
}

bool compare(int i, int j){
    return i > j;
}

void DFS(int x, int y){
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(ny < 0 || nx < 0 || nx >= n || ny >= m) continue;
        
        if(map[nx][ny] == 1 && visited[nx][ny] == 0){
            s++;
            DFS(nx, ny);
        }
    }
}

void Input(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }
}

void BFS(int x, int y){
    visited[x][y] = true;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if(ny < 0 || nx < 0 || nx >= n || ny >= m) continue;
            
            if(map[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny] = true;
                s++;
                q.push(make_pair(nx,ny));
            }
        }
    }
}





