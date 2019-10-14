#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


struct BlockSize {
	int W;
	int D;
	int H;
};

int main() {
	int n, ro;
	cin >> n >> ro;
	vector<BlockSize> blocks(n);
	for (auto &b : blocks) {
		cin >> b.W >> b.D >> b.H;
	}
	uint64_t m = 0;
	for (auto &b : blocks) {
		m += static_cast<uint64_t>(b.W) * b.D * b.H * ro;
	}
	cout << m << endl;
	return 0;
}