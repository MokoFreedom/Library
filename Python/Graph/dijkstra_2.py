# coding: utf-8

from collections import defaultdict
from heapq import *


def dijkstra(edges, start, goal):

    g = defaultdict(list)
    for l, r, c in edges:
        g[l].append((c, r))

    q, seen = [(0, start, ())], set()
    
    while q:
        (cost, v, path) = heappop(q)
        
        if v not in seen:
            seen.add(v)
            path = (v, path)

            if v == goal: return (cost, path)

            for next_cost, u in g.get(v, ()):
                if u not in seen:
                    heappush(q, (cost + next_cost, u, path))

    return float("inf")
