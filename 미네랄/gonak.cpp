// 미네랄
// 2933

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Direction
{
  int y, x;
};
int R, C, count;

Direction dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
std::vector<std::vector<char>> map;

// 입력
void input();
// 막대기 던지기
void throw_bar(int idx, int height);
// 클러스터들이 땅에 붙어있는지 아닌지 확인
std::vector<std::vector<bool>> check_cluster();
// 떨어지는 클러스터 확인
void check_fall_cluster(std::queue<Direction> &fall_cluster_que, const std::vector<std::vector<bool>> &visited);
// 떨어지는 높이 측정
int check_fall_count(std::queue<Direction> &fall_cluster_que, const std::vector<std::vector<bool>> &visited);
// 클러스터 떨어트리기
void change(int check_count, const std::vector<std::vector<bool>> &visited);
// 출력
void print();
bool Movable(int y, int x);

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int height;
  input();

  for (int idx = 0; idx < count; idx++)
  {
    std::queue<Direction> fall_cluster_que;

    throw_bar(idx, height);
    std::vector<std::vector<bool>> visited = check_cluster();
    check_fall_cluster(fall_cluster_que, visited);
    int check_count = check_fall_count(fall_cluster_que, visited);
    change(check_count, visited);
  }

  print();
  return 0;
}

void input()
{
  std::vector<char> map_x;
  std::string str;

  std::cin >> R >> C;

  for (int y = 0; y < R; y++)
  {
    std::cin >> str;
    for (int x = 0; x < C; x++)
      map_x.push_back(str[x]);
    map.push_back(map_x);

    map_x.clear();
    map_x.shrink_to_fit();
  }

  std::cin >> count;
}

void throw_bar(int idx, int height)
{
  std::cin >> height;
  height = R - height;

  if (idx % 2 == 0) // left
  {
    for (int bar_x = 0; bar_x < C; bar_x++)
      if (map[height][bar_x] == 'x')
      {
        map[height][bar_x] = '.';
        break;
      }
  }

  else // right
  {
    for (int bar_x = C - 1; bar_x >= 0; bar_x--)
    {
      if (map[height][bar_x] == 'x')
      {
        map[height][bar_x] = '.';
        break;
      }
    }
  }
}

std::vector<std::vector<bool>> check_cluster()
{
  std::vector<std::vector<bool>> visited(R, std::vector<bool>(C, false));
  std::queue<Direction> que;

  for (int x = 0; x < C; x++)
  {
    if (map[R - 1][x] == 'x')
    {
      que.push({R - 1, x});
      visited[R - 1][x] = true;
    }
  }

  while (!que.empty())
  {
    Direction cur = que.front();
    visited[cur.y][cur.x] = true;
    que.pop();

    for (int d = 0; d < 4; d++)
    {
      Direction next({cur.y + dir[d].y, cur.x + dir[d].x});
      if (Movable(next.y, next.x) && !visited[next.y][next.x])
      {
        if (map[next.y][next.x] == 'x')
        {
          que.push(next);
          visited[next.y][next.x] = true;
        }
      }
    }
  }

  return visited;
}

void check_fall_cluster(std::queue<Direction> &fall_cluster_que, const std::vector<std::vector<bool>> &visited)
{
  for (int y = 0; y < R; y++)
  {
    for (int x = 0; x < C; x++)
    {
      if (!visited[y][x] && map[y][x] == 'x')
        fall_cluster_que.push({y, x});
    }
  }
}

int check_fall_count(std::queue<Direction> &fall_cluster_que, const std::vector<std::vector<bool>> &visited)
{
  int check_count = R;

  while (!fall_cluster_que.empty())
  {
    Direction check_cur = fall_cluster_que.front();
    int check_tmp = 0;
    fall_cluster_que.pop();

    Direction check_next = {check_cur.y + 1, check_cur.x};
    while (check_next.y < R)
    {
      if (map[check_next.y][check_next.x] == '.')
        check_tmp++;
      else if (map[check_next.y][check_next.x] == 'x' && visited[check_next.y][check_next.x])
        break;

      check_next.y += 1;
    }

    if (check_count > check_tmp)
      check_count = check_tmp;
  }
  return check_count;
}

void change(int check_count, const std::vector<std::vector<bool>> &visited)
{
  for (int x = 0; x < C; x++)
  {
    for (int y = R - 1; y >= 0; y--)
    {
      if (map[y][x] == 'x' && !visited[y][x])
      {
        map[y + check_count][x] = map[y][x];
        map[y][x] = '.';
      }
    }
  }
}

void print()
{
  for (int y = 0; y < R; y++)
  {
    for (int x = 0; x < C; x++)
    {
      std::cout << map[y][x];
    }
    std::cout << '\n';
  }
}

bool Movable(int y, int x)
{
  if (y < 0 || y >= R || x < 0 || x >= C)
    return false;
  return true;
}
