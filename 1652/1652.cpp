#include <iosfwd>
#include <iostream>
#include <queue>
#include <vector>

int ForX(std::vector<std::vector<char>> v_cRoom);
int ForY(std::vector<std::vector<char>> v_cRoom);

int N;

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  char Val;
  std::vector<std::vector<char>> v_cRoom;
  std::vector<char> v_cSub;

  std::cin >> N;
  v_cSub.assign(N, -1);
  for (int i = 0; i < N; i++)
  {
    v_cRoom.push_back(v_cSub);
  }

  for (int y = 0; y < N; y++)
  {
    for (int x = 0; x < N; x++)
    {
      std::cin >> Val;
      v_cRoom[x][y] = Val;
    }
  }

  for (auto i : v_cRoom)
  {
    for (auto j : i)
    {
      std::cout << j;
    }
    std::cout << "\n";
  }

  std::cout << ForX(v_cRoom) << " " << ForY(v_cRoom);
}

int ForX(std::vector<std::vector<char>> v_cRoom)
{
  int i_NumofEmpty = -1; // 각 케이스별 빈 공간 개수
  int i_NumofBed = 0;
  for (int y = 0; y < N; y++)
  {
    // 각 행의 왼쪽 끝에서 빈 공간 0으로 초기화
    i_NumofEmpty = 0;
    for (int x = 0; x < N; x++)
    {
      /*
      X를 만났을 때, 해당 X를 만나기 전까지 지나온 빈 칸의 개수가 2개
      이상이면 누울 수 있는 자리 증가
      */
      if (v_cRoom[x][y] == 'X')
      {
        if (i_NumofEmpty >= 2)
        {
          i_NumofBed++;
        }
        // X를 만나면 무조건 빈 공간의 개수는 0으로 초기화
        i_NumofEmpty = 0;
      }
      else
      {
        i_NumofEmpty++;
      }
    }
    /*
    각 행의 마지막에 도달했을 때,
    현재 빈 공간의 개수가 2개 이상일 경우 누울 수 있는 자리 증가
    */
    if (i_NumofEmpty >= 2)
    {
      i_NumofBed++;
    }
  }
  return i_NumofBed;
}

int ForY(std::vector<std::vector<char>> v_cRoom)
{
  int i_NumofEmpty = -1; // 각 케이스별 빈 공간 개수
  int i_NumofBed = 0;
  for (int x = 0; x < N; x++)
  {
    // 각 열의 왼쪽 끝에서 빈 공간 0으로 초기화
    i_NumofEmpty = 0;
    for (int y = 0; y < N; y++)
    {
      /*
      X를 만났을 때, 해당 X를 만나기 전까지 지나온 빈 칸의 개수가 2개
      이상이면 누울 수 있는 자리 증가
      */
      if (v_cRoom[x][y] == 'X')
      {
        if (i_NumofEmpty >= 2)
        {
          i_NumofBed++;
        }
        // X를 만나면 무조건 빈 공간의 개수는 0으로 초기화
        i_NumofEmpty = 0;
      }
      else
      {
        i_NumofEmpty++;
      }
    }
    /*
    각 열의 마지막에 도달했을 때,
    현재 빈 공간의 개수가 2개 이상일 경우 누울 수 있는 자리 증가
    */
    if (i_NumofEmpty >= 2)
    {
      i_NumofBed++;
    }
  }
  return i_NumofBed;
}