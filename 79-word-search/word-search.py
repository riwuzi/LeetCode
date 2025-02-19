class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        start=word[0]
        row=len(board)
        column=len(board[0])
        word_len=len(word)
        matrix = [[0 for _ in range(column)] for _ in range(row)]
        
        flag=0
        
        def BFS(a: int,b: int,c: int,d: int,matrix: List[List[column]]):
            if c==d:
             return 1
            if a>=0 and a<row and b-1>=0 and b-1<column and matrix[a][b-1]==0:
             matrix[a][b-1]=1
             if board[a][b-1]==word[c] and BFS(a,b-1,c+1,d,matrix)==1:
              return 1
             else:
              matrix[a][b-1]=0

            if a>=0 and a<row and b+1>=0 and b+1<column and matrix[a][b+1]==0:
             matrix[a][b+1]=1
             if board[a][b+1]==word[c] and BFS(a,b+1,c+1,d,matrix)==1:
              return 1
             else:
              matrix[a][b+1]=0

            if a-1>=0 and a-1<row and b>=0 and b<column and matrix[a-1][b]==0: 
             matrix[a-1][b]=1
             if board[a-1][b]==word[c] and BFS(a-1,b,c+1,d,matrix)==1:
              return 1
             else:
              matrix[a-1][b]=0

            if a+1>=0 and a+1<row and b>=0 and b<column and matrix[a+1][b]==0:
             matrix[a+1][b]=1
             if board[a+1][b]==word[c] and BFS(a+1,b,c+1,d,matrix)==1:
              return 1
             else:
              matrix[a+1][b]=0
            
            
            
            
            return 0

        if row*column<word_len:
         return False

        for i in range(row):
            for j in range(column):
                if board[i][j]==start:
                 matrix[i][j]=1
                 if BFS(i,j,1,word_len,matrix)==1:
                  flag=1
                  break
                 else:
                  matrix[i][j]=0
                  continue

                 

        if flag==1:
         return True
        else:
         return False
  

        #while not q.empty():
        
        
        