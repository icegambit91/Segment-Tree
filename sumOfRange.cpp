//Sum of given range in an array using a segment tree

#include <iostream>
#include <math.h>

using namespace std;

int s, e; //Range for which sum is to be calculated -> [s, e] where s >= 1 and e <= n

int SegTreeSum(int segTree[], int arr[], int idx, int l, int r){
    if (r < s || l > e){
        return 0;
    }
    else if (l >= s && r <= e){
        return segTree[idx];
    }
    else{
        return SegTreeSum(segTree, arr, (2 * idx) + 1, l, (l + r) / 2) + SegTreeSum(segTree, arr, (2 * idx) + 2, (l + r + 2) / 2, r);
    }
}

int segTreeSet(int segTree[], int arr[], int idx, int l, int r){
    if (l == r){
        segTree[idx] = arr[l];
        return segTree[idx];
    }

    //Value in parent node = value in left child + value in right child
    segTree[idx] = segTreeSet(segTree, arr, (2 * idx) + 1, l, (l + r) / 2) + segTreeSet(segTree, arr, (2 * idx) + 2, (l + r + 2) / 2, r);
    return segTree[idx];
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    int levels = ceil(log10(n)/log10(2.0)) + 1, nodes = pow(2.0, levels) - 1;
    int segTree[nodes] = {0};

    segTreeSet(segTree, arr, 0, 0, n - 1);
    for (int i = 0 ; i < nodes ; i++){
        cout << segTree[i] << ' ';
    }
    cout << endl;
    int numQuery;
    cin >> numQuery;

    for (int i = 0 ; i < numQuery ; i++){
        cin >> s >> e;
        s--;
        e--;
        cout << SegTreeSum(segTree, arr, 0, 0, n - 1) << endl;
    }
}
