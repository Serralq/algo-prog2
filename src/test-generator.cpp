#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k, m, max_int;
  std::cin >> k >> m >> max_int;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, max_int);

  std::cout << k << " " << m << "\n";
  while (m--)
    std::cout << dist(gen) << " ";
  std::cout << "\n";

  return 0;
}
