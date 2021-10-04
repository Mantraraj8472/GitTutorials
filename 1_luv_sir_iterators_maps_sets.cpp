#include <bits/stdc++.h>
using namespace std;

void print_vec(vector<int> &v) //Always pass by reference to reduce the time complexity
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void print_map(unordered_map<int, string> &m)
{
    for (auto &pr : m)
        cout << pr.first << " " << pr.second << endl; //Accessing the elements also have o(log(n))
}

void print_set(set<string> &s)
{
    for (auto &value : s)
        cout << value << endl;
    // for (auto it = s.begin(); it != s.end(); it++)
    //     cout << (*it) << endl;
}

int main()
{

    //                              Iterators and range loops

    // vector<int> v;
    // v = {1, 2, 3, 4, 5};
    // print_vec(v);
    // vector<int>::iterator it = v.begin();
    // for (it; it != v.end(); it++)  //Not it+1 as in case of vector it will work as it is contiguous in memory but not work in maps and sets...
    //     cout << (*it) << " ";
    // cout << endl;

    // vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};
    // vector<pair<int, int>>::iterator it_p;
    // for (it_p = v_p.begin(); it_p != v_p.end(); it_p++)
    //     cout << (*it_p).first << " " << (*it_p).second << endl;
    // for (auto it_p = v_p.begin(); it_p != v_p.end(); it_p++)
    //     cout << it_p->first << " " << it_p->second << endl;

    // for (pair<int, int> value : v_p)
    //     value.first++;
    // for (auto &value : v_p)
    //     value.first++;
    // for (auto value : v_p)
    //     cout << value.first << " " << value.second << endl;

    //                                     Maps

    // map<key, value> m;
    // map<int, string> m;
    // m[1] = "man"; //O(log(n)) -- inserting as well as accessing that is cout the values
    // m[5] = "tra"; // Also depending upon the key as if string then comparison takes more time
    // m[3] = "raj"; // it takes s.size * O(log(n))
    // m[6];                 //O(log(n)) -- declaring

    // m.insert({4, "got"}); //m.insert(make_pair(4,"got"));
    // print_map(m);
    // m[3] = "raja"; //Overwritten --> means only unique keys
    // print_map(m);
    // map<int, string>::iterator it;
    // for (it = m.begin(); it != m.end(); it++)
    //     cout << it->first << " " << it->second << endl;
    // for (auto &value : m)
    //     cout << value.first << " " << value.second << endl;

    // auto it = m.find(3); //O(log(n))
    // if (it == m.end())
    // cout << "No key found\n";
    // else
    //     cout << it->first << " " << it->second << endl;
    // m.erase(3);   //O(log(n)) Here it takes argument also as iterator
    // print_map(m);

    // auto it = m.find(3); //Here it=m.end() then m.erase will give an error
    // if (it != m.end())
    //     m.erase(it);
    // print_map(m);

    // m.clear();  //clear whole map
    // print_map(m);

    // Difference between maps and unordered _maps
    // 1. Inbuilt implementation
    // 2. Time complexity
    // 3. Valid keys datatype

    // unordered_map<int, string> m;
    // m[1] = "man"; //O(1) both have O(1)
    // m[3]="tra";
    // m[6];
    // print_map(m);
    // m.find and m.erase all have O(1) time complexity
    // In case of multimaps we can insert duplicate keys also possible generally we don't use multimaps
    // Instead we use map<int, vector<string> > m; --> for storing multi values corresponding to one key value

    // Question:
    // Given N strings, print unique strings in lexigrophical order with their frequecency.
    // N <= 10^5
    // |S| <= 100

    // int n;
    // cin >> n;
    // map<string, int> m;   //used map as we have to print in lexigrophically order otherwise we use unordered_map
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     m[s]++;
    // }
    // for (auto &var : m)
    // {
    //     cout << var.second << " ";
    //     cout << var.first << endl;
    // }

    //                                         SETS

    // If we remove values from map then it is similar set
    // set<string> s;   //Store in sorted order and uniquely
    // s.insert("ghj"); // all have O(log(n))
    // s.insert("abc");
    // auto it = s.find("abc");
    // print_set(s);
    // if (it != s.end())
    //     s.erase(it);
    // s.erase("ghj");
    // print_set(s);

    // unordered_set<int> --> similar as unordered_map after removing values and has O(1)

    // Question:
    // Given N strings and Q queries, in each query you are given a string.
    // Print yes if string is present else print no.
    // unordered_set<string> set;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     string s;
    //     cin >> s;
    //     set.insert(s);
    // }
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     string str;
    //     cin >> str;
    //     if (set.find(str) == set.end())
    //         cout << "no\n";
    //     else
    //         cout << "yes\n";
    // }

    // Multisets --> similar as multimaps. Here duplicates are allowed  --> O(log(n ))
    // In multisets if I use s.erase(iterator) then first value will be deleted but
    // in case of s.erase(value) then all occurences will be deleted.
    // Also can solve questions in description of video 36 of playlist

    //                           Nesting in STL maps and sets

    // map<pair<int, int>, int> m;
    // pair<int, int> p1, p2;
    // p1 = {1, 2};
    // p2 = {2, 3};
    // cout << (p1 < p2);    //First compare first value and then second same in map nesting insertion
    // map<set<int>, int> m;    //Similarly compare all the elements of set in same order
    // set<int> s = {1,2,3};
    // set<int> p = {1,2};
    // cout<<(s<p);

    // Example  
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     map<pair<string, string>, vector<int>> m; //marks corresponds to first name and last name
    //     string fn, ln;
    //     cin >> fn >> ln;
    //     int ct;
    //     cin >> ct;
    //     for (int j = 0; j < ct; j++)
    //     {
    //         int var;
    //         cin >> var;
    //         m[{fn, ln}].push_back(var); //Now as m[{fn,ln}] is a vector
    //     }
    //     for (auto &val : m)
    //     {
    //         cout << (val.first.first) << " " << val.first.second << endl;
    //         cout << (val.second.size()) << endl;
    //         for (auto &val_vector : val.second)
    //             cout << val_vector << " ";
    //         cout << endl;
    //     }
    // }
    // Please see this question
    // Question link: https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE
    return 0;
}