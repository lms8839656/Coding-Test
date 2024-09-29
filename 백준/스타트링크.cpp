#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000000

using namespace std;

int MAP[MAX+1];
bool visited[MAX+1];

int dx[2] = {1, -1};

int F, S, G, U, D;

int cnt = 0;
int nowF = 0;
int mincnt = 987654321;
//////////
vector <int>v;


///////


void Input();
void Set();
void DFS(int x);
void BFS(int x);

int main(void)
{
    Input();
    Set();
    if(mincnt != 987654321) cout << mincnt;
    else cout << "use the stairs";
    
    return 0;    
}

void Input(){
    cin >> F >> S >> G >> U >> D;
}

void Set(){
    nowF = S;
    BFS(nowF);
}

void DFS(int x){
    visited[x] = true;
    
    
    
    int nx;
    for(int i = 0; i < 2; i++){
        if(i == 0) nx = x + dx[i] * U;
        else nx = x + dx[i] * D;
        
        if(nx > F || nx <= 0 || visited[nx]) continue;
        
        cnt++;
        DFS(nx);
        cnt--;
    }
}

void BFS(int x){
    queue <pair<int,int> >q;
    visited[x] = true;
    q.push(make_pair(x, 0));
    int nx, ncnt;
    
    
    while(!q.empty()){
        x = q.front().first;
        cnt = q.front().second;
        q.pop();

        
        if(x == G){
            mincnt = cnt;
            return;
        }
        
        
        for(int i = 0; i < 2; i++){
            if(i == 0) nx = x + dx[i] * U;
            else nx = x + dx[i] * D;
            
            if(nx > F || nx <= 0 || visited[nx]) continue;
            visited[nx] = true;
            q.push(make_pair(nx, cnt+1));

        }
    }
}
