#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#define MAX 50

using namespace std;

int MAP[MAX+1][MAX+1];
int tempMAP[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
bool chickenvisited[MAX+1][MAX+1];
queue <pair<int, int> > q;
vector <int> v;


int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cx[13];
int cy[13];

int N, M;
int sum = 0;
int minsum = 987654321; 

void Input();
void CalDistance(int x, int y);
void ResetVisited();
void SelShop(int cnt);
void ResetTempMap();
void sumDistance();
void SetTempMap();

void DebugOutput();

int main(void)
{
    Input();
    SelShop(0);
    cout << minsum;
    
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

void CalDistance(int x, int y){
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    int nx, ny;
    int orgx = x;
    int orgy = y;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        if(tempMAP[x][y] == 2){
            v.push_back(abs(x - orgx) + abs(y - orgy));
            
            while(!q.empty()){
                q.pop();
            }
            
            return;
        }
        
        
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx > N || ny > N || nx <= 0 || ny <= 0 || visited[nx][ny]) continue;
            q.push(make_pair(nx,ny));
            visited[nx][ny] = true;
        }
    }
}

void ResetVisited(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            visited[x][y] = false;
        }
    }
}

void SelShop(int cnt){
    if(cnt == M){
        ResetTempMap();
        SetTempMap();
        ResetVisited();
        
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                if(tempMAP[x][y] == 1){
                    CalDistance(x, y);
                    ResetVisited();
                }
            }
        }

        sumDistance();
        return;
    }
    
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(MAP[x][y] == 2 && !chickenvisited[x][y]){
                chickenvisited[x][y] = true;
                cx[cnt] = x;
                cy[cnt] = y;
                
                SelShop(cnt + 1);
                chickenvisited[x][y] = false;
            }
        }
    }
}

void ResetTempMap(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            tempMAP[x][y] = MAP[x][y];
            if(MAP[x][y] == 2) tempMAP[x][y] = 0;
        }
    }
}

void sumDistance(){
    sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum = sum + v[i];
    }
    if(sum < minsum) minsum = sum;
    v.clear();
}

void SetTempMap(){
    int i = 0;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(cx[i] == x && cy[i] == y){
                tempMAP[x][y] = 2;
                i++;
            }
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cout << tempMAP[x][y] << " ";
        }
        cout << "\n";
    }
    /*
    cout << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    */
}
