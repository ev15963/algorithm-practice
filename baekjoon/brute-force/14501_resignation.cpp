/*
    완전탐색 부분에 할당되어 있어서, 완전탐색 디렉토리에 넣었지만, dp로 풀었다.

    완전 탐색 분류에서 풀고 있어서 해결해보려 했으나, 내가 풀었던 방식이 동작하지 않는다는 것을 발견했다.
    처음에는 시작점 하나씩 증가시켜가며, 최대 연속으로 일할 수 있는 날을 구했는데, 
    4번째 테스트케이스 같은 경우에 제대로 동작하지 않는 알고리즘이었다...

   1. 해당 날에 상담 x -> 그 다음날

   2. 해당 날에 상담 o -> 해당 상담을 하는데 걸리는 일 수 만큼 넘어감

    dp로 푸는 문제였다.
    거꾸로 탐색하면서, 최대 이익을 비교한다.
    만약 5일이 주어진 경우, 5일의 소요시간이 1일 아닌이상 최대값은 0이다.
    4일은 2일보다 많이 걸릴경우 최대값은 0이다.
    ...

    솔직히 dp부분은 정말 많이 부족한것같다..

    +완전 탐색으로 풀려면 dfs를 사용한다.

*/
#include <stdio.h>
#include <algorithm>
#define MAX 17

using namespace std;

int n;
int t[MAX],p[MAX];
int dp[MAX];

// 해당 날부터 벌 수 있는 최대의 돈 
int dfs(int day) {
    if(day>=n+1) return 0;
    int sum=0;

    if(t[day]+day<=n+1) sum=max(sum, dfs(day+t[day])+p[day]); // 상담 o
    if(day+1<n+1) sum=max(sum, dfs(day+1)); // 상담 x

    return sum;
}

int main(void) {
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for(int i=n;i>0;i--) {
        int next=i+t[i]; // 해당 날짜를 선택할 때, 그 다음에 가능한 날짜 인덱스 
        if(next>n+1) dp[i]=dp[i+1]; // 다음날짜가 전체 일 수 보다 큰 경우
        else dp[i]=max(dp[i+1],dp[next]+p[i]); // 해당 날짜를 선택하지 않는 것이 큰 지, 선택하는 것이 큰 지 
    }

    printf("%d\n", dp[1]);
    printf("%d\n", dfs(1));

    return 0;
}