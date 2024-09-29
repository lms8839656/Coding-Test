#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];
vector <int>area;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int M, N, K;

int cntArea;
int numArea = 0;

void Input();
void SearchMap();
void DFS(int x, int y);
void DebugOutput();

int main(void)
{
    Input();
    SearchMap();
    DebugOutput();
    return 0;
}

void Input(){
    cin >> M >> N >> K;
    
    int x1, y1, x2, y2;
    for(int i = 0; i < K; i++){
        cin >> y1 >> x1 >> y2 >> x2;
        
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                MAP[x][y] = true;
            }
        }
    }
}

void SearchMap(){
    for(int x = 0; x < M; x++){
        for(int y = 0; y < N; y++){
            if(!visited[x][y] && !MAP[x][y]){
                numArea++;
                cntArea = 0;
                DFS(x, y);
                area.push_back(cntArea);
            }
        }
    }
    
    sort(area.begin(), area.end());
}

void DFS(int x, int y){
    int nx, ny;
    visited[x][y] = true;
    cntArea++;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || MAP[nx][ny] == true || visited[nx][ny]) continue;
        
        DFS(nx, ny);
    }
}

void DebugOutput(){
//    cout << "\n";
//    
//    for(int x = 0; x < M; x++){
//        for(int y = 0; y < N; y++){
//            cout << MAP[x][y] << " ";
//        }
//        cout << "\n";
//    }
//    
//    cout << "\n";
//    for(int x = 0; x < M; x++){
//        for(int y = 0; y < N; y++){
//            cout << visited[x][y] << " ";
//        }
//        cout << "\n";
//    }
//    
//    cout << "\n";
    cout << numArea;
    cout << "\n";
    
    for(int i = 0; i < area.size(); i++){
        cout << area[i] << " ";
    }
}
