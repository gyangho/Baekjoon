#include <algorithm>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <vector>

std::vector<int> v_iNumber;

int R = 0;
int Y = 0;
int G = 0;
int B = 0;

int NumofSame();
int FourCardorDoublePair();
int Flush();
int Straight();
int Calculate();

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  char str[6];

  v_iNumber.assign(5, -1);
  for (int i = 0; i < 5; i++)
  {
    std::cin.getline(str, 5);
    v_iNumber[i] = str[2] - 48;
    switch (str[0])
    {
    case 'R':
      R++;
      break;
    case 'B':
      B++;
      break;
    case 'G':
      G++;
      break;
    case 'Y':
      Y++;
      break;
    }
  }
  std::sort(v_iNumber.begin(), v_iNumber.end());
  // for (auto i : v_iNumber)
  //   std::cout << i << " ";
  // std::cout << "\n";
  std::cout << Calculate();
}

int NumofSame()
{
  int iNumofSame = 0;
  int temp = 0;
  for (int i = 0; i < 4; i++)
  {
    if (v_iNumber[i] == v_iNumber[i + 1])
    {
      iNumofSame++;
      if (temp == 0)
      {
        iNumofSame++;
      }
      temp = 1;
      continue;
    }
    temp = 0;
  }
  if (iNumofSame == 1)
    iNumofSame = 0;
  // std::cout << "NumofSame: " << iNumofSame << "\n";
  return iNumofSame;
}

int FourCardorDoublePair()
{
  int ret = -1;
  if (v_iNumber[0] == v_iNumber[3] || v_iNumber[1] == v_iNumber[4])
  {
    ret = 1;
  }
  else
    ret = 2;
  return ret;
}

int Flush()
{
  int ret = -1;
  if (std::abs(R - B - Y - G) == 5)
    ret = 1;
  return ret;
}

int Straight()
{
  int ret = -1;
  if (v_iNumber[4] - v_iNumber[0] == 4)
  {
    ret = 1;
  }
  return ret;
}

int Calculate()
{
  int iNumofSame = NumofSame();
  int iScore = 0;
  switch (iNumofSame)
  {
  case 0: {
    int f = Flush();
    int s = Straight();
    if (s + f > 1)
    {
      iScore = v_iNumber[4] + 900;
      break;
    }
    else if (s + f == 0)
    {
      if (s == 1)
      {
        iScore = v_iNumber[4] + 500;
      }
      else
      {
        iScore = v_iNumber[4] + 600;
      }
      break;
    }
    else
      iScore = v_iNumber[4] + 100;
    break;
  }
  case 2: {
    for (int i = 0; i < 4; i++)
    {
      if (v_iNumber[i] == v_iNumber[i + 1])
      {
        iScore = v_iNumber[i] + 200;
        break;
      }
    }
    break;
  }
  case 3: {
    iScore = v_iNumber[2] + 400;
    break;
  }
  case 4: {
    if (FourCardorDoublePair() == 1)
    {
      iScore = v_iNumber[1] + 800;
      break;
    }
    else
    {
      iScore = v_iNumber[3] * 10 + v_iNumber[1] + 300;
      break;
    }
  }
  case 5: {
    if (v_iNumber[1] == v_iNumber[2])
    {
      iScore = 10 * v_iNumber[0] + v_iNumber[4] + 700;
    }
    else
    {
      iScore = 10 * v_iNumber[4] + v_iNumber[0] + 700;
    }
    // iScore = 10 * v_iNumber[0] + v_iNumber[4] + 700;
    break;
  }
  }
  return iScore;
}