#include <iostream>
#include <vector>

#define MAX

using namespace std;


int TC;
int N;

vector <int>v;


int main()
{
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> N;
        if(N % 2 == 0){
            v.push_back(true);
        }
        else v.push_back(false);
    }
    
    for(int i = 0; i < TC; i++){
        if(v[i] == true) cout << "#" << i+1 << " Alice\n";
        else cout << "#" << i+1 << " Bob\n";
    }
    
    return 0;
}
