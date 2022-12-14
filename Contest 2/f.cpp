#include<bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree{
  int N;
  vector <T> tree;
  SegmentTree(int _N){
    N = _N;
    tree.resize(4*N);
    build(0, 0, N-1);
  }

  SegmentTree(vector<T> &init) {
    N = init.size();
    tree.resize(4*N);
    build(0, 0, N-1, init);
  }

  T merge(T a, T b){ // Reemplazar esta funcion para determinar como juntar dos nodos para obtener el valor de su padre, en este caso es suma
    return a + b;
  }

  void build(int n, int i, int j){
    if(i == j){
      tree[n] = 0;
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid);
    build(2*n+2, mid+1, j);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
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
    int n;
    cin>>n;
    vector<int> list(n);
    vector<int> order(n);

    for(int i=0; i<n; i++){
        cin>>list[i];
    }
    for(int i=0; i<n; i++){
        cin>>order[i];
    }

    int p=n;

    vector<int> a(n,1);

    SegmentTree<int> st(a);

    int i=0;
    int posicion_eliminada=0;
    while(p>0){
        int posicion_a_eliminar = order[i]-1;
        int j=st.search(i, list[posicion_a_eliminar]+1);
        cout<<list[posicion_a_eliminar]<<" ";
        st.update(posicion_a_eliminar, 0);
        i++;
        p--;
    }

    /* for(int i=0; i<n; i++){
        int posicion_a_eliminar;
        int restantes=st.query(i,n-1);
        if(restantes<posicion_a_eliminar+1){
            i=0;
            posicion_a_eliminar=posicion_a_eliminar-restantes;
        }

        int eliminado=st.search(i, posicion_a_eliminar+1);

        st.update(eliminado, 0);
        cout<<eliminado<<" ";
        eliminado++;
    } */
    cout<<endl;


    return 0;
}
