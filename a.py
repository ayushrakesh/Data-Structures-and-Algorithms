class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

def recoverDeadPods(pods, connections, queries):
    uf = UnionFind(pods + 1)
    active_pods = [set() for _ in range(pods + 1)]

#Create connections
    for u, v in connections:
        uf.union(u, v)

#Initialize all pods as active
    for pod in range(1, pods + 1):
        region = uf.find(pod)
        active_pods[region].add(pod)

    results = []
    for query in queries:
        type_q, pod_id = query
        region = uf.find(pod_id)

        if type_q == 1:  # Data-sending query
            if not active_pods[region]:
                results.append(-1)
            else:
                results.append(min(active_pods[region]))
        elif type_q == 2:  # Database-connection-failure query
            if pod_id in active_pods[region]:
                active_pods[region].remove(pod_id)

    return results

#Example usage
pods = 4
connections = [[1, 2], [2, 3], [1, 4], [4, 3]]
queries = [[2, 3], [1, 3], [2, 1], [1, 1]]

print(recoverDeadPods(pods, connections, queries))  # Output should be [1, 2]
