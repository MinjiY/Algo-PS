/*
    [SWEA] 준홍이의 네 개의 제곱수
 */
#include <cstdio>  
#include <cmath>  
  
int Solve(int N);  
  
int main(void)  
{  
    int T;  
    scanf("%d", &T);  
  
    for (int tc = 0; tc < T; tc++)  
    {  
        int N;  
        scanf("%d", &N);  
        printf("#%d %d\n", tc + 1, Solve(N));  
    }  
  
    return 0;  
}  
  
int Solve(int N)  
{  
    int ret = 0;  
  
    for (int w = 0; w * w <= N; w++)  
    {  
        for (int x = w; w * w + x * x <= N; x++)  
        {  
            for (int y = x; w * w + x * x + y * y <= N; y++)  
            {  
                int z = static_cast<int>(sqrt(N - (w * w + x * x + y * y)));  
  
                if (z < y)  
                    break;  
  
                if (w * w + x * x + y * y + z * z == N)  
                    ret++;  
            }  
        }  
    }  
  
    return ret;  
} 