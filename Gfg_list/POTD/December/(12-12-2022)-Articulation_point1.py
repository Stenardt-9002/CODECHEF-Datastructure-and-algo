class Solution:

    def dfs_util(self , src ,graph , visisted_array ,ans , parent , lowest_t , time_f ,timer1):
        children = 0 
        visisted_array[src] = True 
        time_f[src] = timer1[0]
        lowest_t[src] = timer1[0]
        timer1[0]+=1 

        for child in graph[src]:
            if visisted_array[child]==False:
                parent[child] = src 
                children+=1 
                self.dfs_util(child , graph , visisted_array , ans , parent , lowest_t , time_f , timer1)

                lowest_t[src] = min(lowest_t[src],lowest_t[child])
                if parent[src]==-1 and children>1 :
                    ans[src] = True #articulation point
                if parent[src]!=1 and lowest_t[child]>=time_f[src]:
                    ans[src] = True 
            elif child!=parent[src]:
                lowest_t[src] = min(lowest_t[src] , time_f[child])


    #Function to return Breadth First Traversal of given graph.
    def articulationPoints(self, V, adj):
        visited_array = [False]*V 
        time_f = [99999]*V 
        lowest_t = [99999]*V 
        parent = [-1]*V 
        ans = [False]*V 

        # code here

        timer1 = [0]
        for i in range(V):
            if(visited_array[i]==False):
                self.dfs_util(i ,adj, visited_array , ans , parent ,  lowest_t , time_f ,timer1)

        set_points = []        
        for index , val in enumerate(ans):
            if val==True:
                set_points.append(index)

        return set_points

