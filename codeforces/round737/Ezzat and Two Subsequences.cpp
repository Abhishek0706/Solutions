#include <iostream>
#include <bits/stdc++.h>
#include <limits>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	    long long int a[n];
	    long long int sum=0;
	    for (int i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    for (int i=0;i<n-1;i++)
	    {
	        sum=sum+a[i];
	    }
	    double sum2=0;
	    sum2=(double)(sum/(double)(n-1));
	    sum2=(double)(sum2+a[n-1]);
	    std::cout << std::setprecision (10) << sum2 << std::endl;
	    //cout<<sum2<<endl;
	    
	}
	return 0;
}
