#include <iostream>
#include <vector>

void getDP(std::vector<int> data)
{
	long long sum = 0;
	for (int d : data) {
		sum += d;
	}

	std::vector<int> dp(sum + 1, false);
	dp[0] = true;
	for (int d : data) {
		for (int x = sum; x >= d; --x) {
			dp[x] |= dp[x - d];
		}
	}
	
	for (int i = 0; i <= sum; ++i) {
		if (dp[i]) {
			std::cout << "dp[" << i << "] = true" << std::endl;
		}
		else {
			std::cout << "dp[" << i << "] = false" << std::endl;
		}
	}
}

int getMinProcessingTime(std::vector<int> data, int processTimeA, int processTimeB) {
	long long sum = 0;
	for (int d : data) {
		sum += d;
	}

	// 动态位集：dp 的第 x 位为 1 表示处理器 A 可以处理总量 x
	const int W = (int)((sum + 64) / 64); // 至少 1 个 64 位字
	std::vector<unsigned long long> dp(W, 0);
	dp[0] = 1ULL; // 总量 0 可达

	for (int d : data) {
		const int ws = d >> 6;      // 移动多少个 64 位字
		const int bs = d & 63;      // 字内移动多少位

		if (bs == 0) { // d 是 64 的倍数
			for (int i = W - 1; i >= ws; --i) {
				dp[i] |= dp[i - ws];
			}
		}
		else { // d 不是 64 的倍数
			for (int i = W - 1; i >= ws; --i) {
				unsigned long long val = dp[i - ws] << bs;
				if (i - ws - 1 >= 0) {
					val |= dp[i - ws - 1] >> (64 - bs);
				}
				dp[i] |= val;
			}
		}
	}

	auto reachable = [&](long long x) -> bool {
		return (dp[(int)(x >> 6)] >> (x & 63)) & 1ULL;
		};

	long long ans = LLONG_MAX;

	for (long long x = 0; x <= sum; ++x) {
		if (!reachable(x))
			continue;

		std::cout << "x: " << x << std::endl; // Debugging output

		long long timeA = x * (long long)processTimeA;
		long long timeB = (sum - x) * (long long)processTimeB;

		ans = std::min(ans, std::max(timeA, timeB));
	}

	return (int)ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> data(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> data[i];
	}

	int processTimeA, processTimeB;
	std::cin >> processTimeA >> processTimeB;

	std::cout << getMinProcessingTime(data, processTimeA, processTimeB) << '\n';

	return 0;
}