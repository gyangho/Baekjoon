#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Find_Kcase(int N, int K, vector<pair<int, int>> data);
vector<vector<int>> Find(int i, int N, int K, vector<pair<int, int>> data, vector<vector<int>> Kcase);
int Max(vector<vector<int>> Kcase, vector<pair<int, int>> data);
bool cmp(pair<int ,int> a, pair<int, int> b)
{
    return a.second<b.second;
}

int main()
{
        /*-----------------초기화------------------*/
    int w,v;
    int N;
    int K;
    int max=1;
    vector<vector<int>> Kcase;
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
    sort(data.begin(), data.end(), cmp);
    Kcase=Find_Kcase(N,K,data);
    max=Max(Kcase,data);
    printf("%d",max);
    return 0;
}

vector<vector<int>> Find_Kcase(int N, int K, vector<pair<int, int>> data)
{
    vector<int> tmpv; //Kcase에 넣을 벡터를 임시로 저장해놓는 벡터
    vector<vector<int>> Kcase;//리턴할 합이 K이하인 경우의 수들의 벡터
    int sum;//직전 경우의 w합(중복 계산을 막기 위함)
    int tmp;//임시 값 넣을 곳
    for(int i=0; i<N; i++)
    {
        tmpv.clear();  //초기화 안해줘서 에러 났었음!!!!!!
        sum=data[i].first;
        if(sum<=K)
        {
            tmpv.push_back(i);
            Kcase.push_back(tmpv);
            Kcase=Find(i,N,K,data,Kcase); //Kcase 리턴 안해줘서 상위 함수에서 적용 안됨!!!!!!!
        }
    }

    return Kcase;
}

vector<vector<int>> Find(int i, int N, int K,vector<pair<int, int>> data, vector<vector<int>> Kcase)
{
    vector<int> tmpv;
    //임시 값 벡터 초기 값을 위해 kcase의 마지막 값으로 초기화
    int sum;//직전 경우의 w합(중복 계산을 막기 위함)
    int tmp;//임시 값 넣을 곳
    int r=0;
    sum=0;
    tmpv=Kcase.back();

    for(int a=0; a<tmpv.size();a++)
        sum+=data[tmpv[a]].first;
    for(int j=i+1;j<N;j++)
    {
        tmp=sum+data[j].first;
        if(tmp<=K)
        {
             tmpv.push_back(j);
            if(r==0)
                Kcase.pop_back(); // 이전 find에서 탈출하면 탈출하기 직전의 자리의 숫자가 무조건 바뀜. 한번 탈출 한 이후로는 중복이 안됨.
            Kcase.push_back(tmpv);
            Kcase=Find(j,N,K,data,Kcase); //재귀호출
            tmpv.pop_back();
            r=1;
            /*
            이전에 K보다 작아서 find로 진입했을때, tmpv에 진입할 때 탐색하는 물건번호를 가지고 있는데,
            그 위치의 find를 탈출하고 난 후에 계산하는 경우의 수는
            진입할 때 물건번호를 제외한 경우의 수 이기 때문에 마지막 원소를 제거해줘야한다.
            ex) 1 2 3번 물건의 무게가 3 4 1이어서 합이 8이므로 find에 진입
            ->find에 진입해서 뒷번호의 물건들을 다 탐색(1 2 3을 포함한 모든 경우의 수)
            ->find 탈출 후에 탐색해야할 경우의 수는 탐색하기 직전의 경우(1 2를 포함한 경우의 수) 이므로 마지막 원소를(3) 제거해야함
            */
        }
    }
    return Kcase;
}

int Max(vector<vector<int>> Kcase, vector<pair<int, int>> data)
{
    int sum=0;
    int max=0;

    for(int i=0; i<Kcase.size();i++)
    {
        sum=0;
        for(int j=0; j<Kcase[i].size();j++) //여기 j인데 i로 오타낫음ㅋㅋ
            sum+=data[Kcase[i][j]].second;
        if(sum>max)
            max=sum;
    }
    return max;
}

/*
1 2 3 4 ... 이런식으로 연속되는 경우의수는 모두 찾았지만
1 3 5... 이런식으로 중간 중간 뛰어넘는 경우의수 까먹음
*/