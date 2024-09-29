#include <stdio.h>
#include <iostream>
#include <vector> 
#include <queue>

#define MAX 20

using namespace std;

int MAP[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int N;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int FishEatcnt;
int Runtime = 0;

typedef struct _Shark{
    int x;
    int y;
    int size;
} Shark;

Shark myShark = {0,0,2};


void Input();
void Run();
bool MoveShark();
void BFS(int x, int y);
void Reset();
void EatFish();
void SizeUp(int x);
void DebugOutput();

int main(void)
{
    Input();
    Run();
    cout << Runtime << endl;

    return 0;    
}


void Input(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 9){
                myShark.x = i;
                myShark.y = j;
            }
        }
    }
    //cout << "\n";
}

void Run(){
    while(MoveShark()){
        BFS(myShark.x, myShark.y);
        EatFish();
        Reset();
        //DebugOutput();
    }
}

bool MoveShark(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(myShark.size > MAP[i][j] && MAP[i][j] > 0) return true;
            
        }
    }
    
    return 0;
}


void BFS(int x, int y){
    visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    //dist[x][y]++;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            
            if(!visited[nx][ny] && myShark.size >= MAP[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

void Reset(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void EatFish(){
    int min = 200;
    int min_x, min_y;
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(MAP[i][j] < myShark.size && MAP[i][j] > 0 && MAP[i][j] != 9){
                if(min > dist[i][j]) {
                    min = dist[i][j];
                    min_x = i;
                    min_y = j;   
                }
            }
        }
    }
    
    FishEatcnt++;
    Runtime = Runtime + min;
    
    MAP[myShark.x][myShark.y] = 0;
    myShark.x = min_x;
    myShark.y = min_y;
    MAP[myShark.x][myShark.y] = 9;
    
    SizeUp(FishEatcnt);
    
    
}

void SizeUp(int x){
    if(x == myShark.size) {
        myShark.size++;
        FishEatcnt = 0;    
    }
}

void DebugOutput(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}






