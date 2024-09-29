#include <iostream>
#include <vector>

#define MAX 300

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];
int tempMAP[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

int NumofPiece = 0;
int years = 0;
int cntPiece = 0;


void Input();
void Melt();
void CountArea();
void DFS(int x, int y);
bool IsTwoArea();
void CopyMap();
void Copytemp();
void Resetvisited();
void DebugOutput();

int main(void)
{
    Input();
    CopyMap();
    CountArea();
    if(!IsTwoArea()){
        cout << years;
        return 0;
    }


    
    while(IsTwoArea()){
        NumofPiece = 0;
        Resetvisited();
        Melt();
        Copytemp();
        years++;
        CountArea();
        if(NumofPiece == 0){
            cout << 0;
            return 0;
        }
    }
    
        
    cout << years;
    
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

void Melt(){
    int nx, ny;
    int cnt = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cnt = 0;
            if(MAP[x][y] > 0){
                for(int i = 0; i < 4; i++){
                    nx = x + dx[i];
                    ny = y + dy[i];
                    if(nx >= N || ny >= M || nx < 0 || ny < 0) continue;
                    if(MAP[nx][ny] == 0) cnt++;
                }
                tempMAP[x][y] = tempMAP[x][y] - cnt;
                if(tempMAP[x][y] < 0) tempMAP[x][y] = 0;
            }
        }
    }
}

void CountArea(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            if(MAP[x][y] > 0 && !visited[x][y]){
                DFS(x, y);
                NumofPiece++;
            }
        }
    }
}

void DFS(int x, int y){
    visited[x][y] = true;
    int nx, ny;
    
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(MAP[nx][ny] == 0 || nx >= N || ny >= M || nx < 0 || ny < 0 || visited[nx][ny] == true) continue;
        DFS(nx, ny);
    }
}

bool IsTwoArea(){
    if(NumofPiece >= 2) return false;
    else return true;
}

void CopyMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            tempMAP[x][y] = MAP[x][y];
        }
    }
}

void Copytemp(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            MAP[x][y] = tempMAP[x][y];
        }
    }
}

void Resetvisited(){
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
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}
