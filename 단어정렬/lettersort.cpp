#include <iostream>
#include <algorithm>
#include <string>
#include <set>
struct Compare
{
    bool operator() (const std::string& s1, const std::string& s2) const 
    {
        if(s1.length()==s2.length())
            return s1 < s2;
        else
            return s1.length() < s2.length();
    }
};


int main()
{
    std::cin.tie(NULL);

    int N;
    std::string input;
    std::cin >> N;
    std::set<std::string, Compare> set;
    for(int i=0; i<N; i++)
    {
        std::cin >> input;
        set.insert(input);
    }
    std::string str;
    for(auto i:set)
        std::cout << i << "\n";
}

std::set<