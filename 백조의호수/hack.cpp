// 3197
// 백조의 호수

#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction
{
  int y, x;
};

void input();
void check_ice();
bool check(Direction cur);

Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<char>> map;
std::queue<Direction> L_que, next_L_que, Ice_que, next_ice_que;
int R, C;
bool visited[1500][1500];

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int day = 1;

  input();
  check_ice();

  while (1)
  {
    while (!Ice_que.empty())
    {
      Direction cur = Ice_que.front();
      visited[cur.y][cur.x] = true;
      map[cur.y][cur.x] = '.';
      Ice_que.pop();

      for (int d = 0; d < 4; d++)
      {
        Direction next({cur.y + dir[d].y, cur.x + dir[d].x});

        if (next.y >= 0 && next.y < R && next.x >= 0 && next.x < C)
        {
          if (!visited[next.y][next.x] && map[next.y][next.x] == 'X')
          {
            next_ice_que.push(next);
            visited[next.y][next.x] = true;
          }
        }
      }
    }

    Ice_que.swap(next_ice_que);

    while (!L_que.empty())
    {
      Direction cur = L_que.front();
      map[cur.y][cur.x] = 'O';
      L_que.pop();

      for (int d = 0; d < 4; d++)
      {
        Direction next({cur.y + dir[d].y, cur.x + dir[d].x});

        if (next.y >= 0 && next.y < R && next.x >= 0 && next.x < C && map[next.y][next.x] != 'O')
        {
          if (map[next.y][next.x] == '.')
          {
            L_que.push(next);
            map[next.y][next.x] = 'O';
          }
          else if (map[next.y][next.x] == 'X')
          {
            next_L_que.push(next);
            map[next.y][next.x] = 'O';
          }

          else if (map[next.y][next.x] == 'L')
          {
            std::cout << day << '\n';
            return 0;
          }
        }
      }
    }
    L_que.swap(next_L_que);

    day++;
  }
}

void input()
{
  std::vector<char> map_x;
  std::string str;
  bool is_L = false;

  std::cin >> R >> C;

  for (int y = 0; y < R; y++)
  {
    std::cin >> str;
    for (int x = 0; x < C; x++)
    {
      map_x.push_back(str[x]);
      if (!is_L && str[x] == 'L')
      {
        is_L = true;
        L_que.push({y, x});
      }
    }
    map.push_back(map_x);
    map_x.clear();
    map_x.shrink_to_fit();
  }
}

void check_ice()
{
  for (int y = 0; y < R; y++)
  {
    for (int x = 0; x < C; x++)
    {
      if (map[y][x] == 'X')
      {
        if (check({y, x}))
        {
          Ice_que.push({y, x});
          visited[y][x] = true;
        }
      }
    }
  }
}

bool check(Direction cur)
{
  for (int d = 0; d < 4; d++)
  {
    Direction next({cur.y + dir[d].y, cur.x + dir[d].x});
    if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C)
      continue;
    if (map[next.y][next.x] == '.' || map[next.y][next.x] == 'L')
      return true;
  }

  return false;
}