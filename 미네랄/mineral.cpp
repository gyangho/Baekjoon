
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

struct XY
{
  int x;
  int y;
};

int R, C, N;
XY dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 좌 우 상 하
std::vector<int> h;

bool check_Range(XY loc)
{
  if (loc.x < 0 || loc.x >= C || loc.y < 0 || loc.y >= R)
    return false;
  else
    return true;
}

void clear(std::queue<XY> &q)
{
  std::queue<XY> empty;
  std::swap(q, empty);
}

void throw_stick(std::vector<std::vector<char>> &cave)
{
}

std::queue<XY> find_Cluster(std::vector<std::vector<char>> cave, XY crushed)
{
  std::vector<std::vector<bool>> visited;
  std::vector<bool> t;
  std::queue<XY> que;
  std::queue<XY> minerals;
  XY cur;

  visited.reserve(R);
  t.resize(C, false);

  for (int i = 0; i < R; i++)
  {
    visited.push_back(t);
  }
  visited[crushed.y][crushed.x] = true;
  //======================================================

  // 파괴된 미네랄과 연결된 미네랄 찾기
  for (int d = 0; d < 4; d++)
  {
    cur = crushed;
    cur.x = cur.x + dir[d].x;
    cur.y = cur.y + dir[d].y;
    if (check_Range(cur) && visited[cur.y][cur.x] == false && cave[cur.y][cur.x] == 'x')
    {
      if (cur.y == R - 1) // 바로 바닥에 연결되어 있을 경우
        continue;
      que.push(cur);
      minerals.push(cur);
      visited[cur.y][cur.x] = true;
    }
    else
    {
      visited[cur.y][cur.x] = true;
      continue;
    }
    // 파괴된 지점과 연결되어있던 미네랄들이 바닥과 연결되어있는 지 확인
    while (!que.empty())
    {
      cur = que.front();
      que.pop();
      for (int d = 0; d < 4; d++)
      {
        XY temp;
        temp.x = cur.x + dir[d].x;
        temp.y = cur.y + dir[d].y;
        if (check_Range(temp) && visited[temp.y][temp.x] == false && cave[temp.y][temp.x] == 'x')
        {
          visited[temp.y][temp.x] == true;
          if (temp.y == R - 1)
          {
            clear(que);
            clear(minerals);
            break;
          }
          que.push(temp);
          minerals.push(temp);
        }
      }
    }
    if (!minerals.empty()) // 바닥과 연결되지 않은 클러스터 발견
      break;
  }
  return minerals;
}

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  std::vector<std::vector<char>> cave; // 동굴 벡터 선언

  char temp[200] = {0};
  std::vector<char> t; // 임시 변수 선언

  std::cin >> R >> C; // R, C 입력받기

  cave.reserve(R); // 동굴 크기(행) 할당
  t.reserve(C);    // 동굴 크기(열) 할당

  for (int i = 0; i < R; i++) // 동굴 입력받기
  {
    std::cin >> temp;
    for (int j = 0; j < C; j++)
    {
      t.push_back(temp[j]);
    }
    cave.push_back(t);
    t.clear();
  }
  t.reserve(0); // 임시 벡터 해제

  std::cin >> N;
  h.reserve(N); // 높이 순서 크기 할당

  std::cin.ignore(); // 입력버퍼 비우기

  std::cin.getline(temp, 200, '\n'); // 공백 포함 입력

  h.push_back(R - atoi(strtok(temp, " "))); // 문자열 정수형으로 변환하여 벡터에 입력
  for (int i = 1; i < N; i++)
  {
    h.push_back(R - atoi(strtok(NULL, " ")));
  }
  //^^^^^^^^^^^^^^^^^^^^^^^입력부분^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  for (int i = 0; i < N; i++)
  {
    std::cout << h[i];
  }
}