#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

void Sol();
void Ouput();

int TC;
int length;
char st[MAX+1];
vector <int>v;

int main()
{
    Sol();
    return 0;
}


void Sol(){
    cin >> TC;
    for(int x = 0; x < TC; x++){
        cin >> length;
        if(length % 2 != 0) {
            v.push_back(false);
            continue;
        }
        
        for(int i = 1; i <= length; i++){
            cin >> st[i];
        } 
        int cnt = 0;
        for(int i = 1; i <= length / 2; i++){
            
            if(st[i] == st[i + length/2]){
                cnt++;
            }
            else{
                v.push_back(false);
                break;
            }
            
            if(cnt == length / 2) v.push_back(true);
        } 
    }
    
    Ouput();
}

void Ouput(){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == true){
            cout << "#" << i+1 << " " << "Yes";
        }
        else cout << "#" << i+1 << " " << "No";
        
        cout << "\n";
    }
    
}
