#include "Header.h"

SimpleQuickUnion::SimpleQuickUnion(int N) : id(new int[N]), count(N), N(N) {
	iota(id, id + N, 0);
}

int SimpleQuickUnion::count_components() {
	return count;
}

bool SimpleQuickUnion::connected(int p, int q) {
	return id[p] == id[q];
}

int SimpleQuickUnion::find(int p) {
	return id[p];
}

/*void SimpleQuickUnion::union_elem(int p, int q) {
	if (connected(p, q))
		return;
	for (int i = 0; i < N; i++) {
		if (id[i] == id[p])
			id[i] = q;
	}
	count--;
}*/

void SimpleQuickUnion::union_elem(int p, int q) {
	int p_id = find(p);
	int q_id = find(q);
	if (p_id == q_id) return;
	for (int i = 0; i < N; i++)
		if (id[i] == p_id) id[i] = q_id;
	count--;
}

SimpleQuickUnion::~SimpleQuickUnion() {
	delete(id);
}
