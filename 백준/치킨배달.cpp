#include <stdio.h> 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50


//치킨거리 계산 -> 치킨집 좌표 입력 -> 최소값 정렬 -> 치킨거리 다시 계산 
 
using namespace std;

int MAP[MAX+1][MAX+1];
int visited[MAX+1][MAX+1];
int dist[MAX+1][MAX+1];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


typedef struct _Home{
    int dist;
    int x;
    int y;
}Home;

typedef struct _Chicken{
    int dist;
    int x;
    int y;
}Chicken;

Home myHome;

int min = 123456789;
int temp;
int sumDist;
int N, M;

vector<int> v;

void Input();
void CalDist();
void BFS(int x, int y);
void Reset();
void DebugOutput();


int main(void)
{
    Input();
    
    CalDist();
    
    DebugOutput();
    
    return 0;
}


void Input(){
    cin >> N >> M;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> MAP[x][y];
        }
    }
}

void CalDist(){
    Reset();
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(MAP[x][y] == 1){
                BFS(x,y);
                Reset();
            }
        }
    }
    
    sort(v.begin(), v.end());
}

void BFS(int x, int y){
    visited[x][y] = true;
    dist[x][y]++;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    int nx, ny;
    int temp = 0;
    
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        
        for(int i = 0; i <4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            
            if(nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
            
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(x,y));
            }
        }
        
        if(MAP[nx][ny] == 2){
            q.pop();
            v.push_back(dist[nx][ny]);
            break;
        }
    }
}

void Reset(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            visited[x][y] = false;
            dist[x][y] = 0;
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}
