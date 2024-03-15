#include <cmath>
#include <iosfwd>
#include <iostream>
#include <stack>
#include <string>

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);

  int intInputNum;
  std::cin >> intInputNum;

  std::stack<int> stack_iClassPoint;
  std::stack<std::string> stack_strGrade;

  int iClassPoint;
  int iSum_ClassPoint = 0;
  double dbGrade;
  double dbSum_Grades = 0;
  std::string strGrade;

  for (int i = 0; i < intInputNum; i++)
  {
    std::cin.ignore(100, ' ');
    std::cin >> iClassPoint;
    stack_iClassPoint.push(iClassPoint);
    std::cin.ignore();
    std::cin >> strGrade;
    stack_strGrade.push(strGrade);
  }

  while (!stack_iClassPoint.empty() || !stack_strGrade.empty())
  {
    iClassPoint = stack_iClassPoint.top();
    stack_iClassPoint.pop();
    strGrade = stack_strGrade.top();
    stack_strGrade.pop();
    switch (strGrade.front())
    {
    case 'A':
      dbGrade = 4.0;
      break;
    case 'B':
      dbGrade = 3.0;
      break;
    case 'C':
      dbGrade = 2.0;
      break;
    case 'D':
      dbGrade = 1.0;
      break;
    case 'F':
      dbGrade = 0.0;
      break;
    default:
      dbGrade = 0.0;
      break;
    }

    if (dbGrade >= 1.0)
    {
      switch (strGrade.back())
      {
      case '+':
        dbGrade += 0.3;
        break;
      case '-':
        dbGrade -= 0.3;
        break;
      default:
        break;
      }
    }
    iSum_ClassPoint += iClassPoint;
    dbSum_Grades += (iClassPoint * dbGrade);
  }
  double ans = (dbSum_Grades / iSum_ClassPoint);
  std::cout << std::fixed;
  std::cout.precision(2);
  std::cout << std::round((ans * 100)) / 100;
}