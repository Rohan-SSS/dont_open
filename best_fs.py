import queue

def heuristic(node):
    return heuristic_values.get(node, float('inf'))

def best_first_search(graph, start, goal, heuristic):
    visited = set()
    pq = queue.PriorityQueue()
    pq.put((heuristic(start), start, [start]))
    while not pq.empty():
        _, current, path = pq.get()
        if current == goal:
            return path
        visited.add(current)
        for neighbor in graph[current]:
            if neighbor not in visited:
                pq.put((heuristic(neighbor), neighbor, path + [neighbor]))  
    return [] 

if __name__ == '__main__':
    graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F'],
        'F': []
    }

    heuristic_values = {
        'A': 8,
        'B': 6,
        'C': 4,
        'D': 2,
        'E': 4,
        'F': 0
    }

    start_node = 'A'
    goal_node = 'F'

    path = best_first_search(graph, start_node, goal_node, heuristic)

    if path:
        print("Path:", path)
    else:
        print("Goal not reachable")
