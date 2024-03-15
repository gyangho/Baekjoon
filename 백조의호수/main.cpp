#include <queue>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

void printMap(std::vector<std::vector<char>> v, int R, int C);

struct Location
{
  int x;
  int y;
};

int main()
{
  int R = 0;
  int C = 0;
  std::string str;
  Location lLoc;
  scanf("%d %d", &R, &C);
  printf("R: %d\nC: %d\n", R, C);

  std::vector<std::vector<char>> v(R);
  std::vector<char> vchar(C);

  for (int i = 0; i < R; i++)
  {
    printf("INFOR2\n");
    scanf("%s", str);
    getchar();
    for (int j = 0; j < C; j++)
    {
      printf("INFOR2\n");
      vchar[j] = str[j];
      if (str[j] == 'L')
      {
        lLoc.x = j;
        lLoc.y = i;
      }
    }
    v.push_back(vchar);
  }
  printMap(v, R, C);
}

void printMap(std::vector<std::vector<char>> v, int R, int C)
{
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      printf("%c", v[i][j]);
    }
    printf("\n");
  }
}