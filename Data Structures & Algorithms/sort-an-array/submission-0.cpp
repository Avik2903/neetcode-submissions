class Solution {
public:
void merge(vector<int>& nums,int p,int r,int q)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; i++)
        L[i] = nums[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = nums[q + 1 + j];
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        nums[k] = M[j];
        j++;
        k++;
    }
}
void mergesort(vector<int>& nums, int s,int l)
{
    if(l>s)
    {
        int mid= s+(l-s)/2;;
        mergesort(nums,s,mid);
        mergesort(nums,mid+1,l);
        merge(nums,s,l,mid);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};