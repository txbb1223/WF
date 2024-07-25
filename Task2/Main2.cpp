#include <iostream>
#include <vector>
#include <algorithm>

struct MyStruct {

	MyStruct(const int& x1, const int& x2, const std::string& x3) : x1_(x1), x2_(x2), x3_(x3) {}

	int x1_;
	int x2_;
	std::string x3_;

};

enum MyStructMember {XONE, XTWO, XTHREE};


class comparer_builder {

public:
	comparer_builder(MyStructMember order1, MyStructMember order2, MyStructMember order3) {
		order_.push_back(order1);
		order_.push_back(order2);
		order_.push_back(order3);

	}

	bool operator()(MyStruct a, MyStruct b) const {

		size_t i = 0;

		while (i != order_.size()) {
			if (order_[i] == XONE && a.x1_ != b.x1_) {
				return a.x1_ < b.x1_;
			}
			if (order_[i] == XTWO && a.x2_ != b.x2_) {
				return a.x2_ < b.x2_;
			}
			if (order_[i] == XTHREE && a.x3_ != b.x3_) {
				return a.x3_ < b.x3_;
			}
			else
				i++;
		}

		return a.x3_ < b.x3_;
	}

private:
	std::vector<MyStructMember> order_;
};

void printNames(const std::vector<MyStruct> vec) {
	std::cout << "Order is: ";
	for (auto i = vec.begin(); i != vec.end(); i++) {
		std::cout << (*i).x3_;
		if (i != vec.end() - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

int main() {
	MyStruct s1(1, 5, "Mike");
	MyStruct s2(1, 100, "David");
	MyStruct s3(33, 0, "Zach");
	std::vector<MyStruct> vec = { s1, s2, s3 };

	std::sort(vec.begin(), vec.end(), comparer_builder(XONE, XTHREE, XTWO));
	std::cout << "Sort by: x1->x3->x2" << std::endl;
	printNames(vec);

	std::sort(vec.begin(), vec.end(), comparer_builder(XTWO, XONE, XTHREE));
	std::cout << "Sort by: x2->x1->x3" << std::endl;
	printNames(vec);

}