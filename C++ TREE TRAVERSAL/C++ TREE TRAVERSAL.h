#pragma once
#include <iostream>
#include <random>
#include <ctime>

template <class T>
class Node {
public:
	T val;
	Node<T>* left;
	Node<T>* right;
	Node(T val) : val(val) {}
};

template <class T>
class Tree {
public:
	Node<T>* first;

	template <class T>
	void add(T input) {
		if (first == nullptr) {
			first = new Node<T>(input);
			return;
		}

		Node<T>* node = first;
		Node<T>* lastPresent = nullptr;

		while (node != nullptr) {

			lastPresent = node;

			if (input > node->val) {
				node = node->right;
			}
			else if (input < node->val) {
				node = node->left;
			}
			else return;
		}

		node = new Node<T>(input);
		if (input > lastPresent->val) lastPresent->right = node;
		else lastPresent->left = node;
	}
};

template <class T>
void tree_traversal(Node<T>* node);