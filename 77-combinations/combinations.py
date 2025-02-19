class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        L_flag=[0]*(n+1)
        L_k=[]
        L_sum=[]

        def DFS(n: int,k: int,index: int,L_flag: List[int],L_k: List[int],start: int):
            
            for i in range(start,n+1):
                if index==0:
                 L_k.clear()
                #print("the i is:")
                #print(i)
                #print("print all the flag")
                #for c in range(1,n+1):
                    #print(L_flag[c])
                 
                if L_flag[i]==0:
                    L_flag[i]=1
                    L_k.append(i)
                    #print("middle")
                    #print(L_k)

                    if index+1==k:
                        #print("L_sum_formor")
                        #print(L_sum)
                        L_k1=L_k.copy()
                        L_sum.append(L_k1)
                        #print("L_sum_next")
                        #print(L_sum)
                        ################################
                        L_k.pop(-1)
                        ################################
                        L_flag[i]=0
                        

                        continue
                        
                    else:
                        DFS(n,k,index+1,L_flag,L_k,i)
                        L_flag[L_k[-1]]=0
                        L_k.pop(-1)
                        
                else:
                   continue
                
            return
                       

        DFS(n,k,0,L_flag,L_k,1)
        return L_sum
        