#include <stdio.h>
#include <iostream>

using namespace std;

int arr[9]; 

void Input();

bool FlagMix = true;
bool FlagDe = false;
bool FlagAc = false;

int main(void)
{
    Input();
    
    int cnt;
   
    switch(arr[1]){
        case 1:
            FlagAc = true;
            for(cnt = 1; cnt < 9; cnt++){
                if(cnt != arr[cnt]){
                    FlagMix = true;
                    FlagDe = false;
                    FlagAc = false;    
                }
            }
            break;
        case 8:
            FlagDe = true;
            for(cnt = 8; cnt > 0; cnt--){
                if(cnt != arr[9-cnt]){
                    FlagMix = true;
                    FlagDe = false;
                    FlagAc = false; 
                }
            }
            break;
    }
    
    
    if(FlagAc == true) cout << "ascending";
    else if(FlagDe == true) cout << "descending";
    else cout << "mixed";

    return 0;
}

void Input(){
    for(int i = 1; i < 9; i++){
        cin >> arr[i];
    }
}

