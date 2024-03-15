#include <queue>
#include <stdio.h>

int main()
{
  int baek, N, top = 10000;
  std::priority_queue<int> q1;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
  scanf("%d", &N);
  // std::vector<int>a;
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &baek);

    if (q1.empty())
    {
      q1.push(baek);
    }

    else if (baek <= top)
    {
      if (q1.size() > q2.size())
      {
        q2.push(q1.top());
        q1.pop();
      }
      q1.push(baek);
    }

    else
    {
      if (q1.size() == q2.size())
      {
        if (baek <= q2.top())
        {
          q1.push(baek);
        }
        else
        {
          q1.push(q2.top());
          q2.pop();
          q2.push(baek);
        }
      }
      else
      {
        q2.push(baek);
      }
    }
    top = q1.top();
    printf("%d\n", top);
  }
  return 0;
}