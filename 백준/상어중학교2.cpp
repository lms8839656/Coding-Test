#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20

using namespace std;

int N, M;
int color;
vector<int> group;
int MAP[MAX][MAX];
bool visited[MAX][MAX];

void DFS(int x, int y);
void Gravity();

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    
    return 0;
}

void DFS(int x, int y){
    visited[x][y] = true;
    color = MAP[x][y];
    int nx;
    int ny;
    for(int k = 0; k < 4; k++){
        nx = x + dx[k];
        ny = x + dy[k];
        if(!visited[nx][ny] && (MAP[nx][ny] == color || MAP[nx][ny] == 0)) DFS(nx, ny);
    }
}

void Gravity(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i < 0 || j < 0 || i >= N-1 || j >= N) continue;
            if(MAP[i][j] == -1) continue;
            while(MAP[i-1][j] != NULL || MAP[i-1][j] == -1){
                MAP[i-1][j] = MAP[i][j];
                MAP[i][j] = NULL;
            }
        }
    }
}

void Turn(){
    
}

void Erase(){
    
}
