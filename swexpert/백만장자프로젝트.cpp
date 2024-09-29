#include <iostream>
#include <vector>

using namespace std;


int TC, N;


vector <int>Price;

void Input();
void DFS(int Action);
void Output();

int main()
{
    Input();
    DFS(1);
    Output();
    return 0;
}

void Input(){
    int temp;
    cin >> TC >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        Price.push_back(temp);
    }
}


int depth = -1;
int benefit = 0;
int Maxbenefit = 0;
int num = 0;
void DFS(int Action){
    //사고 안사고 팔고 
    depth++;
    
    switch(Action){
        case 0: //사고 
            benefit = benefit - Price[depth];
            num++;
            break;
        case 1: //안사고 
            
            break;
        case 2: //팔고 
            benefit = benefit + num * Price[depth];
            num = 0;
            break;
    }
    
    
    
    for(int i = 0; i < 3; i++){
        if(depth >= 3) {
            if(Maxbenefit < benefit) Maxbenefit = benefit;
            return;
        }
        DFS(i);
    }
    
    num = 0;
    depth = -1;
    Maxbenefit = 0;
    num = 0;
}

void Output(){
    cout << Maxbenefit;
}
