#include <stdio.h>

int multiply(int, int);
int Multiply(int, int);

int main(){
    printf("%d\n",multiply(5,2));
    printf("%d",Multiply(16,2));
    return 0;
}

int multiply(int A, int B){
    int tmp = 0;

    if (A >> 1) {
        tmp = multiply(A >> 1, B << 1);
    }

    return (( (unsigned int)A << 31 ) >> 31) ? (tmp + B) : tmp;
}

int Multiply(int A, int B){
    int sum = 0;
    for (; ;) {
        if (B & 1) sum += A;
        B >>= 1;
        if (B == 0) break;
        A <<= 1;
    }
    return sum;
}

int SHORTmultiply(int A, int B){
    return !B ? 0 : A + SHORTmultiply(A,B-1);
}

int multiple( int A , int B , int i ) {
    int result = 0;
    ( i >= 0 ) && ( result = multiple( A , B , i - 1 ) );
    ( i >= 0 ) && ( ( ( unsigned int )1 << i ) & B ) && ( result += ( ( unsigned int )A << i ) );
    return result;
}

int MUltiply(int A, int B){
    // ��BΪ��������AB=(AB/2)*2+A, ����AB=(AB/2)*2��
    // ��f(A,B)=AB, ����f(A,B) = (A,B/2)<<1+(B&1) ? A : 0
    if (B >> 1) {
        int tmp = MUltiply(A, (B >> 1)) << 1;
        A = tmp + ((B & 1) ? A : 0);
    }
    return A;
}