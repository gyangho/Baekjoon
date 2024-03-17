#include <iosfwd>
#include <iostream>
#include <vector>

int INUMOFSTAIR;

int Biggerone(int n1, int n2);
int Calculate(std::vector<int> v_iStairs, std::vector<int> v_iDP);

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::vector<int> v_iStairs;
  std::vector<int> v_iDP;

  std::cin >> INUMOFSTAIR;
  INUMOFSTAIR--;

  v_iStairs.assign(INUMOFSTAIR + 1, -1);
  v_iDP.assign(INUMOFSTAIR + 1, -1);

  for (int i = 0; i < INUMOFSTAIR + 1; i++)
  {
    std::cin >> v_iStairs[i];
  }

  // 초기 값 설정
  v_iDP[0] = v_iStairs[0];
  v_iDP[1] = v_iStairs[0] + v_iStairs[1];
  v_iDP[2] = Biggerone(v_iStairs[0], v_iStairs[1]) + v_iStairs[2];
  std::cout << Calculate(v_iStairs, v_iDP);

  return 0;
}

int Calculate(std::vector<int> v_iStairs, std::vector<int> v_iDP)
// parameter: 계단 값 , DP표
{
  int iCurrentLoc = 3;     // 마지막으로 위치할 계단
  int iCurrentBigger = -1; // 비교 값 중 큰 값

  while (1)
  {
    /*iCurrentLoc까지 이동할 때 일어날 수 있는 경우의 수는 두가지다.
      1. i-3까지 이동할 때 최대값 + i-1 번째 계단의 값 + i 번째 계단의 값
      2. i-2까지 이동할 때 최대값 + i 번째 계단의 값
      이 중 더 큰 것을 작성하여 INUMOFSTAIR값 까지 이동할 때 최대값을 계속 구해주면 된다.*/
    v_iDP[iCurrentLoc] =
        Biggerone(v_iDP[iCurrentLoc - 3] + v_iStairs[iCurrentLoc - 1], v_iDP[iCurrentLoc - 2]) + v_iStairs[iCurrentLoc];

    iCurrentLoc++;
    if (iCurrentLoc > INUMOFSTAIR)
      break;
  }

  return v_iDP[INUMOFSTAIR];
}

int Biggerone(int n1, int n2)
{
  int ans;
  if (n1 >= n2)
    ans = n1;
  else
    ans = n2;
  return ans;
}