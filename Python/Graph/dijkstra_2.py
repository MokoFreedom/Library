# coding: utf-8

from collentions import defaultdict
from heapq import *


class Graph:

    def __init__(self):
        
        g = defaultdict(list)

    
    def add_edge(from_node, to_node, cost, reverse_edge=False):

        g[from_node].append((to_node, cost))
        if reverse_edge:
            g[to_node].append((from_node, cost))


def dijkstra(g, start, goal):

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

if __name__ == "__main__":
	n = int(input())
	g = Graph()
	for i in range(n):
		ls = [map(int, input().split())]
		v = ls[0]
		ls.pop(0)
		for j in range(len(ls) / 2):
			g.add_edge(v, ls[j * 2], ls[j * 2 + 1])
	
