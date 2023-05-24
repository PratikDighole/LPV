// #include<bits/stdc++.h>
// using namespace std;
// int N=1e5+10;
// vector<vector<int>> graph(N,vector<int>());
// vector<int> vis(N,false);
// vector<int> vis1(N,false);

// void parallel_dfs(int v){
//     vis[v]=true;
//     cout<<v<<" ";
//     #pragma omp parallel for
//     for(auto j:graph[v]){
//         if(vis[j]!=true)parallel_dfs(j);
//     }
// }

// void parallel_bfs(int v){
//     vis1[v]=true;
//     queue<int> q;
//     q.push(v);
//     while(!q.empty()){
//         int curr=q.front();
//         cout<<curr<<" ";
//         #pragma omp critical
//         q.pop();
//         #pragma omp parallel for
//         for(auto j=graph[curr].begin(); j != graph[curr].end();j++){
//             if(vis1[*j]!=true){
//                 #pragma omp critical
//                 q.push(*j);
//                 vis1[*j]=true;
//             }
//         }
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int v1,v2;
//         cin>>v1>>v2;
//         graph[v1].push_back(v2);
//     }
//     parallel_dfs(0);
//     parallel_bfs(0);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// void parallel_bubble(vector<int> &v){
//     for(int i=0;i<v.size();i++){
//         bool swapped=false;
//         for(int j=0;j<v.size()-i-1;j++){
//             if(v[j]>v[j+1]){
//                 swapped =true;
//                 swap(v[j],v[j+1]);
//             }
//         }
//         if(!swapped)break;
//     }
// }
// void merge_sort(vector<int> &v,int s,int m,int e){
//     int n1=m-s+1,n2=e-m;
//     vector<int> f(n1);
//     vector<int> sec(n2);
//     for(int i=0;i<n1;i++){
//         f[i]=v[s+i];
//     }
//     for(int i=0;i<n2;i++){
//         sec[i]=v[m+i+1];
//     }
//     int i=0,j=0,k=s;
//     while(i<n1 && j<n2){
//         if(f[i]<=sec[j]){
//             v[k]=f[i];
//             i++;
//             k++;
//         }
//         else{
//             v[k]=sec[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<n1){
//         v[k]=f[i];
//         i++;k++;
//     }
//     while(j<n2){
//         v[k]=sec[j];
//         j++;k++;
//     }
// }

// void merge(vector<int> &v,int s,int e){
//     if(s<e){
//         int mid=s+(e-s)/2;
//         merge(v,s,mid);
//         merge(v,mid+1,e);
//         merge_sort(v,s,mid,e);
//     }
// }
// int main(){
//     vector<int> v={23,65,97,56,21,43};
//     // #pragma omp parallel 
//     // {
//     // parallel_bubble(v);
//     // }
//     #pragma omp parallel 
//     {
//     #pragma omp single nowait
//     merge(v,0,v.size()-1);
//     }
//     for(auto i:v)cout<<i<<" ";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// void min_red(vector<int> v,int n){
//     int minv=INT_MAX;
//     #pragma omp parallel for reduction(min:minv)
//     for(int i=0;i<n;i++){
//         if(v[i]<minv)minv=v[i];
//     }
//     cout<<minv<<endl;
// }

// void max_red(vector<int> v,int n){
//     int maxv=v[0];
//     #pragma omp parallel for reduction(max:maxv)
//     for(int i=1;i<n;i++){
//         if(v[i]>maxv)maxv=v[i];
//     }
//     cout<<maxv<<endl;
// }
// void sum_red(vector<int> v,int n){
//     int sum=0;
//     #pragma omp parallel for reduction(+:sum)
//     for(auto i:v)sum+=i;
//     cout<<sum<<endl;
// }
// void avg_red(vector<int> v,int n){
//     int sum=0;
//     #pragma omp parallel for reduction(+:sum)
//     for(auto i:v)sum+=i;
//     cout<<sum/n<<endl;
// }

// int main(){
//     vector<int> v={13,53,65,88,98,54};
//     int n=v.size();
//     min_red(v,n);
//     max_red(v,n);
//     sum_red(v,n);
//     avg_red(v,n);
//     return 0;
// }