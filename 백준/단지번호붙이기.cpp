#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 25

using namespace std;

int MAP[MAX][MAX];
int visited[MAX][MAX];
vector <int>Size;

int N;
int depth;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Input();
void DebugOutput();
void DFS(int x, int y);
void SearchMap();

int main(void)
{
    Input();
    SearchMap();
    
    
    
    
    DebugOutput();
    return 0;
}

void Input(){
    cin >> N;
    string s;
    
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            MAP[i][j] = s[j] - '0';
        }
    }
}

void DebugOutput(){
    sort(Size.begin(), Size.end());
    
    cout << Size.size() << "\n";
    for(int i = 0; i < Size.size(); i++){
        cout << Size[i] << "\n";
    }
}

void DFS(int x, int y){
    visited[x][y] = true;
    depth++;
    int nx, ny;
    for(int i = 0; i < 4; i++){
        
        nx = x + dx[i];
        ny = y + dy[i];
        
        if(nx >= N || ny >= N || nx < 0 || ny < 0 || MAP[nx][ny] == 0 || visited[nx][ny] == true) continue;
        
        DFS(nx, ny);
    }
}

void SearchMap(){
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            
            if(MAP[x][y] && !visited[x][y]){
                depth = 0;
                DFS(x, y);
                Size.push_back(depth);   
            }
        }
    }
}
