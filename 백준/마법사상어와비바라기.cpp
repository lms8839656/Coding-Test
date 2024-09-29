#include <iostream>
#include <vector>

#define MAX 50
#define MAXODER 100
#define MYMAP 1
#define TEMPMAP 2

using namespace std;

int MAP[MAX + 1][MAX + 1];

typedef struct _Oder{
    int dest;
    int dist;
}Oder;

typedef struct _Map{
    bool isCloud;
    int water;
}Map;

Map myMap[MAX + 1][MAX + 1];
Map tempMap[MAX + 1][MAX + 1];

Oder myOder[MAXODER];

int N, M;

int T;
int sum = 0;

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int wdx[4] = {-1, -1, 1, 1};
int wdy[4] = {-1, 1, -1, 1};

void Input();
void Bibaragi();
void InitCloud();
void SetCloud();
void Rainy();
void WaterCopy();
void CreatCloud();
void ResetCloud(int sel);
void CopyMap();
void CalAllWater();

void DebugOutput();


int main(void)
{
    
    Input();
    CopyMap();
    Bibaragi();
    CalAllWater();
    //DebugOutput();

    
    return 0;
}

void Input(){
    cin >> N >> M;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cin >> myMap[x][y].water;
        }
    }
    
    for(int i = 0; i < M; i++){
       cin >> myOder[i].dest >> myOder[i].dist;
    }
}

void Bibaragi(){
    InitCloud();
    for(T = 0; T < M; T++){
        SetCloud();
        Rainy();
        WaterCopy();
        ResetCloud(MYMAP);
        CreatCloud();
        ResetCloud(TEMPMAP);
        CopyMap();
    }
}

void InitCloud(){
    myMap[N][1].isCloud = true;
    myMap[N][2].isCloud = true;
    myMap[N-1][1].isCloud = true;
    myMap[N-1][2].isCloud = true;
}

void SetCloud(){
    int nx, ny;
    int ndest;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(myMap[x][y].isCloud){
                ndest = myOder[T].dest;
                nx = x + dx[ndest-1] * myOder[T].dist;
                ny = y + dy[ndest-1] * myOder[T].dist;
                
                if(nx > N) {
                    nx = nx % N;
                    if(nx == 0) nx = 5;
                }
                if(nx < 1) nx = 5 + nx % N;
                
                if(ny > N) {
                    ny = ny % N;
                    if(ny == 0) ny = 5;
                }
                if(ny < 1) ny = 5 + ny % N;

                tempMap[nx][ny].isCloud = true;
            }
        }
    }
}

void Rainy(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(tempMap[x][y].isCloud){
                tempMap[x][y].water++;
            }
        }
    }
}

void WaterCopy(){
    int nx, ny;
    int cnt = 0;
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(tempMap[x][y].isCloud){
                for(int i = 0; i < 4; i++){
                    nx = x + wdx[i];
                    ny = y + wdy[i];
                    if(nx > N || ny > N || nx <= 0 || ny <= 0 || tempMap[nx][ny].water == 0) continue;
                    
                    cnt++;
                }
                
                myMap[x][y].water = tempMap[x][y].water + cnt;
                cnt = 0;
            }
        }
    }
}

void CreatCloud(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(myMap[x][y].water >= 2 && !tempMap[x][y].isCloud){
                myMap[x][y].isCloud = true;
                myMap[x][y].water = myMap[x][y].water - 2;   
            }
        }
    }
}

void ResetCloud(int sel){
    if(sel == 1){
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                myMap[x][y].isCloud = false;
            }
        }
    }
    else if(sel == 2){
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                tempMap[x][y].isCloud = false;
            }
        }
    }
    else{
        for(int x = 1; x <= N; x++){
            for(int y = 1; y <= N; y++){
                myMap[x][y].isCloud = false;
                tempMap[x][y].isCloud = false;
            }
        }
    }
}

void CopyMap(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            tempMap[x][y].water = myMap[x][y].water;
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cout << myMap[x][y].water << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cout << myMap[x][y].isCloud << " ";
        }
        cout << "\n";
    }
}

void CalAllWater(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            sum = myMap[x][y].water + sum;
        }
    }
    cout << sum;
}
