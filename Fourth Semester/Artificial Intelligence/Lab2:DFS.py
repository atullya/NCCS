adj_list={
    "a":["b","c","d"],
    "b":["e"],
    "c":["f","g"],
    "d":["h","i"],
    "e":[],
    "f":[],
    "g":[],
    "h":[],
    "i":[],
    }

closedlist={}
top=[]

for node in adj_list.keys():
    closedlist[node]="notvisited"

def dfs(stnode):
    closedlist[stnode]="visited"
    top.append(stnode)

    for v in adj_list[stnode]:
        if closedlist[v]!="visited":
            dfs(v)
    
stnode=input("enter the start node from where you want to traverse= ")
dfs(stnode)
print("traversed output = ",top)
