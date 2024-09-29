#include <iostream> 
#include <stdio.h>

#define MAX 20

using namespace std;

int N, time;

//bool Help = false;

typedef struct _Shark{
    int x;
    int y;
    int size;
    int count;
}Shark;

Shark myShark = {0,0,2};

typedef struct _Fish{
    int x;
    int y;
    int size;
}Fish;

Fish myFish[MAX*MAX];

void Input();
void Run();
void Output();
void EatFish();
void MoveShark();
void SizeUp();
void FindFish();

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void)
{
    Input();
    //Run();
    //Output();
    //printf("%d %d", myShark.x, myShark.y);
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> myFish[i*N + j].size;
            myFish[i*N + j].x = i;
            myFish[i*N + j].y = j;
            
            if(myFish[i*N + j].size == 9){
                myShark.x = i;
                myShark.y = j;
                myFish[i*N + j].size = 0;
            }
        }
    }
}

void Run(){
    while(1){
        
    }
}

void Output(){
    cout << time;
}

void EatFish(){
    if(myShark.size > myFish[myShark.x*N + myShark.y].size){
        myFish[myShark.x*N + myShark.y].size = 0;
    }
    else if(myShark.size == myFish[myShark.x*N + myShark.y].size){
        
    }
}

void MoveShark(){
    int nx;
    int ny;
    
    for(int k = 0; k < 4; k++){
        nx = myShark.x + nx;
        ny = myShark.y + ny;
    }
    
    time++;
}

void SizeUp(){
    if(myShark.size == myShark.count){
        myShark.size++;
        myShark.count = 0;
    }
}

void FindFish(){
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(myFish[i*N + j].size < myShark.size){
                myFish[i*N + j].x - myShark.x + 
            }
        }
    }
}
