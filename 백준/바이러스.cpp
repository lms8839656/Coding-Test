#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int MAP[MAX+1][MAX+1];
int visited[MAX+1];

int Num = 0;

int N;

void Input();
void DFS(int x);
void CalNum();

int main(void)
{
    Input();
    DFS(1);
    CalNum();
    cout << --Num;
    return 0;
}

void Input(){
    cin >> N;
    int temp;
    int x, y;
    cin >> temp;
    for(int i = 0; i < temp; i++){
        cin >> x >> y;
        MAP[x][y] = true;
        MAP[y][x] = true;
    }
}

void DFS(int x){
    visited[x] = true;
    
    for(int i = 1; i <= N; i++){
        if(!visited[i] && MAP[x][i]){
            DFS(i);
        }
        else continue;
    }
}

void CalNum(){
    for(int i = 1; i <= N; i++){
        if(visited[i] == true) Num++;
    }
}
