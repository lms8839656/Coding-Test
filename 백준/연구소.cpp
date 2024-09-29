#include <iostream>
#include <queue>

#define MAX 8

using namespace std;

int MAP[MAX][MAX];
int tempMAP[MAX][MAX];
int DebugMAP[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int cnt = 0;
int maxArea = 0;

queue <pair<int, int> > q;

void Input();
void CopyMAP();
void Set();
void SpreadVirus(int x, int y);
void CalZeroSpace();
void ResetVisited();
void DebugOutput();
void temp();

int main(void)
{
    Input();
    Set();
    //DebugOutput();
    cout << maxArea;
    
    return 0;
}

void Input(){
    cin >> N >> M;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cin >> MAP[x][y];
        }
    }
}

void CopyMAP(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            tempMAP[x][y] = MAP[x][y];
        }
    }
}

void Set(){
    for(int i = 0; i < N; i++){
        for(int ii = 0; ii < M; ii++){
            for(int j = 0; j < N; j++){
                for(int jj = 0; jj < M; jj++){
                    for(int k = 0; k < N; k++){
                        for(int kk = 0; kk < M; kk++){
                            
                            if(MAP[i][ii] || MAP[j][jj] || MAP[k][kk]) continue;
                            if(i == j && ii == jj) continue;
                            if(i == k && ii == kk) continue;
                            if(j == k && jj == kk) continue;
                            
                            CopyMAP();
                            ResetVisited();
                            
                            tempMAP[i][ii] = 1;
                            tempMAP[j][jj] = 1;
                            tempMAP[k][kk] = 1;
                            
                            for(int x = 0; x < N; x++){
                                for(int y = 0; y < M; y++){
                                    if(tempMAP[x][y] == 2) SpreadVirus(x, y);
                                }
                            }
                            
                            CalZeroSpace();
                            

                        }
                    }
                }
            }
        }
    }
}

void CalZeroSpace(){
    cnt = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(tempMAP[x][y] == 0) cnt++;
        }
    }
    if(cnt > maxArea){
        maxArea = cnt;
        ///////////Debug////////////////
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                DebugMAP[x][y] = tempMAP[x][y];
            }
        }
    }
}

void SpreadVirus(int x, int y){
    visited[x][y] = true;
    tempMAP[x][y] = 2;
    int nx, ny;
    
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx >= N || ny >= M || nx < 0 || ny < 0 || visited[nx][ny] || tempMAP[nx][ny] == 1 || tempMAP[nx][ny] == 2) continue;
        
        SpreadVirus(nx, ny);
    }
}

void ResetVisited(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            visited[x][y] = false;
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cout << DebugMAP[x][y] << " ";
        }
        cout << "\n";
    }
}

void temp(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cout << tempMAP[x][y] << " ";
        }
        cout << "\n";
    }
}
