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

  v_iSubDP.assign(INUMOFSTAIR, 0);
  v_vDP.push_back(v_iSubDP);
  v_vDP.push_back(v_iSubDP);

  v_vDP[0][0] = v_iStairs[0];
  v_vDP[1][0] = v_iStairs[1];
  icurrentLoc++;
  // iBiggerone = Biggerone(v_iStairs[0], v_iStairs[1]);
  // in1 = v_vDP[iBiggerone][0] + v_iStairs[2];
  // in2 = v_vDP[iBiggerone][0] + v_iStairs[3];
}

int Calculate(std::vector<int> v_iStairs, std::vector<std::vector<int>> v_vDP, int iCurrentLoc)
{
  int iStairLoc = 0;
  int iCurrentBigger = -1;
  int iPreviousBigger = -1;

  iPreviousBigger = Biggerone(v_vDP[0][iCurrentLoc], v_vDP[1][iCurrentLoc]);
  iStairLoc += iPreviousBigger + 1;
  iCurrentLoc++;

  iCurrentBigger = Biggerone(v_iStairs[iStairLoc + 1], v_iStairs[iStairLoc + 2]);
  if (iCurrentBigger == 0)
  {
    v_vDP[0][iCurrentLoc] = v_vDP[iPreviousBigger][iCurrentLoc - 1] + v_iStairs[iStairLoc + 1];
    v_vDP[1][iCurrentLoc] = v_vDP[iPreviousBigger][iCurrentLoc - 1] + v_iStairs[iStairLoc + 2];
    iStairLoc += 1;
  }
  else
  {
    v_vDP[iCurrentBigger][iCurrentLoc] = v_vDP[1][iCurrentLoc - 1] + v_iStairs[iStairLoc + 1];
  }
  iPreviousBigger = iCurrentBigger;
  iCurrentLoc++;
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