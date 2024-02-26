import queue
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

visited=[]
queue=[]
top=[]

def bfs(visited,graph,node):
    visited.append(node)
    queue.append(node)

    while queue:
        m=queue.pop(0)
        top.append(m)

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

    print("traversed output =",top)

node=input("enter the node from where you want to traverse =")
bfs(visited,adj_list,node)
