#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Find_Kcase(int N, int K, vector<pair<int, int>> data);

int main()
{
    /*-----------------초기화------------------*/
    int w,v;
    int N;
    int K;
    int max=1;
    vector<pair<int, int>> data;
    pair<int, int> WV;
    /* data==> data[0]=W, data[1]=V*/

    /*--------------------입력------------------*/
    scanf("%d %d",&N,&K); // N값과 K값 입력
    data.reserve(N);
    for(int i=0; i<N; i++)
    {
        scanf("%d %d",&WV.first,&WV.second);
        data.push_back(WV);
    }
    /*-------------------입력확인----------------*/
    cout <<"N: "<< N << " K: " << K << endl;
    for(int i=0; i<N; i++)   
        cout <<"data["<< i <<"]: (" << data[i].first << ", " << data[i].second << ")" << endl;
    max=Find_Kcase(N,K,data);
    cout << max;
    return 0;
}

int Find_Kcase(int N, int K, vector<pair<int, int>> data)
{
    pair<int, int> tmp; 
    vector<vector<int>> Kcase(N+1,vector<int>(K+1,0));//DP표 생성
    cout << "Kcase:" << endl;
    for(int i=1; i<=N; i++)
    {
        tmp=data[i-1];
        for (int j=1; j<=K; j++)
        {
            if(j-tmp.first>=0)
                Kcase[i][j]=max(Kcase[i-1][j],Kcase[i-1][j-tmp.first]+tmp.second);
            else
                Kcase[i][j]=Kcase[i-1][j];
            cout << Kcase[i][j] << " ";
        }
        cout << endl;
    }
    return Kcase[N][K];
}

/*
1 2 3 4 ... 이런식으로 연속되는 경우의수는 모두 찾았지만
1 3 5... 이런식으로 중간 중간 뛰어넘는 경우의수 까먹음
*/