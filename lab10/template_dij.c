int *Graph::dijkstra(int src)
{
   int *dist = new int[nrNodes];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

     bool sptSet[nrNodes]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < nrNodes; i++)
        dist[i] = 16000, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < nrNodes-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       //int u = minDistance(dist, sptSet);
       int min = 16000, u;

       for (int v = 0; v < nrNodes; v++)
        if (sptSet[v] == false && dist[v] <= min) {
          min = dist[v];
          u = v;
        }

       // Mark the picked vertex as processed
       sptSet[u] = true;

       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < nrNodes; v++)

         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && a[u][v] && dist[u] != 16000 
                                       && dist[u]+a[u][v] < dist[v])
            dist[v] = dist[u] + a[u][v];
     }

     // print the constructed distance array
     return dist;
}