
if you remember the bfs code then just
change loop from for neighbor in graph[node] =reversed(graph[node])
second stack.pop() not pop()
_____________________________________________________________________
dls:
recursive approach:
print(node,end=" ")
if(node==goal) return true
if(limit=0) return false
for(neighbor in graph[node])
 if(dls(graph,neigbour,goal,limit-1)
 return true
return false


_____________________________________________________________________


def dls(graph, start, goal, depth_limit):
def dfs(node, goal, depth, path):
# 1. Check if depth limit exceeded

if depth > depth_limit:
return None

# 2. Add current node to path

path.append(node)
print(f"Visiting: {node} at depth {depth}")

#3. Check if goal reached
if node == goal:
return path

# 4. Explore neighbors
for neighbor in graph.get(node, []):
result = dfs(neighbor, goal, depth + 1, path)
if result: # If goal found in recursion, return it up
return result

# 5. Backtrack: If goal not found in this branch, remove node
path.pop()

return None

# Run the search
result_path = dfs(start, goal, 0, [])
if result_path:
print(f"\nGoal found! Path: {' -> '.join(result_path)}")
else:
print(f"\nGoal not found within depth limit {depth_limit}")
# Run DLS with depth limit 3
dls(graph, 'A', 'I', 3)
_____________________________________________________________________________

def ids(graph, start, goal, max_depth):
    for depth in range(1, max_depth + 1):
        print(f"\nSearching at depth {depth}: ", end="")
        if dls(graph, start, goal, depth):
            print(f"\nGoal '{goal}' found at depth {depth}")
            return True
    print("\nGoal not found within max depth")
    return False
print("Goal not found within depth limit.")
# Test Iterative Deepening
start_node = 'A'
goal_node = 'I'
max_search_depth = 5
iterative_deepening(start_node, goal_node, max_search_depth)


_____________________________________________________________


def ucs(graph, start, goal):
    # Priority queue with (cumulative_cost, current_node, path_taken)
    queue = [(0, start, [start])]

    visited = set()

    while queue:
        # Pop the node with lowest cumulative cost
        queue.sort(key=lambda x: x[0])  # sort by cost
        cost, node, path = queue.pop(0)

        if node == goal:
            print(f"Path: {path} with total cost: {cost}")
            return path, cost

        if node not in visited:
            visited.add(node)
            for neighbor, weight in graph.get(node, []):
                if neighbor not in visited:
                    queue.append((cost + weight, neighbor, path + [neighbor]))

    print("Goal not reachable")
    return None, float('inf')


# Example weighted graph
graph_weighted = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('F', 1)],
    'D': [],
    'E': [('F', 2)],
    'F': []
}

ucs(graph_weighted, 'A', 'F')
__________________________________________________


graph = {
    'A': {'B': 2, 'C': 1},
    'B': {'D': 4, 'E': 3},
    'C': {'F': 1, 'G': 5},
    'D': {'H': 2},
    'E': {},
    'F': {'I': 6},
    'G': {},
    'H': {},
    'I': {}
}

# Heuristic function (estimated cost to reach goal 'I')
heuristic = {
    'A': 7, 'B': 6, 'C': 5,
    'D': 4, 'E': 7, 'F': 3,
    'G': 6, 'H': 2, 'I': 0
}

# Greedy Best-First Search Function (without heapq)
def greedy_bfs(graph, start, goal):
    frontier = [(start, heuristic[start])]  # List-based priority queue
    visited = set()                         # Set to keep track of visited nodes
    came_from = {start: None}               # Path reconstruction

    while frontier:
        # Sort frontier manually by heuristic value (ascending)
        frontier.sort(key=lambda x: x[1])

        current_node, _ = frontier.pop(0)   # Get node with best heuristic

        if current_node in visited:
            continue

        print(current_node, end=" ")
        visited.add(current_node)

        # Goal check
        if current_node == goal:
            path = []
            while current_node is not None:
                path.append(current_node)
                current_node = came_from[current_node]
            path.reverse()
            print(f"\nGoal found with GBFS. Path: {path}")
            return

        # Expand neighbors
        for neighbor in graph[current_node]:
            if neighbor not in visited:
                came_from[neighbor] = current_node
                frontier.append((neighbor, heuristic[neighbor]))

    print("\nGoal not found")


# Run Greedy Best-First Search
print("\nFollowing is the Greedy Best-First Search (GBFS):")
greedy_bfs(graph, 'A', 'I')

___________________________________________________________________________________-

def a_star(graph, start, goal):
    frontier = [(start, heuristic[start])]   # (node, f_cost)
    visited = set()
    g_costs = {start: 0}                     # g(n)
    came_from = {start: None}                # path reconstruction

    while frontier:
        # Sort by f(n) = g(n) + h(n)
        frontier.sort(key=lambda x: x[1])
        current_node, current_f = frontier.pop(0)

        if current_node in visited:
            continue

        print(current_node, end=" ")
        visited.add(current_node)

        # Goal check
        if current_node == goal:
            path = []
            while current_node is not None:
                path.append(current_node)
                current_node = came_from[current_node]
            path.reverse()
            print(f"\nGoal found with A*. Path: {path}")
            return

        # Explore neighbors
        for neighbor, cost in graph[current_node].items():
            new_g_cost = g_costs[current_node] + cost
            f_cost = new_g_cost + heuristic[neighbor]

            if neighbor not in g_costs or new_g_cost < g_costs[neighbor]:
                g_costs[neighbor] = new_g_cost
                came_from[neighbor] = current_node
                frontier.append((neighbor, f_cost))

    print("\nGoal not found")
-----------------------------------------------------------------------------------


from queue import PriorityQueue

class Node:
    def __init__(self, position, parent=None):
        self.position = position
        self.parent = parent
        self.g = 0   # cost from start node to current node
        self.h = 0   # heuristic cost to end node
        self.f = 0   # total cost (for Best-First, f = h)

    def __lt__(self, other):
        return self.f < other.f
def heuristic(current_pos, end_pos):
    # Manhattan distance heuristic
    return abs(current_pos[0] - end_pos[0]) + abs(current_pos[1] - end_pos[1])

def best_first_search(maze, start, end):
    rows, cols = len(maze), len(maze[0])

    start_node = Node(start)
    end_node = Node(end)

    frontier = PriorityQueue()
    frontier.put(start_node)

    visited = set()

    while not frontier.empty():
        current_node = frontier.get()
        current_pos = current_node.position

        # Goal check
        if current_pos == end:
            path = []
            while current_node:
                path.append(current_node.position)
                current_node = current_node.parent
            return path[::-1]   # reverse path

        visited.add(current_pos)

        # Explore neighbors (up, down, left, right)
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            new_pos = (current_pos[0] + dx, current_pos[1] + dy)

            if (
                0 <= new_pos[0] < rows and
                0 <= new_pos[1] < cols and
                maze[new_pos[0]][new_pos[1]] == 0 and
                new_pos not in visited
            ):
                new_node = Node(new_pos, current_node)
                new_node.g = current_node.g + 1
                new_node.h = heuristic(new_pos, end)
                new_node.f = new_node.h   # Best-First Search

                frontier.put(new_node)
                visited.add(new_pos)

    return None   # No path found

# Example maze
maze = [
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0],
    [0, 0, 1, 0, 1],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 1, 0]
]

start = (0, 0)
end = (4, 4)

path = best_first_search(maze, start, end)

if path:
    print("Path found:", path)


__________________________________________________________

def get_neighbors(state): 
    neighbors = [] 
    n = len(state) 
    for row in range(n): 
        for col in range(n): 
            if col != state[row]: 
                new_state = list(state) 
                new_state[row] = col 
                neighbors.append(new_state) 
    return neighbors 
 
# Simple Hill Climbing function 
def simple_hill_climbing(n): 
    # Random initial state 
    current_state = [random.randint(0, n - 1) for _ in range(n)] 
    current_conflicts = calculate_conflicts(current_state) 
    
    while True: 
        neighbors = get_neighbors(current_state) 
        next_state = None 
        next_conflicts = current_conflicts 
        # Find the first better neighbor 
        for neighbor in neighbors: 
            neighbor_conflicts = calculate_conflicts(neighbor) 
            if neighbor_conflicts < next_conflicts: 
                next_state = neighbor 
                next_conflicts = neighbor_conflicts 
                break  # Move to the first better neighbor 
        
        # If no better neighbor is found, return the current state 
        if next_conflicts >= current_conflicts: 
            break 
        
        # Move to the better neighbor 
        current_state = next_state 
        current_conflicts = next_conflicts 
    
    return current_state, current_conflicts 

# Run Simple Hill Climbing for N-Queens 
n = 8  # Change N here for different sizes 
solution, conflicts = simple_hill_climbing(4) 
# Print results 
if conflicts == 0: 
print(f"Solution found for {n}-Queens problem:") 
print(solution) 
else: 
print(f"Could not find a solution. Stuck at state with {conflicts} 
conflicts:") 
print(solution) 

________________________________________________________


def beam_search(start, goal, beam_width=2): 
# Initialize the beam with the start state 
beam = [(0, [start])]  # (cumulative cost, path) 
while beam: 
candidates = [] 
# Expand each path in the beam 
for cost, path in beam: 
current_node = path[-1] 
if current_node == goal: 
return path, cost  # Return the path and cost if goal            
# Generate successors 
for neighbor, edge_cost in graph.get(current_node, []): 
new_cost = cost + edge_cost 
new_path = path + [neighbor] 
candidates.append((new_cost, new_path)) 
# Select top-k paths based on the lowest cumulative cost 
beam = heapq.nsmallest(beam_width, candidates, key=lambda x: 
x[0]) 

#print(beam) 
return None, float('inf')  # Return None if no path is found 
# Run Beam Search 
start_node = 'S' 
goal_node = 'L' 
beam_width = 3 
path, cost = beam_search(start=start_node, goal=goal_node, 
beam_width=beam_width) 
# Print results 
if path: 
print(f"Path found: {' → '.join(path)} with total cost: {cost}") 
else: 
print("No path found.")

_______________________________________________________________________


import random
 
# ── Parameters ──────────────────────────────────────────────────
POP_SIZE      = 6
GENERATIONS   = 10
MUTATION_RATE = 0.1
BIT_LENGTH    = 5
 
# ── Helper Functions ─────────────────────────────────────────────
 
def to_decimal(binary):
    # Convert binary string → integer
    return int(binary, 2)
 
def fitness(ind):
    # f(x) = x² - 1
    x = to_decimal(ind)
    return x ** 2 - x
 
def init_population():
    # Random population of BIT_LENGTH-bit binary strings
    return [''.join(random.choice('01') for _ in range(BIT_LENGTH))
            for _ in range(POP_SIZE)]
 
def selection(pop):
    # Keep top-2 fittest individuals
    return sorted(pop, key=fitness, reverse=True)[:2]
 
def crossover(p1, p2):
    # Single-point crossover at a random cut
    point = random.randint(1, BIT_LENGTH - 2)
    return p1[:point] + p2[point:], p2[:point] + p1[point:]
 
def mutation(ind):
    # Flip each bit with probability MUTATION_RATE
    return ''.join(('1' if b == '0' else '0') if random.random() < MUTATION_RATE else b
                   for b in ind)
 
# ── Genetic Algorithm ────────────────────────────────────────────
 
population = init_population()
 
for gen in range(GENERATIONS):
    print(f"Generation {gen}: {population}")
 
    parents        = selection(population)          # Step 1 – Select
    child1, child2 = crossover(parents[0], parents[1])  # Step 2 – Crossover
    child1         = mutation(child1)               # Step 3 – Mutate
    child2         = mutation(child2)
    population     = parents + [child1, child2]     # Step 4 – New population
 
# ── Result ───────────────────────────────────────────────────────
 
best = max(population, key=fitness)
print("\nBest Solution:")
print("  Binary  :", best)
print("  Decimal :", to_decimal(best))
print("  f(x)    :", fitness(best))
