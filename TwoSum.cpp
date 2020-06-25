#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Brute force approch take O(n^2) time which is quiet expensive so we need to optimize the solution
*/
vector<int> bruteForce(vector<int> a,int n,int target){
	vector<int> ans;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]+a[j]==target){
				ans.push_back(i);
				ans.push_back(j);
				return ans;
			}
		}
	}
}
/*
Now we use unordered_map to optimize the solution to O(n) time unoredered_map uses O(1) time to access its elements
*/

vector<int> optimal(vector<int> a,int n,int target){
	vector<int> ans;
	unordered_map<int,int> ump;
	for(int i=0;i<n;i++){
		int comp=target-a[i];
		if(ump.find(comp)!=ump.end()){
			auto it=ump.find(comp);
			ans.push_back(it->second);
			ans.push_back(i);
			return ans;
		}
		ump.insert({a[i],i});
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,target,temp;
		cin>>n;
		vector<int> a;
		for(int i=0;i<n;i++){
			cin>>temp;
			a.push_back(temp);
		}
		cin>>target;
//		vector<int> ans=bruteForce(a,n,target);
//		cout<<"BruteForce Approch: ";
//		cout<<ans[0]<<" "<<ans[1]<<endl;
		cout<<"Optimal Approch: ";
		vector<int> ans2=optimal(a,n,target);
		cout<<ans2[0]<<" "<<ans2[1]<<endl;
	}
}
