#include <iostream>
#include <vector>

#define MAX 200

using namespace std;

void Sol();
void Cal();
void Output();

int TC;
int N;

int cnt;
vector <int>v;

int main()
{
    Sol();
    
    return 0;
}


void Sol(){
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> N;
        Cal();
        v.push_back(cnt);
        cnt = 0;
    }
    Output();
}

void Cal(){
    for(int x = 1; x <=N; x++){
        for(int y = 1; y <= N; y++){
            if(x*x + y*y <= N*N) cnt++;
        }
    }
    
    cnt = cnt*4 + N*4 + 1;
}

void Output(){
    for(int i = 0; i < v.size(); i++){
        cout << "#" << i+1 << " " << v[i] << "\n";
    }    
}
