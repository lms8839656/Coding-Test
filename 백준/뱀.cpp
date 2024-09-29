#include <iostream>
#include <vector>

#define MAX 100
#define APPLE 1
#define SNAKE 2

using namespace std;

int MAP[MAX+1][MAX+1];

typedef struct _Snake{
    int x;
    int y;
}Snake;

typedef struct _Oder{
    int time;
    char oder;
}Oder;

Oder myOder[100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector <Snake>mySnake;
int head = 0;

int N, K, L;

int gametime = 0;
bool EndFlag = false;

void Input();
void NextHead();
void Run();
void SetSnake();


void DebugOutput();

int main(void)
{
    Input();
    //DebugOutput();
    Run();
    cout << gametime;
    
    return 0;
}

void Input(){
    cin >> N >> K;
    
    int x, y;
    for(int i = 0; i < K; i++){
        cin >> x >> y;
        MAP[x][y] = APPLE;
    }
    
    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> myOder[i].time >> myOder[i].oder;
    }
}

void NextHead(){
    int nx, ny;
    bool IsApple = false;
    Snake tempSnake;
    
    
    nx = mySnake[0].x + dx[head];
    ny = mySnake[0].y + dy[head];
    
    if(nx > N || ny > N || nx <= 0 || ny <= 0 || MAP[nx][ny] == SNAKE){
        EndFlag = true;
        return;
    }
    
    mySnake.push_back(tempSnake);
        
    for(int i = mySnake.size(); i > 0; i--){
        mySnake[i] = mySnake[i-1];
    }
    
    mySnake[0].x = nx;
    mySnake[0].y = ny;
    
    if(MAP[nx][ny] != APPLE){
        nx = mySnake[mySnake.size()-1].x;
        ny = mySnake[mySnake.size()-1].y;
        MAP[nx][ny] = 0;
        mySnake.pop_back();
    }
    
}

void Run(){
    Snake tempSnake = {1, 1};
    mySnake.push_back(tempSnake);
    int Odertime = 0;
    
    
    while(!EndFlag){
        gametime++;
        NextHead();
        SetSnake();
        if(gametime == myOder[Odertime].time){
            if(myOder[Odertime].oder == 'D'){
                head++;
                if(head == 4) head = 0;
            }
            else{
                head--;
                if(head == -1) head = 3;
            }
            Odertime++;
        }
    }
}

void SetSnake(){
    int nx, ny;
    for(int i = 0; i < mySnake.size(); i++){
        nx = mySnake[i].x;
        ny = mySnake[i].y;
        MAP[nx][ny] = SNAKE;
    }
}


void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
}

