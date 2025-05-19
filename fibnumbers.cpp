#include <iostream>

int fib(int n) {
    int arr[n]{0,1};
    for(int i=2;i<=n;i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
int main(){
    int n;
    std::cin >> n;
    std::cout << fib(n) << endl;
    return 0;
}
