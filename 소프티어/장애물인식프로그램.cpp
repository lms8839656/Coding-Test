#include <stdio.h> 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define MAX 25

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N;
int num;

void Input();
void DFS(int x, int y);
void solution();
void Output();
void BFS(int x, int y);

int main(void)
{
    Input();
    solution();
    Output();
    
    return 0;
}

void Input(){
    cin >> N;
    
    
    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        for(int j = 0; j < N; j++){
            MAP[i][j] = t[j] - '0';
        }
    }
}

void DFS(int x, int y){
    visited[x][y] = true;
    int nx, ny;
    
    for(int i = 0; i < 4; i++){
        
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        
        if(!visited[nx][ny] && MAP[nx][ny] == 1) {
            num++;
            DFS(nx, ny);
        }
        
    }
    
}

void solution(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(MAP[x][y] == 1 && visited[x][y] == false){
                num = 1;
                BFS(x, y);
                v.push_back(num);
            }
        }
    }
    
    sort(v.begin(), v.end());
}

void Output(){
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}

void BFS(int x, int y){
    visited[x][y] = true;
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
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!visited[nx][ny] && MAP[nx][ny] == 1) {
                num++;
                visited[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
