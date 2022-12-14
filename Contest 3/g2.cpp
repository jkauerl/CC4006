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
    return min(a,b);
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
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }
};

int main() {
    long long n, q;
    cin>>n>>q;
    vector<long long> a1(n);
    vector<long long> a2(n);
    for(int i=0; i<n; i++){
        long long value;
        cin>>value;
        a1[i]=value+i;
        a2[i]=value-i;
    }
    SegmentTree<long long> st1(a1);
    SegmentTree<long long> st2(a2);

    for(int p=0; p<q; p++){
        int instruction;
        cin>>instruction;
        long long k;
        cin>>k;
        k--;
        if(instruction==1){
            long long x;
            cin>>x;
            st1.update(k,x+k);
            st2.update(k,x-k);
        }
        if(instruction==2){
            long long min_izquierda=st1.query(k,n-1)-k;
            long long min_derecha=st2.query(0,k)+k;
            cout<<min(min_derecha,min_izquierda)<<endl;
        }
    }
}