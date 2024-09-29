#include <iostream>
#include <vector>

#define MAX 10

using namespace std;

int MAP[MAX][MAX];
int TC;
vector <int>v;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void Input();
void SetMap(int N);
void ReSetMap(int N);
void Output(int N);

int main()
{
    Input();
    for(int i = 0; i < TC; i++){
        SetMap(v[i]);
        Output(v[i]);
        ReSetMap(v[i]);
    }
    
    return 0;
}

void Input(){
    cin >> TC;
    int temp;
    for(int i = 0; i < TC; i++){
        cin >> temp;
        v.push_back(temp);
    }

}

int nx = 0;
int ny = 0;
int num = 1;
int k = 0;
void SetMap(int N){
    if(num > N*N) return;
    
    MAP[nx][ny] = num;
    num++;
    
    int tempx = dx[k];
    int tempy = dy[k];
    
    if(MAP[nx + tempx][ny + tempy] || nx + tempx < 0 || ny + tempy < 0 || nx + tempx >= N || ny + tempy >= N){
        if(k < 4) k++;
        
        if(k == 4) k = 0;
        
        nx = nx + dx[k];
        ny = ny + dy[k];
    }
    else {
        nx = nx + tempx;
        ny = ny + tempy;
    }
    SetMap(N);
}

void ReSetMap(int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            MAP[i][j] = 0;
        }
    }
    k = 0;
    nx = 0;
    ny = 0;
    num = 1;
}

int tc_num = 1;
void Output(int N){
    cout << "#" << tc_num << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    tc_num++;
}
