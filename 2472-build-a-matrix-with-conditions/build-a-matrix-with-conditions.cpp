class Solution {
public:
    void dfs(int vertex, const vector<vector<int>>& graph, unordered_set<int>& visited, stack<int>& Stack) {
    // Mark the current node as visited
    visited.insert(vertex);

    // Recur for all the vertices adjacent to this vertex
    for (int child : graph[vertex]) {
        if (visited.find(child) == visited.end()) {
            dfs(child, graph, visited, Stack);
        }
    }

    // Push the current vertex to the stack after all adjacent vertices are processed
    Stack.push(vertex);
}

// Function to perform topological sorting
    vector<int> topologicalSort(const vector<vector<int>>& graph, int V)
{
    unordered_set<int> visited;  // Set to keep track of visited nodes
    stack<int> Stack;            // Stack to store the topological order

    // Perform DFS for each vertex
    for (int i = 0; i < V; i++) {
        if (visited.find(i) == visited.end()) {
            dfs(i, graph, visited, Stack);
        }
    }

    // Extract the vertices from the stack to get the topological ordering
    vector<int> topoOrder;
    while (!Stack.empty()) {
        topoOrder.push_back(Stack.top());
        Stack.pop();
    }

    return topoOrder;  // Return the topological order
}
    
bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    // If the node is already in the recursion stack, a cycle is detected
    if (recStack[u])
        return true;

    // If the node is already visited and not in recursion stack, no need to check again
    if (visited[u])
        return false;

    // Mark the current node as visited and add it to the recursion stack
    visited[u] = true;
    recStack[u] = true;

    // Recur for all neighbors
    for (int x : adj[u])
    {
        if (isCyclicUtil(adj, x, visited, recStack))
            return true;
    }

    // Remove the node from the recursion stack
    recStack[u] = false;
    return false;
}

// Function to construct an adjacency list from edge list
vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V+10);
    for (auto &it : edges)
    {
        cout<<"V "<<V<<endl;
        cout<<"it[0] "<<it[0]<<endl;
        cout<<"it[1] "<<it[1]<<endl;
        adj[it[0]].push_back(it[1]); // Directed edge from it[0] to it[1]
    }
    return adj;
}

// Function to detect cycle in a directed graph
bool isCyclic(int V, vector<vector<int>> &edges)
{
    // Construct the adjacency list
    vector<vector<int>> adj = constructadj(V, edges);

    // visited[] keeps track of visited nodes
    // recStack[] keeps track of nodes in the current recursion stack
    vector<bool> visited(V+10, false);
    vector<bool> recStack(V+10, false);

    // Check for cycles starting from every unvisited node
    for (int i = 1; i <= V; i++)
    {
        if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
            return true; // Cycle found
    }

    return false; // No cycles detected
}



    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        vector<vector<int>> null_array(k);
        null_array.clear();  

        //check if there is a circle 
        if((isCyclic(k, rowConditions)==true)||(isCyclic(k, colConditions)==true))
         return null_array;
       





        vector<vector<int>> graph_row(k);
        vector<vector<int>> graph_col(k);
        

        int r,c;
        r=rowConditions.size();
        c=colConditions.size();

        int i,j;
        int x,y;

              

        for(i=0;i<r;++i)
        {
            x=rowConditions[i][0];
            y=rowConditions[i][1];
            graph_row[x-1].push_back(y-1);
           // auto it = find(graph_row[y-1].begin(), graph_row[y-1].end(), x-1);
           // if(it != graph_row[y-1].end())
              //  {
                   // cout<<"graph_row"<<x-1<<" "<<y-1<<endl;
                   // return(null_array);
                   // }
        }
         
        for(i=0;i<c;++i)
        {
            x=colConditions[i][0];
            y=colConditions[i][1];
            graph_col[x-1].push_back(y-1);
        
             
        }

        vector<int> row_n = topologicalSort(graph_row,k);
        vector<int> col_n = topologicalSort(graph_col,k);

        vector<vector<int>> map(k, vector<int>(k,0));

       

        int h=row_n.size();

        int hh=col_n.size();

       // cout<<"the h is:"<<h<<endl;
       // cout<<"the hh is:"<<hh<<endl;
        int a,col_i;

     //   cout<<"output the row_priority"<<endl;
      //  for(i=0;i<h;++i)
      //   cout<<row_n[i]<<" ";
      //  cout<<endl;

       // cout<<"output the col_priority"<<endl;
       // for(i=0;i<h;++i)
       //  cout<<col_n[i]<<" ";
      //  cout<<endl;

        for(i=0;i<h;++i)
    {
        a=row_n[i];

        auto it = find(col_n.begin(), col_n.end(), a);
        col_i= it - col_n.begin();

        map[i][col_i]=a+1;
    }

        return map;
    
    }
};