//Fractional Knapsack Problem
/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Item {
	int profit, weight;

	Item(int profit, int weight){
		this->profit = profit;
		this->weight = weight;
	}
};

static bool cmp(struct Item a, struct Item b){
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N){
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}

int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << fractionalKnapsack(W, arr, N);
	return 0;
}



//Activity Selection

struct Activity {
    int start, finish;
};
 
bool activityCompare(Activity s1, Activity s2){
    return (s1.finish < s2.finish);
}
 
void printMaxActivities(Activity arr[], int n){
    sort(arr, arr + n, activityCompare);

    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish<< ")";
 
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << ", (" << arr[j].start << ", "<< arr[j].finish << ")";
            i = j;
        }
    }
}

int main(){
    Activity arr[] = { { 5, 9 }, { 1, 2 }, { 3, 4 },
                        { 0, 6 }, { 5, 7 }, { 8, 9 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}
*/


//Job  scheduling
/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job{
	int no;
	int deadline;
	int profit;
};

bool cmp(Job a, Job b){
	return(a.profit > b.profit);
}

int jobSchedule(Job arr[], int n){
	sort(arr, arr+n, cmp);
	int slot[n];

	for(int i=0;i<n;i++){
		slot[i]=0;
	}

	int p=0;
	for(int i=0;i<n;i++){
		for(int j=arr[i].deadline;j>=0;j--){
			if(slot[j]==0){
				continue;
				slot[j]=arr[i].no;
				p=p+arr[i].profit;
			}
		}
	}

	return p;
}

int main(){
    Job arr[] = { { 1, 2, 100 },
                  { 2, 1, 19 },
                  { 3, 2, 27 },
                  { 4, 1, 25 },
                  { 5, 3, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<jobSchedule(arr, n);
    return 0;
}
*/


//Huffmann coding


#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq){
		left=right=NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare{
	bool operator()(MinHeapNode* l, MinHeapNode* r){
		return(l->freq, r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str){
	if(!root)
		return;

	if(root->data != '$'){
		cout<<root->data<<":"<<str<<endl;
	}

	printCodes(root->left, str+"0");
	printCodes(root->right, str+"1");
}

void HuffmanCodes(char data[], int freq[], int size){
	struct MinHeapNode *left, *right, *top;

	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare>

	minHeap;

	for(int i=0;i<size;++i){
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}

	while(minHeap.size() != 1){
		left=minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};

	int size = sizeof(arr)/sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}



