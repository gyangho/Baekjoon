#include <iosfwd>
#include <iostream>

int IsPrime(int n);
int IsPalindrome(int n);
int Reverse(int n);

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  std::cout << "hello";
  int N;
  int iAns;
  std::cin >> N;
  iAns = N;
  while (1)
  {
    if (IsPalindrome(iAns) && IsPrime(iAns))
      std::cout << iAns;
  }

  return 0;
}

int IsPrime(int n)
{
  int iRet = 0;
  for (int i = 2; i < n; i++)
  {
    if (n % i == 0)
    {
      iRet = 1;
      break;
    }
  }
  return iRet;
}

int IsPalindrome(int n)
{
  return (Reverse(n) == n);
}

int Reverse(int n)
{
  int iRet = 0;
  int iTemp = -1;
  int iTens = 10;
  while (1)
  {
    iTemp = n % iTens;
    if (iTemp = 0)
    {
      break;
    }
    iRet = iRet * 10 + iTemp;
    iTens *= 10;
    std::cout << iRet << " ";
  }
  return iRet;
}