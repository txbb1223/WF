#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct MyStruct {

	MyStruct(const int& x1, const int& x2, const std::string& x3) : x1_(x1), x2_(x2), x3_(x3) {}

	int x1_;
	int x2_;
	const std::string& getName() const {
		return x3_;
	}

private:
	std::string x3_;

};


struct MyStruct2 {

	MyStruct2(const int& y1, const int& y2, const double& y3, const std::string& y4) : y1_(y1), y2_(y2), y3_(y3), y4_(y4) {}

	int y1_;
	int y2_;
	double y3_;
	const std::string& getName() const {
		return y4_;
	}

private:
	std::string y4_;

};


template<class T>
class comparer_builder {

public:

	comparer_builder& by(std::function<bool(const T&, const T&)> member) {
		order_.push_back(member);
		return *this;
	}

	bool operator()(const T& a, const T& b) const {

		size_t i = 0;

		while (i != order_.size()) {
			if (order_[i](a, b))
				return true;
			else if (order_[i](b, a))
				return false;
			
			// If not returned in the loop, meaning  a and b has the same value for this member,
			// then proceed to the next member in order_ in the next iteration
			i++;
		}

		return false;
	}

private:
	std::vector<std::function<bool(const T&,const T&)>> order_;
};

template<class T>
void printNames(const std::vector<T> vec) {
	std::cout << "Order is: ";
	for (auto i = vec.begin(); i != vec.end(); i++) {
		std::cout << (*i).getName();
		if (i != vec.end() - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

int main() {

	// Illustrate with the custom type "MyStruct"
	MyStruct s1(1, 5, "Mike");
	MyStruct s2(1, 100, "David");
	MyStruct s3(33, 0, "Zach");
	std::vector<MyStruct> vec = { s1, s2, s3 };

	auto XONE = [](const MyStruct& a, const MyStruct& b) { return a.x1_ < b.x1_; };
	auto XTWO = [](const MyStruct& a, const MyStruct& b) { return a.x2_ < b.x2_; };
	auto XTHREE = [](const MyStruct& a, const MyStruct& b) { return a.getName() < b.getName(); };


	std::sort(vec.begin(), vec.end(), comparer_builder<MyStruct>().by(XONE).by(XTHREE).by(XTWO));
	std::cout << "Sort by: x1->x3->x2" << std::endl;
	printNames<MyStruct>(vec);


	std::sort(vec.begin(), vec.end(), comparer_builder<MyStruct>().by(XTWO).by(XONE).by(XTHREE));
	std::cout << "Sort by: x2->x1->x3" << std::endl;
	printNames<MyStruct>(vec);



	// Illustrate with the custom type "MyStruct2"
	MyStruct2 t1(1, 5, 501.0, "Zoe");
	MyStruct2 t2(1, 100, 0.23241, "Aaron");
	MyStruct2 t3(33, 0, 98.1, "Baker");
	MyStruct2 t4(200, 1000, 0.23241, "Aaron");
	std::vector<MyStruct2> vec2 = { t1, t2, t3, t4 };

	auto YONE = [](const MyStruct2& a, const MyStruct2& b) { return a.y1_ < b.y1_; };
	auto YTWO = [](const MyStruct2& a, const MyStruct2& b) { return a.y2_ < b.y2_; };
	auto YTHREE = [](const MyStruct2& a, const MyStruct2& b) { return a.y3_ < b.y3_; };
	auto YFOUR = [](const MyStruct2& a, const MyStruct2& b) { return a.getName() < b.getName(); };


	std::sort(vec2.begin(), vec2.end(), comparer_builder<MyStruct2>().by(YFOUR).by(YTHREE).by(YTWO).by(YONE));
	std::cout << "Sort by: y4->y3->y2->y1" << std::endl;
	printNames<MyStruct2>(vec2);

}