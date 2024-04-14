#include <iosfwd>
#include <iostream>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int iN;
  int iLeft;
  int iCurrent;
  int iPrev;
  int iCount = 0;
  int iTemp;

  std::cin >> iN;

  iLeft = iN / 10;
  iPrev = iN % 10;
  iCurrent = (iLeft + iPrev) % 10;

  while (1)
  {
    iCount++;
    if (iPrev * 10 + iCurrent == iN)
      break;
    iTemp = iCurrent;
    iCurrent = (iCurrent + iPrev) % 10;
    iPrev = iTemp;
  }

  std::cout << iCount;
  return 0;
}