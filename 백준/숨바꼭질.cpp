#include <iostream>
#include <queue>
#include <vector>

#define MAX 100000

using namespace std;

int N, K;

queue <pair<int,int> >q;
bool visited[MAX+1];

int dx[3] = {1, -1, 0};

void Input();
void BFS(int x, int depth);

int main(void)
{
    Input();
    BFS(N, 0);
    
    return 0;    
}

void Input(){
    cin >> N >> K;
}

void BFS(int x, int d){
    q.push(make_pair(x, d));
    visited[x] = true;
    int nx, nd;
    
    while(!q.empty()){
        
        
        x = q.front().first;
        d = q.front().second;
        q.pop();
        
        if(x == K){
            cout << d;
            return;
        }
        
        for(int i = 0; i < 3; i++){
            nx = x + dx[i];
            if(dx[i] == 0) nx = 2*x;
            if(nx > 100000 || nx < 0 || visited[nx]) continue;
        
            visited[nx] = true;
            q.push(make_pair(nx, d+1));
        }
        
        
        
    }
}
