# coding: utf-8

import heapq


class Dijkstra:

    """
    Dijkstra's algorithm: find the shortest path from a vertex
    O(E + log(V))
    verified:
        https://onlinejudge.u-aizu.ac.jp/#/courses/lesson/1/ALDS1/12/ALDS1_12_B
        https://onlinejudge.u-aizu.ac.jp/#/courses/lesson/1/ALDS1/12/ALDS1_12_C
    """

    def __init__(self, V, G, INF=float("inf")):

        """
        V: the number of vertexes
        E: adjacency list (all edge in G must be 0 or positive)
        INF: Infinity distance
        """
        self.V = V
        self.G = G
        self.INF = INF
        self.distance, self.prev = list(), list()


    def dijkstra(self, start):

        Q = list()
        self.distance = [self.INF for _ in range(self.V)]
        self.prev = [-1 for _ in range(self.V)]

        self.distance[start] = 0
        heapq.heappush(Q, (0, start))

        while len(Q) > 0:
            dist, from_v = heapq.heappop(Q)
            if self.distance[from_v] < dist:
                continue
            for to_v, nxt_dist in self.G[from_v]:
                if self.distance[from_v] + nxt_dist >= self.distance[to_v]:
                    continue
                self.distance[to_v] = self.distance[from_v] + nxt_dist
                heapq.heappush(Q, (self.distance[to_v], to_v))
                self.prev[to_v] = from_v

        return self.distance


    def get_path(self, goal):

        path = [goal]
        while self.prev[goal] != -1:
            path.append(prev[goal])
            goal = self.prev[end]

        return path[::-1]


if __name__ == "__main__":

    """
    an example of use
    """

    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n):
        v, _, *e = map(int, input().split())
        for u, d in zip(e[::2], e[1::2]):
            g[v].append((u, d))

    dist = Dijkstra(n, g).dijkstra(0)
    for i, d in enumerate(dist):
        print(i, d)
