/* Optimal solution than its python solution
Strategy: First sorted both lists then compared each element of both the lists one by one using two pointer method
when elements of both element gets equal no insertion and when inserting list is greater then checked next element
of comparing list when it is smaller than that of comparing list then insertion happens.
 */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v;
        vector<int> k;
        int i=0,j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(i=0;i<nums1.size();i++){
            if(j!=nums2.size()){
                if(nums1[i]==nums2[j]){
                    continue;
                }else{
                    if(nums1[i]>nums2[j]){
                        j++;i--;continue;
                    }else{
                        if(k.size()!=0){
                            if(k[k.size()-1]!=nums1[i]){
                                k.push_back(nums1[i]);
                            }
                        }else{
                            k.push_back(nums1[i]);
                        }
                    }
                }
            }else{
                if(k.size()!=0){
                    if(k[k.size()-1]!=nums1[i]){
                        k.push_back(nums1[i]);
                    }
                }else{
                    k.push_back(nums1[i]);
                }
            }
        }
        v.push_back(k);
        k.clear();
        j=0;
        for(i=0;i<nums2.size();i++){
            if(j!=nums1.size()){
                if(nums2[i]==nums1[j]){
                    continue;
                }else{
                    if(nums2[i]>nums1[j]){
                        j++;i--;continue;
                    }else{
                        if(k.size()!=0){
                            if(k[k.size()-1]!=nums2[i]){
                                k.push_back(nums2[i]);
                            }
                        }else{
                            k.push_back(nums2[i]);
                        }
                    }
                }
            }else{
                if(k.size()!=0){
                    if(k[k.size()-1]!=nums2[i]){
                        k.push_back(nums2[i]);
                    }
                }else{
                    k.push_back(nums2[i]);
                }
            }
        }
        v.push_back(k);
        return v;
    }
};
