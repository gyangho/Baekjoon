#include <iosfwd>
#include <iostream>
#include <stack>
#include <vector>

int DFS();

int iN;
int iM;
std::vector<int> v_iNodes;
std::vector<std::vector<int>> v_vLines;

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int iu;
  int iv;

  std::cin >> iN;
  std::cin >> iM;

  v_vLines.assign(iN + 1, v_iNodes);

  for (int i = 0; i < iM; i++)
  {
    std::cin >> iu;
    std::cin >> iv;

    v_vLines[iu].push_back(iv);
    v_vLines[iv].push_back(iu);
  }

  std::cout << DFS();

  return 0;
}

int DFS()
{
  int iCurrentVectorPosition = 1; // 현재 탐색중인 노드의 벡터 인덱스
  int iCurrentNode = -1;          // 벡터의 값을 통해 도착할 노드.
  int iConnection = 0;            // 연결의 수
  std::vector<int> v_iVisited;
  std::stack<int> s_iConnection;

  v_iVisited.assign(iN + 1, 0);
  while (1)
  {
    if (!v_vLines[iCurrentVectorPosition].empty())
    {
      if (iCurrentNode == -1)
        s_iConnection.push(iCurrentVectorPosition);
      // std::cout << "stack.push(): " << iCurrentVectorPosition << "\n";
      iCurrentNode = v_vLines[iCurrentVectorPosition].back();
      // std::cout << "MOVE : " << iCurrentVectorPosition << "-->" << iCurrentNode << "\n";
      v_vLines[iCurrentVectorPosition].pop_back();
      iCurrentVectorPosition = iCurrentNode;
      s_iConnection.push(iCurrentVectorPosition);
    }
    else
    {
      if (iCurrentNode != -1) // 하나의 연결을 탐색하는 중이다.
      {
        v_iVisited[s_iConnection.top()] = 1;
        s_iConnection.pop();

        if (!s_iConnection.empty())
        {
          iCurrentVectorPosition = s_iConnection.top();
          // std::cout << "stack.pop(): " << iCurrentVectorPosition << "\n";
        }
        else // 스택이 비어서 더 이상 연결 된 노드가 없음.
        {
          iConnection++;
          // std::cout << "Connection++\n";
          iCurrentVectorPosition = 1;
          iCurrentNode = -1;
        }
      }
      else // 시작된 연결이 아직 없음.
      {
        iCurrentVectorPosition++;
        if (iCurrentVectorPosition >= iN)
        {
          break;
        }
      }
    }
  }
  for (int i = 1; i <= iN; i++)
  {
    if (v_iVisited[i] == 0)
      iConnection++;
  }

  return iConnection;
}