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

  T merge(T a, T b){ // Reemplazar esta funcion para determinar como juntar dos nodos para obtener el valor de su padre, en este caso es suma
    int gcd=__gcd(a.first, b.first);
    int gcd_counter=0;
    if(gcd==a.first){
      gcd_counter=a.second;
    }
    if(gcd==b.first){
      gcd_counter=b.second;
    }
    if(gcd==a.first and gcd==b.first){
      gcd_counter=a.second+b.second;
    }
    return make_pair(gcd, gcd_counter);
  }

  void build(int n, int i, int j, vector<T> &init){
    if(i == j){
      tree[n] = init[i];
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid, init);
    build(2*n+2, mid+1, j, init);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  T query(int l, int r){
    return query(0, 0, N-1, l, r);
  }

  T query(int n, int i, int j, int l, int r){
    if(l <= i && j <= r) return tree[n];
    int mid = (i+j)/2;
    if(mid < l || r < i)
      return query(2*n+2, mid+1, j, l, r);
    if(j < l || r < mid+1)
      return query(2*n+1, i, mid, l, r);
    return merge(
        query(2*n+1, i, mid, l, r),
        query(2*n+2, mid+1, j, l, r));
  }
};

int main(){

    int n;
    cin>>n;

    vector<pair<int,int>> f(n);
    int value;
    for(int i=0; i<n; i++){
        cin>>value;
        f[i]=make_pair(value, 1);
    }

    SegmentTree<pair<int,int>> st(f);

    int q;
    cin>>q;

    for(int k=0; k<q; k++){
      int l,r;
      cin>>l>>r;
      l--;
      r--;

      cout<<(r-l+1-st.query(l,r).second)<<endl;
    }
}