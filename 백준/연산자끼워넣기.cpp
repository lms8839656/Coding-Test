#include <iostream>

#define MAX 100

using namespace std;

typedef struct _Cal{
    int add;
    int sub;
    int mul;
    int div;
}Cal;

Cal myCal;

int Number[MAX];

int N;

int sum = 0;
int minsum = 1000000001;
int maxsum = -1000000001;

void Input();
void DFS(int selCal, int depth);

int main(void)
{
    Input();
    
    
    
    for(int i = 0; i < 4; i++){
        sum = Number[0];
        DFS(i, 1);   
    }
    
    cout << maxsum << "\n" << minsum;
    return 0;
}

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> Number[i];
    }
    
    cin >> myCal.add >> myCal.sub >> myCal.mul >> myCal.div;
}

void DFS(int selCal, int depth){
    
    if(depth > N-1){
        if(sum > maxsum) maxsum = sum;
        if(sum < minsum) minsum = sum;
        
        
        return;
    }
    
    int prevsum = sum;
    
    for(int i = 0; i < 4; i++){
        switch(selCal){
            case 0:
                if(myCal.add == 0) continue;
                sum = sum + Number[depth];
                myCal.add--;
                break;
            case 1:
                if(myCal.sub == 0) continue;
                sum = sum - Number[depth];
                myCal.sub--;
                break;
            case 2:
                if(myCal.mul == 0) continue;
                sum = sum * Number[depth];
                myCal.mul--;
                break;
            case 3:
                if(myCal.div == 0) continue;
                sum = sum / Number[depth];
                myCal.div--;
                break;
        }
        depth++;
        DFS(i, depth);
        depth--;
        sum = prevsum;
        switch(selCal){
            case 0:
                myCal.add++;
                break;
            case 1:
                myCal.sub++;
                break;
            case 2:
                myCal.mul++;
                break;
            case 3:
                myCal.div++;
                break;
        }
    }
}
