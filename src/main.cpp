#include <bits/stdc++.h>

int fifo(int k, int m, std::vector<int> r) {
  std::unordered_set<int> set;
  std::queue<int> queue;
  int misses = 0;

  for (int i : r) {
    if (set.count(i))
      continue;

    if (set.size() == k) {
      int j = queue.front();
      queue.pop();
      set.erase(j);
    }
    misses++;
    set.insert(i);
    queue.push(i);
  }
  return misses;
}

int lru(int k, int m, std::vector<int> r) {
  int misses = 0;
  std::list<int> list;
  std::unordered_map<int, std::list<int>::iterator> map;

  for (int i : r) {
    auto it = map.find(i);

    if (it != map.end()) {
      list.erase(it->second);
      list.push_front(i);
      map[i] = list.begin();

    } else {

      if (map.size() == k) {
        int lru_canidate = list.back();
        list.pop_back();
        map.erase(lru_canidate);
      }

      misses++;
      list.push_front(i);
      map[i] = list.begin();
    }
  }

  return misses;
}

int optff(int k, int m, std::vector<int> r) {
  int misses = 0;
  std::unordered_set<int> set;
  std::unordered_map<int, std::queue<int>> next_use;

  for (int i = 0; i < m; i++)
    next_use[r[i]].push(i);

  for (int i : r) {
    next_use[i].pop();

    if (set.count(i))
      continue;

    if (set.size() == k) {
      int canidate_front = -1;
      int canidate_j = -1;

      // Checking every possible option
      for (int j : set) {
        if (next_use[j].empty()) {
          canidate_j = j;
          break;
        } else {
          if (next_use[j].front() > canidate_front) {
            canidate_j = j;
            canidate_front = next_use[j].front();
          }
        }
      }

      set.erase(canidate_j);
    }

    set.insert(i);
    misses++;
  }
  return misses;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k, m;
  std::cin >> k >> m;

  std::vector<int> r(m);
  for (int i = 0; i < m; i++)
    std::cin >> r[i];

  int fifo_result = fifo(k, m, r);
  int lru_result = lru(k, m, r);
  int optff_result = optff(k, m, r);

  std::cout << "FIFO  : " << fifo_result << "\n";
  std::cout << "LRU   : " << lru_result << "\n";
  std::cout << "OPTFF : " << optff_result << "\n";
}
