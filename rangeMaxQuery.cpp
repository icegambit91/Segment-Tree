//Max number present in given range in an array using a segment tree

#include <iostream>
#include <math.h>

using namespace std;

int s, e;// Range -> [s, e] where s >= 1 and e <= n

int segTreeSet(int segTree[], int arr[], int idx, int l, int r){
    if (l == r){
        segTree[idx] = arr[l];
        return segTree[idx];
    }

    int left = segTreeSet(segTree, arr, (2 * idx) + 1, l, (l + r) / 2);
    int right = segTreeSet(segTree, arr, (2 * idx) + 2, (l + r + 2) / 2, r);

    if (left > right){
        segTree[idx] = left;
        return segTree[idx];
    }
    else{
        segTree[idx] = right;
        return segTree[idx];
    }
}

int segTreeMax(int segTree[], int arr[], int idx, int l, int r){
    if (s > r || e < l){
        return 0;
    }
    else if (s <= l && e >= r){
        return segTree[idx];
    }
    else{
        int left = segTreeMax(segTree, arr, (2 * idx) + 1, l, (l + r) / 2);
        int right = segTreeMax(segTree, arr, (2 * idx) + 2, (l + r + 2) / 2, r);

        if (left > right){
            return left;
        }
        else{
            return right;
        }
    }
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

    int numQuery;
    cin >> numQuery;

    for (int i = 0 ; i < numQuery ; i++){
        cin >> s >> e;
        s--;
        e--;
        cout << segTreeMax(segTree, arr, 0, 0, n - 1) << endl;
    }
}
