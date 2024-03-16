#include <iosfwd>
#include <iostream>
#include <vector>

int INUMOFSTAIR;

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  std::vector<int> v_iStairs;
  std::vector<std::vector<int>> v_vDP;
  std::vector<int> v_iSubDP;

  int iTemp;
  int icurrentLoc = 0;
  int iBiggerone = -1;
  int in1;
  int in2;

  std::cin >> INUMOFSTAIR;

  v_iStairs.assign(INUMOFSTAIR, 0);
  for (int i = 0; i < INUMOFSTAIR; i++)
  {
    std::cin >> iTemp;
    v_iStairs[i] = iTemp;
  }

  v_iSubDP.assign(INUMOFSTAIR, -1);
  v_vDP.push_back(v_iSubDP);
  v_vDP.push_back(v_iSubDP);

  // 처음 계단은 포함하지 않는다고 했으니까 무조건 처음 계단을 밟는게 맞다
  v_vDP[0][0] = v_iStairs[0];
  v_vDP[1][0] = v_iStairs[0];
  icurrentLoc++;
}

int Calculate(std::vector<int> v_iStairs, std::vector<std::vector<int>> v_vDP)
// parameter: 계단 값 , DP표
{
  int iCurrentLoc = 1;     // DP표에서 현재 위치(지나온 계단의 수와 같음)[1,INUMOFSTAIR]
  int iStairLoc = 1;       // 현재 위치한 계단 층 수[1,INUMOFSTAIR]
  int iCurrentBigger = -1; // 새로 밟을 계단 중 큰 것[0,1]
  int iPreviousBigger = 1; // 작성된 DP표 중 직전에 더 큰 것[0,1]

  while (1)
  {
    if (iPreviousBigger == 0) // 이전에 큰 것이 한 칸 이동한 것일 경우
    {
      /*이전에 큰 것이 1칸 이동한 경우이면, 연속으로 3칸을 못 밟기 때문에 2칸 뒤의 경우와 이전에 1칸만 이동하고 2칸을
      이동한 것을 비교 결국엔 같은 계단을 이전 어..? 그러면 결국 같은 값을 더하는 거 잖아 그러면 2칸 이동한게 무조건 큰
      거 아님? ㅋㅋ 근데 맞나 1 4 3 2 100 1000 1 이면 어 안되노 ㅋㅋ*/
      iCurrentBigger = Biggerone(v_iStairs[iStairLoc + 1], v_iStairs[iStairLoc + 2]);
      if (iCurrentBigger == 0) // 한 칸 이동하는 것이 더 크다
      {
        v_vDP[0][iCurrentLoc] = v_vDP[iPreviousBigger + 1][iCurrentLoc - 1] + v_iStairs[iStairLoc + 2];
        v_vDP[1][iCurrentLoc] = v_vDP[iPreviousBigger][iCurrentLoc - 1] + v_iStairs[iStairLoc + 2];
        iStairLoc += 1;
      }
      else // 두 칸 이동이 더 크다
      {
        v_vDP[iCurrentBigger][iCurrentLoc] = v_vDP[1][iCurrentLoc - 1] + v_iStairs[iStairLoc + 1];
      }

      iPreviousBigger = iCurrentBigger;
      iCurrentLoc++;
    }
    else // 이전에 큰 것이 두칸 이동한 것일 경우
    {
    }

    if (iStairLoc > INUMOFSTAIR)
      break;
  }
}

int Biggerone(int n1, int n2)
{
  int ans;
  if (n1 >= n2)
    ans = 0;
  else
    ans = 1;

  return ans;
}