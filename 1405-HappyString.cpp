#include <iostream>
#include <queue>
using namespace std;

string happyString(int a, int b, int c)
{
    priority_queue<pair<int,char>>pq;

    if (a > 0)
        pq.push({a, 'a'});
    if (b > 0)
        pq.push({b, 'b'});
    if (c > 0)
        pq.push({c, 'c'});

    string ans = "";

    while (!pq.empty())
    {
        pair<int, char> top = pq.top();
        pq.pop();
        int cnt = top.first, size = ans.size();
        char c = top.second;

        if (size >= 2 && ans[size - 1] == c && ans[size - 2] == c)
        {
            if (pq.empty())
                return ans;

            pair<int, char> temp = pq.top();
            pq.pop();
            ans += temp.second;
            if (temp.first - 1 > 0)
                pq.push({temp.first - 1, temp.second});
        }
        else
        {
            ans += c;
            cnt--;
        }
        if (cnt)
            pq.push({cnt, c});
    }
    return ans;
}

int main()
{
    int a = 1, b = 1, c = 7;
    cout << happyString(a, b, c) << endl;
}
