#include <iostream>

int main(){
    __int64 n, m, a;
    std::cin >> n >> m >> a;
    std::cout << (n/a+(n%a>0))*(m/a+(m%a>0)) << std::endl;
    return 0;
}