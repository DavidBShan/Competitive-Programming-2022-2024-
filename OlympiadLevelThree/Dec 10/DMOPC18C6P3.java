import java.util.*;
class DMPOPC18C6P3 {
    private static void dfs(ArrayList<ArrayList<Integer>> adj,boolean[] visited,int src,int v){
        visited[src]=true;
        for(int i=0;i<v;i++){
            if(adj.get(src).get(i)==1 && !visited[i]){
                dfs(adj,visited,i,v);
            }
        }
    }
    static int numProvinces(ArrayList<ArrayList<Integer>> adj, int V) {
        int count=0;
        boolean[] visited=new boolean[V];
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i,V);
            }
        }
        return count;
    }
    public static void main(String[] args){
        ArrayList = new 
    }
};