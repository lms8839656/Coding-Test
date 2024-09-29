#include <iostream> 

#define MAX 100

using namespace std;

int N, M;

typedef struct _Gu{
    int length;
    int v;
}Gu;

Gu myGu[MAX+1];

void Input();
void Check();


int dd = 0;

int main(void)
{
    
    Input();
    Check();
    
    cout << dd;
    return 0;
}

void Input(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> myGu[i].length >> myGu[i].v;
    }
}
void Check(){
    int tlength, tv;
    int temp = 0;
    int sel;
    
    for(int i = 1; i <= M; i++){
        cin >> tlength >> tv;
        
        
        /*
        sel = i;
        
        while(tlength > 0 && sel <= M){
            if(tv > myGu[sel].v) temp = tv - myGu[sel].v;
            
            tlength = tlength - myGu[sel].length;
            
            if(temp > dd) dd = temp;
            
            sel++;
        }
        */
        
        
        
        for(int j = 1; j <=N; j++){
            if(tlength <= myGu[j].length){
                if(tv > myGu[j].v) temp = tv - myGu[j].v;
                
                if(temp > dd) dd = temp;
                
                break;
            }
            else tlength = tlength - myGu[j].length;
        } 
        
    }
}
