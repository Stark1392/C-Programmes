 #include <iostream>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while(t--){
        ll N, M, X, Y;
        cin >> N >> M >> X >> Y;
        ll arr[N][M];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++) {
                arr[i][j] = 0;
            }
        }
        ll diff, sum=0;
        if(Y<X){
            diff = X-Y;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++) {
                    if( (i+j)%2 == 0)
                        sum += diff;
                    else
                        sum += 0;
                }
            }
        } else {
            diff = Y - X;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++) {
                    if( (i+j)%2 == 0)
                        sum += X;
                    else
                        sum += diff;
                }
            }
        }
        
        cout << sum << endl;
    }
}