#include <iostream>
#include <vector>
#include <algorithm>

struct MyStruct {
	
	MyStruct(const int& x1, const int& x2, const std::string& x3) : x1_(x1), x2_(x2), x3_(x3) {}
	
	int x1_;
	int x2_;
	std::string x3_;

};

template<class T>
class comparer_builder {
	
public:
	comparer_builder();

	comparer_builder& by(void* member) {
		order_.push_back(member);
		return *this;
	}

	bool operator()(T a, T b) const {

		size_t i = 0;

		while (!sorted_ && i != order_.size()) {
			if (a.order_[i] != b.order_[i])
				sorted_ = true;
			else
				i++;
		}

		return a.order_[i] < b.order_[i];
	}

private:
	std::vector<void*> order_;
	bool sorted_ = false;
};

int main(){
	MyStruct s1(1, 5, "Mike");
	MyStruct s2(6, 100, "David");
	MyStruct s3(33, 0, "Zach");
	std::vector<MyStruct> vec = { s1, s2, s3 };
	// Issue: void* can't be used to hold value of pointer to member.
	std::sort(vec.begin(), vec.end(), comparer_builder<MyStruct>().by(&MyStruct::x1_).by(&MyStruct::x2_));
}