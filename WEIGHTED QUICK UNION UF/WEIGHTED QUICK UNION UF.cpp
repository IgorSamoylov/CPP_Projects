#include "Header.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int N) : 
	id(new int[N]), sz(new int[N]), count(N), N(N) {
	
	iota(id, id + N, 0);
	iota(sz, sz + N, 0);
}

int WeightedQuickUnionUF::count_components() {
	return this->count;
}

int WeightedQuickUnionUF::find(int p) {
	while (p != id[p])
		p = id[p];
	return p;
}

bool WeightedQuickUnionUF::connected(int p, int q) {
	return find(p) == find(q);
}

void WeightedQuickUnionUF::union_elem(int p, int q) {
	int i = find(p);
	int j = find(q);
	if (i == j) return;

	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	}
	else {
		id[j] = i;
		sz[i] += sz[j];
	}
	count--;
	//cout << count << " ";
}

WeightedQuickUnionUF::~WeightedQuickUnionUF() {
	delete(id);
	delete(sz);
}

