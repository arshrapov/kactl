/**
* Author: Peltorator
 * Date: 11.05.2024
 * Source: peltorator.ru
 * Description: xor convolution
 * Status: not testsed
 * Time: $O(n * logn)$.
 */
#pragma once

vt<int> hadamard_transform(const vt<int>& a) {
	vt<int> dp = a;
	for (size_t bit = 1; bit < a.size(); bit <<= 1) {
		for (size_t mask = 0; mask < a.size(); mask++) {
			if ((mask & bit) == 0) {
				int u = dp[mask], v = dp[mask ^ bit];
				dp[mask] = u + v;
				dp[mask ^ bit] = u - v;
			}
		}
	}
	return dp;
}

vt<int> inverse_hadamard_transform(const vt<int>& f) {
	vt<int> dp = f;
	for (size_t bit = 1; bit < f.size(); bit <<= 1) {
		for (size_t mask = 0; mask < f.size(); mask++) {
			if ((mask & bit) == 0) {
				int x = dp[mask], y = dp[mask ^ bit];
				dp[mask] = (x + y) / 2;
				dp[mask ^ bit] = (x - y) / 2;
			}
		}
	}
	return dp;
}

	// a.size() == b.size() == 2^k
vt<int> xor_convolution(const vt<int>& a, const vt<int>& b) {
	vt<int> f = hadamard_transform(a);
	vt<int> g = hadamard_transform(b);
	vt<int> h(f.size());
	for (size_t i = 0; i < f.size(); i++) {
		h[i] = f[i] * g[i];
	}
	vt<int> c = inverse_hadamard_transform(h);
	return c;
}
