/**
 * Author: Simon Lindholm
 * Date: 2019-05-22
 * License: CC0
 * Description: Chinese Remainder Theorem.
 *
 * $x \equiv a_i$ $mod m_i$
 * $m_i$ is co-prime
 * Time: $\log(n)$
 * Status: not tested
 */
#pragma once

#include "euclid.h"

struct Congruence {
 ll a, m;
};

ll chinese_remainder_theorem(vector<Congruence> const& congruences) {
	ll M = 1;
	for (auto const& congruence : congruences) {
		M *= congruence.m;
	}
	ll solution = 0;
	for (auto const& congruence : congruences) {
		ll a_i = congruence.a;
		ll M_i = M / congruence.m;
		ll N_i = mod_inv(M_i, congruence.m);
		solution = (solution + a_i * M_i % M * N_i) % M;
	}
	return solution;
}