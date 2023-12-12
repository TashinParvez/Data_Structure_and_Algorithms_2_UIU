#include<bits/stdc++.h>
using namespace std;

int getCrossingMagicalSum(const vector<int> &array, int left, int mid, int right){
    
    // on the left part:
    
    int leftSum=0;
    int leftMaxSum=INT_MIN;

    for(int i=mid;i>=left;i--){
        int current=array[i];

        if((current%2==0 || current%3==0) && current>0){
            leftSum+=current;

            if(leftSum>leftMaxSum){
                leftMaxSum=leftSum;
            }
        }else break;
    }

    // on the right part

    int rightSum=0;
    int rightMaxSum=INT_MIN;

    for(int i=mid+1;i<=right;i++){
        int current=array[i];

        if((current%2==0 || current%3==0) && current>0){
            rightSum+=current;

            if(rightSum>rightMaxSum){
                rightMaxSum=rightSum;
            }
        }else break;
    }

    return leftMaxSum + rightMaxSum; // the crossing point
}

int getMaxMagicalSubarraySum(const vector<int> &array, int left, int right){
    if(left==right){
        //base case
        //single element
        // return the value if meets conditon
        // return 0 if doesn't meets condtion

        return ((array[left] % 2 == 0 || array[left] % 3 == 0) && (array[left]>0)) ? array[left] : 0;
    }else{
        //divide the array into two parts
        int mid=(left+right)/2;

        int leftMagicalSum=getMaxMagicalSubarraySum(array,left,mid);
        int rightMagicalSum=getMaxMagicalSubarraySum(array,mid+1,right);
        int crossingMagicalSum=getCrossingMagicalSum(array,left,mid,right);

        return max(
          leftMagicalSum,
          max(rightMagicalSum, crossingMagicalSum)  
        );
    }
}

void run(){
    int n;
    cin>>n;
    
    vector<int>array;

     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        array.push_back(x);
    }

    int result = getMaxMagicalSubarraySum(array,0,n-1);

    cout<<result<<endl;
}

int main(){
    // test cases
    int t;
    cin>>t;
    
    while(t--){
        run();
    }
    
    return 0;
}