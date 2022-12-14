#include <bits/stdc++.h>

using namespace std;

template <class T>
struct SegmentTree{
    int N;
    vector <T> tree;

    SegmentTree(vector<T> &init) {
        N = init.size();
        tree.resize(4*N);
        build(0, 0, N-1, init);
    }


    T merge1(T a, T b){ // Reemplazar esta funcion para determinar como juntar dos nodos para obtener el valor de su padre, en este caso es suma
        return a | b;
    }

    T merge2(T a, T b){
        return a ^ b;
    }

    void build(int n, int i, int j, vector<T> &init){
        if(i == j){
            tree[n] = init[i];
            return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, init);
        build(2*n+2, mid+1, j, init);
        int height=(int)log2(N+1)-(int)log2(n+1);
        if(height%2==1){
            tree[n] = merge1(tree[2*n+1], tree[2*n+2]);
        }
        else if(height%2==0){
            tree[n] = merge2(tree[2*n+1], tree[2*n+2]);
        }
    }

    void update(int t, T val){
        update(0, 0, N-1, t, val);
    }
  
    void update(int n, int i, int j, int t, T val){
        if(t < i || j < t) return;
        if(i == j){
            tree[n] = val;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, t, val);
        update(2*n+2, mid+1, j, t, val);
        int height=(int)log2(N+1)-(int)log2(n+1);
        if(height%2==1){
            tree[n] = merge1(tree[2*n+1], tree[2*n+2]);
        }
        else if(height%2==0){
            tree[n] = merge2(tree[2*n+1], tree[2*n+2]);
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(pow(2,n));
    for(int i=0; i<pow(2, n); i++){
        cin>>a[i];
    }
    
    SegmentTree<int> st(a);
    
    for(int i=0; i<m; i++){
        vector<int> pairs(2);

        cin >> pairs[0] >> pairs[1];
        st.update(pairs[0]-1, pairs[1]);

        cout<<st.tree[0]<<endl;
    }
    return 0;
}