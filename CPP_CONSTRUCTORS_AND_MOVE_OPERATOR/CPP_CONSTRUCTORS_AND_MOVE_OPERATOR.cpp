#include <iostream>
using namespace std;


class Test {
public:
	Test() { cout << "Test()\n"; }
	Test(int x) : val_(x) { cout << "Test(" << x << ")\n"; }
	Test(const Test& t) : val_(t.val_) { cout << "Test(const Test& " << t.val_ << ")\n"; }
	//Test(Test&& t) : val_(t.val_) { cout << "Test(Test&& " << t.val_ << ")\n"; t.val_ = 0; }
	Test(const Test&& t) : val_(t.val_) { cout << "Test(const Test&& " << t.val_ << ")\n"; }

	~Test() { cout << "~Test(" << val_ << ")\n"; }
private:
	int val_ = 0;
};

struct Quest
{
	Test t;
	Quest(){}
	Quest(Test&& t) : t(t) {}
};

struct Quest1 : Quest
{
	Test t;
	Quest1(Test&& t) : t(move(t)) {}
};

int main(int argc, const char* argv[])
{
	Test t(5), s(6);
	Quest q(move(t));
	Quest1 w(move(s));
}