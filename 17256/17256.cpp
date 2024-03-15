#include <iosfwd>
#include <iostream>
#include <vector>

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::vector<int> a(3);
  std::vector<int> b(3);
  std::vector<int> c(3);
  int temp;
  for (int i = 0; i < 3; i++)
  {
    std::cin >> a[i];
  }

  for (int i = 0; i < 3; i++)
  {
    std::cin >> c[i];
  }

  b[0] = (c[0] - a[2]);
  b[1] = (c[1] / a[1]);
  b[2] = (c[2] - a[0]);

  std::cout << b[0] << ' ' << b[1] << ' ' << b[2];
}