#include <iostream>
#include <vector>

#define MAX 50

using namespace std;

int MAP[MAX+1][MAX+1];
int tempMAP[MAX+1][MAX+1];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct _Fire{
    int x;
    int y;
    int m;
    int d;
    int s;
}Fire;

//Fire myFire[MAX*MAX];
vector <Fire>myFire;

int N, M, K;

void Input();
void SetMapFire();
void MoveFire();
void IsTwoFire();
void ResetMap();
void Sum();
void DebugOutput();

int main(void)
{
    Input();
    //DebugOutput();
    while(K){
        MoveFire();
        SetMapFire();
        IsTwoFire();
        ResetMap();
        K--;
        //DebugOutput();
    }
    //DebugOutput();
    Sum();
    
    return 0;
}

void Input(){
    cin >> N >> M >> K;
    //oder_num = M;
    Fire tempFire;
    for(int i = 0; i < M; i++){
        cin >> tempFire.x;
        cin >> tempFire.y;
        cin >> tempFire.m;
        cin >> tempFire.s;
        cin >> tempFire.d;
        myFire.push_back(tempFire);
    }
}

void SetMapFire(){
    int x, y;
    for(int i = 0; i < myFire.size(); i++){
        x = myFire[i].x;
        y = myFire[i].y;
        MAP[x][y]++;
    }
}

void MoveFire(){
    int nx, ny;
    for(int i = 0; i < myFire.size(); i++){
        nx = myFire[i].d;
        ny = myFire[i].d;
        nx = dx[nx];
        ny = dy[ny];
        myFire[i].x = myFire[i].x + myFire[i].s * nx;
        myFire[i].y = myFire[i].y + myFire[i].s * ny;
        if(myFire[i].x > N) myFire[i].x = myFire[i].x % N;
        if(myFire[i].x < 0) myFire[i].x = N + (myFire[i].x % N);
        if(myFire[i].x == 0) myFire[i].x = N;
        
        if(myFire[i].y > N) myFire[i].y = myFire[i].y % N;
        if(myFire[i].y < 0) myFire[i].y = N + (myFire[i].y % N);
        if(myFire[i].y == 0) myFire[i].y = N;
    }
}

void IsTwoFire(){
    Fire tempFire;
    int cnt = 0;
    int tempDis;
    bool checkSame;
    bool FirstMeet;
    int orgsize = myFire.size();
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            if(MAP[x][y] > 1){
                cnt = 0;
                FirstMeet = false;
                checkSame = false;
                tempFire.x = 0;
                tempFire.y = 0;
                tempFire.s = 0;
                tempFire.m = 0;
                tempFire.d = 0;
                
                for(int i = 0; i < orgsize; i++){
                    if(myFire[i].x == x && myFire[i].y == y){
                        if(FirstMeet == false){
                            FirstMeet = true;
                            tempDis = myFire[i].d % 2;
                            checkSame = true;
                        }
                        
                        if(checkSame){
                            if(tempDis != myFire[i].d % 2) checkSame = false;
                        }
                        tempFire.m = myFire[i].m + tempFire.m;
                        tempFire.s = myFire[i].s + tempFire.s;
                        myFire.erase(myFire.begin() + i);
                        orgsize--;
                        i--;
                        cnt++;
                    }
                }
                tempFire.x = x;
                tempFire.y = y;
                tempFire.s = tempFire.s / cnt;
                tempFire.m = tempFire.m / 5;
                if(tempFire.m == 0) continue;
                if(checkSame == true){
                    for(int k = 0; k < 4; k++){
                        tempFire.d = k * 2;
                        myFire.push_back(tempFire);
                    }
                }
                else{
                    for(int k = 0; k < 4; k++){
                        tempFire.d = k * 2 + 1;
                        myFire.push_back(tempFire);
                    }
                }
                

            }
        }
    }
}

void Sum(){
    int sum = 0;
    for(int i = 0; i < myFire.size(); i++){
        sum = myFire[i].m + sum;
    }
    //cout << "\n";
    cout << sum;
}

void ResetMap(){
    for(int x = 1; x <= N; x++){
        for(int y = 1; y <= N; y++){
            MAP[x][y] = 0;
        }
    }
}

void DebugOutput(){
    
//    cout << "\n";
//    int x, y;
//    for(int i = 0; i < myFire.size(); i++){
//        x = myFire[i].x;
//        y = myFire[i].y;
//        MAP[x][y]++;
//    }
//    for(int x = 1; x <= N; x++){
//        for(int y = 1; y <= N; y++){
//            cout << MAP[x][y] << " ";
//        }
//        cout << "\n";
//    }

    
    cout << "\n";
    for(int i = 0; i < myFire.size(); i++){
        cout << myFire[i].x << " " << myFire[i].y;
        cout << "\n";
    }
    
}
