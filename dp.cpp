//LCS
/*
#include<iostream>
#include<string>
using namespace std;

int lcs(int l1, int l2, string s1, string s2){
	int m = l1+1;
	int n = l2+1;
	int matrix[m][n];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=0;
		}
	}

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(s1[i-1]==s2[j-1]){
				matrix[i][j]=matrix[i-1][j-1]+1;
			}
			else{
				matrix[i][j]=max(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	return matrix[m-1][n-1];
}

int main(){
	string s1 = "stone";
	string s2="longest";
	int l1 = s1.length();
	int l2 = s2.length();
	cout<<lcs(l1,l2,s1,s2);
}
*/

//Knapsack 0/1
/*
#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { 
	return (a > b) ? a : b; 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	vector<vector<int> > K(n + 1, vector<int>(W + 1)); 

	for (i = 0; i <= n; i++) { 
		for (w = 0; w <= W; w++) { 
			if (i == 0 || w == 0) 
				K[i][w] = 0; 
			else if (wt[i - 1] <= w) 
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
			else
				K[i][w] = K[i - 1][w]; 
		} 
	} 
	return K[n][W]; 
} 

int main(){
	int profit[]={60,100,120};
	int weight[]={10,20,30};
	int W = 50;
	int n=sizeof(profit)/sizeof(profit[0]);
	cout<<knapSack(W, weight, profit, n);
}
*/

/*

#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[], int n){

    int m[n][n];
    int q;
    
    for(int i=0;i<n;i++){
        m[i][i] = 0;
    }

    for(int l=2;l<n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=0;
            for(int k=i;k<=j-1;k++)
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n-1];

}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<mcm(arr, n);
}

*/

//Coin change problem
/*
#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int n, int sum){
	int rows=n+1;
	int cols=sum+1;
	int arr[rows][cols];

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			arr[i][j] = 0;
		}
	}
	arr[0][0] = 1;

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(coins[i]>j){
				arr[i][j] = arr[i-1][j];
			}
			else{
				arr[i][j] = arr[i-1][j]+arr[i][j-coins[i]];
			}
		}
	}

	return arr[rows][cols];
}

int main(){
	int coins[] = {1,2,3};
	int n=3;
	int sum=5;
	cout<<coinChange(coins, n, sum);
	return 0;
}
*/



