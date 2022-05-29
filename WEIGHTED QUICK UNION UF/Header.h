#pragma once

#include <algorithm>
#include <numeric>
#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class UF {
public:
	virtual int count_components() = 0;
	virtual bool connected(int p, int q) = 0;
	virtual void union_elem(int p, int q) = 0;
};

class SimpleQuickUnion : public UF {
	int* id;
	int count;
	int N;

public:
	explicit SimpleQuickUnion(int N);
	int count_components();
	bool connected(int p, int q);
	int find(int p);
	void union_elem(int p, int q);
	~SimpleQuickUnion();
};

class WeightedQuickUnionUF : public UF {
    int* id;
    int* sz;
    int count;
	int N;
public:
    explicit WeightedQuickUnionUF(int N);
    int count_components();
    int find(int p);
    bool connected(int p, int q);
    void union_elem(int p, int q);
    ~WeightedQuickUnionUF();
};
