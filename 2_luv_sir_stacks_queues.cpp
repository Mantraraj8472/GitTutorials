#include <bits/stdc++.h>
using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopr(i, n) for (int i = n - 1; i >= 0; i--)
#define ll long long
unordered_map<char, int> m = {{'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3}};

// This is modified for git by adding this comment

string isBalanced(string &s)
{
    stack<char> st;
    for (auto &var : s)
    {
        if (m[var] < 0)
            st.push(var);
        else if ((!st.empty()) && m[st.top()] + m[var] == 0)
        {
            st.pop();
        }
        else
            return "NO";
    }
    if (st.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    //                                       Stacks

    // Stack --> LIFO --> Last In First Out
    // We can access size and top element of stack
    // General operations are push(adding at top), pop(removing top), top(accessing top element)
    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    //                                             Queue

    // Queue --> FIFO --> First In First Out
    // We can access size and First element of Queue
    // General operations are push(adding at last), pop(removing first), top(accessing front element)
    // queue<string> q;
    // q.push("Mantraraj");
    // q.push("Gotecha");
    // q.push("How are you");
    // while (!q.empty())
    // {
    //     cout << q.front() << endl;
    //     q.pop();
    // }

    //                                Balanced paranthesis

    // Hackerank question https://www.hackerrank.com/challenges/balanced-brackets/problem

    // {}, (), []   -->   {([()])}
    // |_________|      Now checking for }, ), ] and last element of the stack should be matched.
    // |____(____|      And atlast stack should also be empty
    // |____[____|
    // |____{____|
    // |____{____|

    //I have declared the map globally for simplicity of the code as not to write the code repeatedly

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     string s;
    //     cin >> s;
    //     cout << (isBalanced(s)) << endl;
    // }

    //                                Next greater element

    // Without stack it takes O(n^2)
    // Let's take the array --> 4  5  2  25  7  8
    //  5 25 25  -1  8  -1
    // |_________|      |_________|      |_________|      |_________|
    // |_________|      |_________|      |_________|      |_________|
    // |_________|      |_________|      |_________|      |_________|
    // |_________|      |____2____|      |____7____|      |____8____|
    // |____4____|      |____5____|      |____25___|      |____25___|

    // And altast the elements which present in the stack has -1

    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    //     cin >> v[i];
    // stack<int> st;
    // // We can also make function
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (st.empty())
    //         st.push(i);
    //     else
    //     {
    //         if (v[st.top()] > v[i])
    //             st.push(i);
    //         else
    //         {
    //             while (!st.empty() && v[st.top()] <= v[i])
    //             {
    //                 v[st.top()] = v[i];
    //                 st.pop();
    //             }
    //             st.push(i);
    //         }
    //     }
    // }
    // while (!st.empty())
    // {
    //     v[st.top()] = -1;
    //     st.pop();
    // }
    // for (auto &var : v)
    //     cout << var << " ";
    // return 0;

    //                             Previous greater element
    // int n;
    // cin >> n;
    // int a[n];
    // loop(i, n) cin >> a[i];
    // int ans[n];
    // stack<int> st;
    // loopr(i, n)
    // {
    //     if (st.empty())
    //         st.push(i);
    //     else
    //     {
    //         while ((!st.empty()) && a[i] > a[st.top()])
    //         {
    //             ans[st.top()] = a[i];
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    // }
    // while ((!st.empty()))
    // {
    //     ans[st.top()] = -1;
    //     st.pop();
    // }
    // loop(i, n) cout << ans[i] << " ";

    //                                 Next smaller element

    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    //     cin >> v[i];
    // stack<int> st;
    // vector<int> ans(n);
    // loop(i, n)
    // {
    //     if (st.empty())
    //         st.push(i);
    //     else
    //     {
    //         while ((!st.empty()) && (v[i] < v[st.top()]))
    //         {
    //             ans[st.top()] = v[i];
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    // }
    // while (!st.empty())
    // {
    //     ans[st.top()] = -1;
    //     st.pop();
    // }
    // for (auto &value : v)
    //     cout << value << " ";
    // cout << endl;
    // for (auto &value : ans)
    //     cout << value << " ";

    //                               Previous smaller element

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans(n);
    loop(i, n) cin >> v[i];
    stack<int> st;
    loopr(i, n)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while ((!st.empty()) && v[i] < v[st.top()])
            {
                ans[st.top()] = v[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while ((!st.empty()))
    {
        ans[st.top()] = -1;
        st.pop();
    }
    for (auto value : v)
        cout << value << " ";
    cout << endl;
    for (auto value : ans)
        cout << value << " ";
}