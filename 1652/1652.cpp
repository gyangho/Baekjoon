#include <iosfwd>
#include <iostream>
#include <queue>
#include <vector>

int N;

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  char Val;
  std::vector<std::vector<char>> v_cRoom;
  std::vector<char> v_cSub;
  std::pair<int, int> ii_pair;
  std::vector<std::pair<int, int>> X;

  std::cin >> N;
  v_cSub.assign(N, -1);
  for (int i = 0; i < N; i++)
  {
    v_cRoom.push_back(v_cSub);
  }

  for (int x = 0; x < N; x++)
  {
    for (int y = 0; y < N; y++)
    {
      std::cin >> Val;
      if (Val == 'X')
      {
        ii_pair.first = x;
        ii_pair.second = y;
        X.push_back(ii_pair);
      }
      v_cRoom[x][y] = Val;
    }
  }
}

int ForX(std::vector<std::pair<int, int>> X)
{
  for (int i = 0; i < N; i++)
  {
    X[i].first;
  }
}

/*
while (!X.empty())
{
  std::cout << "(" << X.front().first << ", " << X.front().second << ")"
            << "\n";
  X.pop();
}
*/

/*
  for (auto i : v_cRoom)
  {
    for (auto j : i)
    {
      std::cout << j;
    }
    std::cout << "\n";
  }
  */