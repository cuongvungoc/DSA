#include <bits/stdc++.h>

using namespace std;

int main()

{
    stack<char> st;
    stack<int> c;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]) == 0)
        {
            if (s[i] == '/')
            {
                st.push(s[i]);

                c.push(i);
            }
            else
            {
                reverse(s.begin() + c.top(), s.begin() + i + 1);
                c.pop();
                st.pop();
            }
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
            cout << s[i];
    }

    return 0;
}