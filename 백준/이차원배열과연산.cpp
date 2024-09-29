#include <iostream>
#include <vector>

#define MAX 100

/*
1 2 2
3 1 1
2 1 3
3 3 3

*/

//vector로 푸는법 찾아보기  
using namespace std;

int MAP[MAX+1][MAX+1];
int Numcnt[MAX+1][MAX+1];
vector <pair<int, int> >num;

int r, c, k;

int xsize = 3;
int ysize = 3;

int time = 0;

void Input();
bool CheckCondition();
void Calculate();
void SortNum();
void ResetNumcnt();
void ResetMAP();
void DebugOutput();



int main(void)
{
    Input();

    while(MAP[r][c] != k){
        if(time > 100){
            cout << "-1";
            return 0;
        }
        time++;
        Calculate();
        ResetNumcnt();
        
    }

    cout << time;
    return 0;
}

void Input(){
    cin >> r >> c >> k;
    for(int x = 1; x <= 3; x++){
        for(int y = 1; y <= 3; y++){
            cin >> MAP[x][y];
        }
    }
}

bool CheckCondition(){
    if(MAP[r][c] == k) return true;
    else false;
}

void Calculate(){
    int tempNum;
    
    if(xsize >= ysize){//R Calculate
        int tempsize = ysize;
        for(int x = 1; x <= xsize; x++){
            for(int y = 1; y <= ysize; y++){
                if(MAP[x][y] == 0) continue;
                tempNum = MAP[x][y];
                Numcnt[x][tempNum]++;
                MAP[x][y] = 0;
            }
            
            for(int y = 1; y <= 100; y++){
                if(Numcnt[x][y] == 0) continue;
                tempNum = Numcnt[x][y];
                num.push_back(make_pair(y, tempNum));
            }
            
            SortNum();
            
            tempNum = num.size();
            if(num.size() > 100) tempNum = 100;
            for(int y = 1; y <= tempNum; y++){
                MAP[x][2*y-1] = num[y-1].first;
                MAP[x][2*y] = num[y-1].second;
            }
            if(2*num.size() > tempsize) tempsize = num.size()*2;
            num.clear();
        } 
        ysize = tempsize;
    }
    else if(ysize > xsize){//C Calcaulate
        int tempsize = xsize;
        for(int y = 1; y <= ysize; y++){
            for(int x = 1; x <= xsize; x++){
                if(MAP[x][y] == 0) continue;
                tempNum = MAP[x][y];
                Numcnt[tempNum][y]++;
                MAP[x][y] = 0;
            }
            
            for(int x = 1; x <= 100; x++){
                if(Numcnt[x][y] == 0) continue;
                tempNum = Numcnt[x][y];
                num.push_back(make_pair(x, tempNum));
            }
            
            SortNum();
            
            tempNum = num.size();
            if(num.size() > 100) tempNum = 100;
            for(int x = 1; x <= tempNum; x++){
                MAP[2*x-1][y] = num[x-1].first;
                MAP[2*x][y] = num[x-1].second;
            }
            if(2*num.size() > tempsize) tempsize = num.size()*2;
            num.clear();
        } 
        xsize = tempsize;
    }
    
    
}

void SortNum(){
    pair<int, int> temp;
    for(int x = 0; x < num.size(); x++){
        for(int sel = x; sel < num.size(); sel++){
            if(num[x].second > num[sel].second){
                temp = num[x];
                num[x] = num[sel];
                num[sel] = temp;
            }
            else if(num[x].second == num[sel].second){
                if(num[x].first > num[sel].first){
                    temp = num[x];
                    num[x] = num[sel];
                    num[sel] = temp;
                }
            } 
        }
    }
}

void ResetNumcnt(){
    for(int x = 1; x <= 100; x++){
        for(int y = 1; y <= 100; y++){
            Numcnt[x][y] = 0;
        }
    }
}

void ResetMAP(){
    for(int x = 1; x <= 100; x++){
        for(int y = 1; y <= 100; y++){
            MAP[x][y] = 0;
        }
    }
}

void DebugOutput(){
    cout << "\n";
    for(int x = 1; x <= xsize; x++){
        for(int y = 1; y <= ysize; y++){
            cout << MAP[x][y] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    for(int i = 0; i < num.size(); i++){
        cout << num[i].first << " ";
    }
    
    cout << "\n";
    for(int i = 0; i < num.size(); i++){
        cout << num[i].second << " ";
    }
}
