/**
* Author: Peltorator
 * Date: 11.05.2024
 * Source: peltorator.ru
 * Description: or convolution(for and convolution just use complanar value x instead of x)
 * Status: not testsed
 * Time: $O(n * logn)$.
 */
#pragma once

vt<int> sum_over_subsets(const vt<int>& a) {
	vt<int> dp = a;
	for (size_t bit = 1; bit < a.size(); bit <<= 1) {
		for (size_t mask = 0; mask < a.size(); mask++) {
			if ((mask & bit) != 0) {
				dp[mask] += dp[mask ^ bit];
			}
		}
	}
	return dp;
}

vt<int> inverse_sum_over_subsets_simplified(const vt<int>& b) {
	vt<int> dp = b;
	for (size_t bit = 1; bit < b.size(); bit <<= 1) {
		for (size_t mask = 0; mask < b.size(); mask++) {
			if ((mask & bit) != 0) {
				dp[mask] -= dp[mask ^ bit];
			}
		}
	}
	return dp;
}

// a.size() == b.size() == 2^k
vt<int> or_convolution(const vt<int>& a, const vt<int>& b) {
	vt<int> f = sum_over_subsets(a);
	vt<int> g = sum_over_subsets(b);
	vt<int> h(f.size());
	for (size_t i = 0; i < f.size(); i++) {
		h[i] = f[i] * g[i];
	}
	vt<int> c = inverse_sum_over_subsets(h);
	return c;
}
