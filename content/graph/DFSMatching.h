/**
 *	Author: nor
 *	Date: 2024-11-11
 *	License: CC0
 *	Source: yosupo.judge
 *	Description: Fast bipatrite algorithm
 *	Time: O(VE), in real better
 *	Status: works
 */
#pragma once
 
#include "randomizer.h"

template <bool ToShuffle = false>
struct bipartite_matching {
	int n, m, flow = 0;
	vt<vt<int>> g;
	vt<int> matchL, matchR, dist;
	bipartite_matching(int _n, int _m): n(_n), m(_m), g(_n), matchL(_n, -1), matchR(_m, -1), dist(_n) {}
	void add(int u, int v) { g[u].push_back(v); }
	void bfs() {
		std::queue<int> q;
		for (int u = 0; u < n; ++u) {
			if (!~matchL[u]) q.push(u), dist[u] = 0;
			else dist[u] = -1;
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto v : g[u]) if (~matchR[v] && !~dist[matchR[v]]) {
				dist[matchR[v]] = dist[u] + 1;
				q.push(matchR[v]);
			}
		}
	}
	bool dfs(int u) {
		for (auto v : g[u])
			if (!~matchR[v]) {
				matchL[u] = v, matchR[v] = u;
				return true;
			}
		for (auto v : g[u])
			if (dist[matchR[v]] == dist[u] + 1 &&
				dfs(matchR[v])) {
				matchL[u] = v, matchR[v] = u;
				return true;
			}
		return false;
	}
	int get_max_matching() {
		if constexpr (ToShuffle) {
			Random rng;
			for (int i = 0; i < n; ++i)
				std::random_shuffle(std::begin(g[i]), std::end(g[i]), rng);
		}
		while (true) {
			bfs();
			int augment = 0;
			for (int u = 0; u < n; ++u)
				if (!~matchL[u]) augment += dfs(u);
			if (!augment) break;
			flow += augment;
		}
		return flow;
	}
	std::pair<vt<int>, vt<int>> minimum_vertex_cover() {
		vt<int> L, R;
		for (int u = 0; u < n; ++u) {
			if (!~dist[u])
				L.push_back(u);
			else if (~matchL[u])
				R.push_back(matchL[u]);
		}
		return {L, R};
	}
	vt<std::pair<int, int>> get_edges() {
		vt<std::pair<int, int>> ans;
		for (int u = 0; u < n; ++u)
			if (matchL[u] != -1)
				ans.emplace_back(u, matchL[u]);
		return ans;
	}
};
