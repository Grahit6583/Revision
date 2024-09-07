#include<bits/stdc++.h>

using namespace std;
//print all subsequences
void show(int i, int arr[], vector<int> &sh, int n)
{
    if(i==n)
    {
        for(int j=0; j<sh.size(); j++)
        {
            cout<<sh[j]<<" ";
        }
        if(sh.size() == 0)
        {
            cout<<"{}";
        }
        cout<<endl;
        return;
    }

    sh.push_back(arr[i]);
    show(i+1,arr,sh,n);
    sh.pop_back();
    show(i+1,arr,sh,n);
}

//print subsequence equal to target sum;
void show_1(int i, int arr[], vector<int> &sh, int n, int s, int sum)
{
    if(i==n)
    {
        if(s == sum)
        {
            for(auto it:sh)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }

    sh.push_back(arr[i]);
    s += arr[i];
    show_1(i+1,arr,sh,n,s,sum);
    sh.pop_back();
    s -= arr[i];
    show_1(i+1,arr,sh,n,s,sum);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int arr[] = {1,1,2};
    int n=3;
    vector<int> sh;
    // show(0,arr,sh,n);
    show_1(0,arr,sh,n,0,2);
    return 0;
}