#include <iostream>
#include <math.h>

#define MAX 20

using namespace std;

int MAP[MAX][MAX];
int visited[MAX];

int N;
int minsub = 987654321;

void Input();
void DFS(int x, int depth);
void CalMinMax();
void ResetVisited();
void DebugOutput();

int main(void)
{
    Input();
    
    DFS(0, 0);
    
    cout << minsub;
    
    return 0;
}

void Input(){
    cin >> N;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            cin >> MAP[x][y];
        }
    }
}

void DFS(int x, int depth){
    
    
    if(depth == N/2){
        CalMinMax();
        //DebugOutput();
        return;
    }
    
    for(int i = x; i < N; i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        depth++;
        DFS(i, depth);
        visited[i] = false;
        depth--;
    }
}

void CalMinMax(){
    int sumA = 0;
    int sumB = 0;
    for(int x = 0; x < N; x++){
        for(int y = 0; y < N; y++){
            if(visited[x] == true && visited[y] == true){
                sumA = sumA + MAP[x][y];
            }
            else if(visited[x] == false && visited[y] == false){
                sumB = sumB + MAP[x][y];
            }
        }
    }
    
    if(minsub > abs(sumA - sumB)) minsub = abs(sumA - sumB);
}

void ResetVisited(){
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }
}

void DebugOutput(){
    cout << "\n";
    for(int i = 0; i < N; i++){
        cout << visited[i] << " ";
    }
}



/*
#include <iostream> 
#include <stdio.h>
#include <cstdio>

#define MAX 20

using namespace std;

int N;
int min;
int MAP[MAX+1][MAX+1];

bool visited[MAX+1];

int Start, Link;
int cnt = 0;


void Input();
void Output();

void Run();
void SumScore();
void SetTeam(int x);

int main(void)
{
    Input();
    //Output();
    
    
    
    return 0;
}


void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
}

void Output(){
    cout << N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void Run(){
    SetTeam(1);
    
    
}

void SumScore(){
    int team_s = 0;
    int team_l = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            
            if(visited[i] == 1 && visited[j] == 1){
                team_s = team_s + map[i][j];
            }
            else if(visited[i] == 0 && visited[j] == 0){
                team_l = team_l + map[i][j];
            }
        }
    }
    min = abs(team_s - teaml);
}

void SetTeam(int x){
    cnt++;
    if(cnt > N/2){
        SumScore();
        return;   
    }
    
    visited[x] = true;
    for(int i = 1; i <= N; i++){
        if(!visited[i]) SetTeam(i);  
    }
    
}

*/
