#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
class FenwickTree{
private:
    std::vector<std::vector<ll>> mod;
public:
    int base, L;
    FenwickTree(int n){
        mod = std::vector<std::vector<ll>> (3, std::vector<ll> ((n*2+1)/3+10, 0));
        base = n;
        L = (n*2+1)/3+10;
    }
    ll update(int ind){
        int m = (ind+300000)%3, new_ind=(ind+base)/3+2, res;
        res = get(L-1,m) - get(new_ind-1, m);
        while (new_ind < L){
            mod[m][new_ind] += 1;
            new_ind += (new_ind & -new_ind);
        }
        return res;
    };
    ll get(int ind, int m){
        ll total = 0;
        while (ind > 0){
            total += mod[m][ind];
            ind -= (ind & -ind);
        }
        return total;
    }
};

int main(){
    std::vector<int> list(3,0);
    int x=1;
    list[x++] = 5;
    for (int num:list) std::cout << num << ", ";
    std::cout << std::endl;
    return 0;
}