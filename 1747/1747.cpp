#include <iosfwd>
#include <iostream>

int IsPrime(int n);
int IsPalindrome(int n);
int Reverse(int n);

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int N;
  int iAns;

  std::cin >> N;
  iAns = N;
  if (N == 1) // 1은 소수가 아니래요
  {
    std::cout << 2;
    return 0;
  }
  while (1)
  {
    if (IsPalindrome(iAns) && IsPrime(iAns))
    {
      std::cout << iAns;
      break;
    }
    iAns += 1;
  }
  return 0;
}

int IsPrime(int n)
{
  int iRet = 1;
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      iRet = 0;
      break;
    }
  }
  return iRet;
}

int IsPalindrome(int n)
{
  if (Reverse(n) == n)
    return 1;
  else
    return 0;
}

int Reverse(int n)
{
  int iRet = 0;
  int iTemp = -1;
  while (1)
  {
    if (n <= 0)
    {
      break;
    }
    iTemp = n % 10;
    iRet = iRet * 10 + iTemp;
    n = n / 10;
  }
  return iRet;
}