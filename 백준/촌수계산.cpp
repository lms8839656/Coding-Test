#include <iostream>

#define MAX 100

using namespace std;

int N, A, B;

int depth;
int minDepth = 987654321;

int MAP[MAX+1][MAX+1];
int visited[MAX+1];

void Input();
void DFS(int x, int cnt);
void sDFS(int x);
int minCnt = 987654321;

int main(void)
{
    Input();
    //DFS(A, 0);
    sDFS(A);
    if(minDepth == 987654321) cout << -1;
    else cout << minDepth - 1;
    
    //if(minCnt == 987654321) cout << -1;
    //else cout << minCnt - 1;
    
    return 0;
}


void Input(){
    cin >> N >> A >> B;
    
    int temp, x, y;
    
    cin >> temp;
    
    for(int i = 0; i < temp; i++){
        cin >> x >> y;
        MAP[x][y] = true;
        MAP[y][x] = true;
    }
    
}


void DFS(int x, int cnt){
    visited[x] = true;
    depth++;
    cnt++;
    if(x == B) {
        if(minDepth > depth) minDepth = depth;
        depth--;
        
        if(minCnt > cnt) minCnt = cnt;
        
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(MAP[x][i] == true && !visited[i]) DFS(i, cnt);
    }
}

void sDFS(int x){
    visited[x] = true;
    depth++;

    if(x == B) {
        if(minDepth > depth) minDepth = depth;
        depth--;
        return;
    }
    
    for(int i = 1; i <= N; i++){
        if(MAP[x][i] == true && !visited[i]) {
            sDFS(i);
            depth--;
        }
    }
}
