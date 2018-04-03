class UnionFind:
	def __init__(self, sz):
		self.data = [-1 for i in range(sz)]

	def unite(self, x, y):
		x, y = self.root(x), self.root(y)
		if x != y:
			if self.data[y] < self.data[x]:
				x, y = y, x
			self.data[x] += self.data[y]
			self.data[y] = x
		return x != y

	def same(self, x, y):
		return self.root(x) == self.root(y)

	def root(self, x):
		if self.data[x] < 0:
			return x
		self.data[x] = self.root(self.data[x])
		return self.data[x]

	def size(self, x):
		return -self.data[self.root(x)]

	def show(self, n):
		for i in range(n):
			print("i={}, root={}, size={}".format(i, self.root(i), self.size(i)))
