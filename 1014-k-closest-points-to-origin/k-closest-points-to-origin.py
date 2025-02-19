class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        new_points=[]
        

        def ToScore():
            for i in range(len(points)):
                x=abs(points[i][0])
                y=abs(points[i][1])

                if x==0 or y==0:
                    len_i=max(x,y)
                else:
                    len_i=x*math.sqrt(1+(y/x)*(y/x))
                    
                new_item=[]
                new_item.append(points[i][0])
                new_item.append(points[i][1])
                new_item.append(len_i)
                new_points.append(new_item)
                
                
        ToScore()
        points_sort=sorted(new_points, key=lambda x:x[2])
        points_output=[]
        print(new_points)
        print(points_sort)
        
        for j in range(0,k):
            item=points_sort[j]
            del item[-1:]
            points_output.append(item)

        return points_output


