#include <iostream>
#include <queue>

int main()
{
  int baek, N, top = 10000;
  std::priority_queue<int> q1;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
  std::cin >> N;
  // std::vector<int>a;
  for (int i = 0; i < N; i++)
  {
    std::cin >> baek;
    if (q1.empty())
    {
      q1.push(baek);
    }
    else if (q1.size() < q2.size())
    {
      if (baek <= top)
      {
        q1.push(baek);
      }
      else if (baek > top)
      {
        q2.push(baek);
      }
      top = q2.top();
      q2.pop();
      q1.push(top);
    }
    else if (q1.size() > q2.size())
    {
      if (baek <= top)
      {
        top = q2.top();
        q2.pop();
        q1.push(top);
        q1.push(baek);
      }
      else if (baek > top)
      {
        q2.push(baek);
      }
    }
    else
    {
      if (baek <= top)
      {
        q1.push(baek);
      }
      else if (baek > top)
      {
        q2.push(baek);
      }
    }
    top = q1.top();
    std::cout << top << std::endl;
    // a.push_back(top);
  }
  /*    for(auto loop: a)
      {
          std::cout << loop << std::endl;

           else if(baek<=top)
          {
              q1.push(baek);
          }
          else if(baek > top)
          {
              q2.push(baek);
          }
      }*/
}