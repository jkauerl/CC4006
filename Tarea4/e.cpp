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
    long long max_number=max(a.first,b.first);
    long long index_max_number;
    if(max_number==a.first){
      index_max_number=a.second;
    }
    if(max_number==b.first){
      index_max_number=b.second;
    }
    return make_pair(max_number, index_max_number);
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

  int search(int from, T val){
    if(!from) return search(0, 0, N-1, val);
    return search(0, 0, N-1, val+query(0, from-1));
  }

  int search(int n, int i, int j, T val){
    if(tree[n] < val) return -1;
    if(i==j && tree[n] >= val) return i;
    int mid = (i+j)/2;
    if(tree[2*n+1] >= val) return search(2*n+1, i, mid, val);
    else return search(2*n+2, mid+1, j, val-tree[2*n+1]);
  }
};

int main(){
    int N;
    cin>>N;

    vector<pair<long long, long long>> A(N);

    for(int i=0; i<N; i++){
        long long value;
        cin>>value;
        A[i]=make_pair(value,i);
    }

    SegmentTree<pair<long long, long long>> st(A);

    int Q;
    cin>>Q;

    for(int k=0; k<Q; k++){
        char Instruction;

        cin>>Instruction;

        if(Instruction=='U'){
            long long index, change;
            cin>>index>>change;
            st.update(index-1, make_pair(change, index-1));
        }
        else if(Instruction=='Q'){
            long long i, j;
            cin>>i>>j;

            pair<long long, long long> max_number1=st.query(i-1, j-1);
            st.update(max_number1.second, make_pair(0,max_number1.second));
            pair<long long, long long> max_number2= st.query(i-1, j-1);
            st.update(max_number1.second, make_pair(max_number1.first, max_number1.second));
            cout<<(max_number1.first+max_number2.first)<<endl;
        }

    }
}