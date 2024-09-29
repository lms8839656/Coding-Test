#include <stdio.h>
#include <iostream>
#include <string>

#define MAX 18

using namespace std;

int N, M;



typedef struct _Room{
    string name;
    bool time[MAX+1];    
}Room;

Room myRoom[51];


void Input();
void DebugOutput();
void Output();

int main(void)
{
    Input();
    DebugOutput();
    return 0;
}

void Input(){
    int a, b;
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        cin >> myRoom[i].name;
    }
    
    string temp;
    
    for(int i = 1; i <= M; i++){
        cin >> temp;
        
        for(int j = 1; j <= N; j++){
            if(temp == myRoom[j].name){
                cin >> a >> b;
                
                for(int k = a; k < b; k++){
                    myRoom[j].time[k] = true;
                }
            }
        }
    }
}

void DebugOutput(){
    for(int i = 9; i <= MAX; i++){
        cout << myRoom[1].time[i] << " ";
    }
}

void Output(){
    bool CheckFlag = false;
    
    for(int i = 1; i <= N; i++){
        cout << "Room " << myRoom[i].name << ":\n";
        
    }
}
