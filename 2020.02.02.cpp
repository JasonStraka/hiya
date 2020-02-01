//发现scanf比cin快很多，且洛谷平台并不稳定，超时的算法等一再会提交可能会卡点ac。
//记忆法搜索：在递归函数体中，若已经计算过则调用数组，否则先把计算出来的值给数组存储再返回数组。优化递归复杂度。
ll w(ll a,ll b,ll c){
    if(a<=0||b<=0||c<=0) return 1;//特例 防下标越界
    else if(rpt[a][b][c]!=0) return rpt[a][b][c];//若已经计算过则调用数组
    else if(a>20||b>20||c>20) rpt[a][b][c]=w(20,20,20);
    else if(a<b&&b<c) rpt[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else rpt[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);//先计算
    return rpt[a][b][c];//返回数组
}//*****/
//复习欧拉筛的10e7以内数字筛法。洛谷简化至约1.5s内计算。o(n2)复杂度。
#define MAX_N 10e7//设定上限1e8
int prime[(int)MAX_N+5];//存储第个素数
void getPrime()
{
    memset(prime, 0, sizeof (prime));//初始化
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) prime[++prime[0]] = i;//标记当前素数 prime[0]计数器
        for (int j = 1; j <= prime[0] && prime[j] <= MAX_N/i; j++) {
            prime[prime[j]*i] = 1;//筛掉倍数
            if (i%prime[j] == 0) break;
        }
    }
}
