#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;

bool visited[1000+1];
bool BFSvisited[1000+1];
vector<int> vGraph[1000+1];

void Input();
void Run();
void Output();
void DFS(int point);
void BFS(int point);

int main(void)
{
    Input();
    Run();
    return 0;
}

void Input(){
    cin >> N >> M >> V;
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y; 
        vGraph[x].push_back(y);
        vGraph[y].push_back(x);
    }
    for(int i = 1; i <= N; i++){
        sort(vGraph[i].begin(), vGraph[i].end());
    }
    
}

void Run(){
    DFS(V);
    cout << "\n";
    BFS(V);
}

void Output(){
    
}

void DFS(int point){
    visited[point] = true;
    cout << point << " "; 
    for(int i = 0; i < vGraph[point].size(); i++){
        int nextpoint = vGraph[point][i];
        if(!visited[nextpoint]) DFS(nextpoint);
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start);
    BFSvisited[start] = true;
    while(!q.empty()){
        int point = q.front();
        q.pop();
        cout << point << " ";
        for(int i = 0; i < vGraph[point].size(); i++){
            int nextpoint = vGraph[point][i];
            if(!BFSvisited[nextpoint]){
                q.push(nextpoint);
                BFSvisited[nextpoint] = true;
            }
        }
        
    }
}
