#include<bits/stdc++.h>

using namespace std;

int fun(int i, int arr[], int n, int s, int sum)
{
    if(i==n)
    {
        if(s == sum) return 1;
        else return 0;
    }

    s += arr[i];
    int l = fun(i+1, arr, n, s, sum);

    s -= arr[i];
    int r = fun(i+1, arr, n, s, sum);

    return l+r;
}

bool func1(int i, int arr[], vector<int> &vec, int n, int s, int sum)
{
    if(i == n)
    {
        if(s == sum)
        {
            for(auto it : vec)
            {
                cout<<it<<" ";
            }
            return true;
        }
        else 
            return false;
    }

    vec.push_back(arr[i]);
    s += arr[i];
    if(func1(i+1, arr, vec, n, s, sum) == true)
    {
        return true;
    }

    vec.pop_back();
    s -= arr[i];
    if(func1(i+1,arr,vec,n, s, sum) == true)
    {
        return true;
    }

    return false;
}

int func2(string str, vector<string> output)
{
    if(str.length() == 0)
    {
        output[0] = "";
        return 1;
    }

    int size = func2(str.substr(1), output);
    for(int i=0; i<size; i++)
    {
        output[i+size] = str[0] + output[i];
    }

    return 2*size;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int arr[] = {1,1,2};
    vector<int> vec;
    // cout<<func1(0, arr, vec, n, 0, 2);

    vector<string> ans(100);
    int n = func2("abcde",ans);
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;    
}