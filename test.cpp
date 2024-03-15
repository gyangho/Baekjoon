#include <iostream>

int main()
{
  std::cin.tie(NULL);
  std::ios::sync_with_stdio(false);
  int N;
  char temp[100];

  std::cin >> N;
  std::cin.ignore();
  std::cin.getline(temp, 100, '\n');
  std::cout << temp[0];
}