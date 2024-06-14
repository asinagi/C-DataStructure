// #include <stdio.h>
// int factorial(int n) { //O(n)
//     if (n == 0) // 0! = 1
//         return 1;
//     else
//         return n * factorial(n - 1);
// }

// int fac2(int n){
//     int result2=1;
//     for (int i=2; i<=n; i++){
//         result2*=i;
//     }
//     return result2;
// }

// int main() {
//     int num;
//     int result;
//     int result2;
//     scanf("%d", &num);

//     result = factorial(num);

//     printf("%d %d\n", num, result);
//     result2 = fac2(num);
//     printf("%d\n", result2);
//     return 0;
// }

#include <stdio.h>

int fact(int n) {
    if (n == 0) 
        return 1;
    else 
        return n * fact(n-1);
    
}
int main() {
    int num;
    int result1;
    scanf("%d", &num);
    result1= fact(num);
    printf("%d\n", result1);
    return 0;
}