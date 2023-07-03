#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
// {32,43,5,23,53,5}; op: {5,5,23,32,43,53}
using namespace std;
vector<int> countSort(vector<int> &v){
	unordered_map<int,int> m;
	unordered_map<int,vector<int>> indexCont;
	vector<int>vs;
	int max = *max_element(v.begin(),v.end());
	int min = *min_element(v.begin(),v.end());
	/* Stores index of elements of the vector in hashmap (indexCont) */
	for(int i=0;i<v.size();i++){
			indexCont[v[i]].push_back(i);
	}
//	/* Prints elements of indexCont */
//	for(auto x:indexCont){
//		cout<<x.first<<":";
//		for(auto y:x.second){
//			cout<<y<<" ";
//		}
//	}
	/* Stores count of elements of the vector in hashmap (m) */
	for(auto x:v){
		if(m.find(x)!=m.end()){
			m[x] = m[x]+1;
		}
		else
			m[x] = 1;
	}
	int j=0;
	v.clear(); // original vector i scleared to stores sorted elements
	/* Inserts elements in the vector (v) */
	for(int i=min;i<=max;i++){
		if(m.find(i)!=m.end()){
			for(int k = 0;k<m[i];k++){
				v.push_back(i);
			}
		}
	}
	/* Getting the sorted index and storing it into a vector */
	for(int i=0;i<v.size();i++){
		if(i>0 and v[i]!=v[i-1]){
			for(auto y:indexCont[v[i]]){
				vs.push_back(y);
			}
		}else{
			if(i==0){
				for(auto y:indexCont[v[i]]){
					vs.push_back(y);
				}
			}
		}
	}
	return vs;
}
int main(){
	vector<int> v = {32,43,5,23,53,5};
	vector<int> sortedIndex;
	sortedIndex = countSort(v);
	/* For printing the sorted array */
	cout<<"Sorted Array: ";
	for(auto x:v){
		cout<<x<<" ";
	}
	/* For printing the sorted index */
	cout<<"\nSorted Index: ";
	for(auto x:sortedIndex){
		cout<<x<<" ";
	}
	return 0;
}