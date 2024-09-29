#include <iostream>

#define MAX 500

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


int N, M;

int maxValue = 0;


void Input();
void Run();
void DFS(int x, int y, int depth, int sum);
void CalT(int x, int y);
void DebugOutput();


int main(void)
{
    Input();
    Run();
    cout << maxValue;
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

void Run(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            DFS(x, y, 1, 0);
            CalT(x, y);
        }
    }
}

void DFS(int x, int y, int depth, int sum){
    int nx, ny;
    visited[x][y] = true;
    sum = MAP[x][y] + sum;
    
    if(depth == 4){
        if(maxValue < sum) maxValue = sum;
        //DebugOutput();
        return;
    }
    
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= N || ny >= M || nx < 0 || ny < 0 || visited[nx][ny] == true) continue;
        depth++;
        DFS(nx, ny, depth, sum);
        depth--;
        visited[nx][ny] = false;
    }

    visited[x][y] = false;
}

void CalT(int x, int y){
    int nx, ny;
    int sum = 0;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx >= N || ny >= M || nx < 0 || ny < 0) continue;
        
        if(dx[i]){
            if(y-1 < 0 || y+1 >= M) continue;
            sum = MAP[x][y] + MAP[x][y-1] + MAP[x][y+1] + MAP[nx][ny];
        }
        else if(dy[i]){
            if(x-1 < 0 || x+1 >= N) continue;
            sum = MAP[x][y] + MAP[x-1][y] + MAP[x+1][y] + MAP[nx][ny];
        }
        
        if(sum > maxValue) maxValue = sum;
    }
    
}

void DebugOutput(){
    cout << "\n";
    for(int x = 0; x < N; x++){
        for(int y = 0; y < M; y++){
            cout << visited[x][y] << " ";
        }
        cout << "\n";
    }
}


