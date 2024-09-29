#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int N, M, H;

int MAP[MAX][MAX][MAX];
int tempMAP[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int day = 0;
int maxDay = 0;

void Input();
bool checkTomato();
void DFS(int zh, int xn, int ym);
void SpreadTomato();
void CopyMAP();
void OneDayTomato();
void SetTomato(int zh, int xn, int ym);
bool AlreadyTomato();

int main(void)
{
    Input();
    
    
    while(checkTomato()){
        day++;
        CopyMAP();
        OneDayTomato();
        if(day > 175) break;
    }
    

    if(checkTomato()) cout << -1;
    else cout << day;
    
    return 0;   
}

void Input(){
    cin >> N >> M >> H;
    for(int z = 0; z < H; z++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                cin >> MAP[z][x][y];
            }
        }
    }
}

bool checkTomato(){
    for(int z = 0; z < H; z++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                if(MAP[z][x][y] == 0) return true;
            }
        }
    }
    
    return false;
}


void DFS(int zh, int xn, int ym){
    visited[zh][xn][ym] = true;
    MAP[zh][xn][ym] = 1;
    
    
    //tempMAP[zh][xn][ym] = 1;
    
    int nz, nx, ny;
    
    for(int i = 0; i < 6; i++){
        nz = zh + dz[i];
        nx = xn + dx[i];
        ny = ym + dy[i];
        
        //if(nz >= H || nx >= N || ny >= M || nz < 0 || nx < 0 || ny < 0 || visited[nz][nx][ny] || (MAP[nz][nx][ny] && tempMAP[nz][nx][ny] && 1) || MAP[nz][nx][ny] != 0) continue;
        if(nz >= H || nx >= N || ny >= M || nz < 0 || nx < 0 || ny < 0 || visited[nz][nx][ny] || MAP[nz][nx][ny] != 0) continue;
        day++;
        DFS(nz, nx, ny);
        if(day > maxDay) maxDay = day;
        day--;
    }
}

void CopyMAP(){
    for(int z = 0; z < H; z++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                MAP[z][x][y] = tempMAP[z][x][y];
            }
        }
    }
}

void SpreadTomato(){
    for(int z = 0; z < H; z++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                if(MAP[z][x][y] == 1) DFS(z, x, y);
            }
        }
    }
}

void OneDayTomato(){
    for(int z = 0; z < H; z++){
        for(int x = 0; x < N; x++){
            for(int y = 0; y < M; y++){
                if(MAP[z][x][y] == 1) SetTomato(z, x, y);
            }
        }
    }
}

void SetTomato(int zh, int xn, int ym){
    int nz, nx, ny;
    for(int i = 0; i < 6; i++){
        nz = zh + dz[i];
        nx = xn + dx[i];
        ny = ym + dy[i];
        if(nz >= H || nx >= N || ny >= M || nz < 0 || nx < 0 || ny < 0 || MAP[nz][nx][ny] == 1 || tempMAP[nz][nx][ny] == -1) continue;
    
        tempMAP[nz][nx][ny] = 1;
    }
}

bool AlreadyTomato(){
    //if(MAP[nz][nx][ny] && tempMAP[nz][nx][ny] && 1) return true;
    //else false;
}
