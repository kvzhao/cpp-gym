#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
};

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

template <typename T> T convertStrTo(const std::string &str) {
  std::istringstream ss(str);
  T num;
  ss >> num;
  return num;
}

template <typename T> vector<T> stringToVectorOf(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);

  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<T> ret;

  ss.str(input);
  getline(ss, item, ',');
  ret.emplace_back(convertStrTo<T>(item));

  while (true) {
    if (!getline(ss, item, ',')) {
      break;
    }
    trimLeftTrailingSpaces(item);
    ret.emplace_back(convertStrTo<T>(item));
  }

  return ret;
}

vector<int> stringToIntegerVector(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);

  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<int> ret;

  ss.str(input);
  getline(ss, item, ',');
  ret.emplace_back(stoi(item));

  while (true) {
    if (!getline(ss, item, ',')) {
      break;
    }
    trimLeftTrailingSpaces(item);
    ret.emplace_back(stoi(item));
  }

  return ret;
}

template <class T> vector<vector<T>> stringToVector2DOf(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<vector<T>> rets;

  size_t end = 0;
  while (true) {
    end = input.find(']') + 1;
    string segment = input.substr(0, end);
    auto ret = stringToVectorOf<T>(segment);
    rets.emplace_back(ret);
    if (end + 1 > input.length())
      break;
    input = input.substr(end + 1, input.length());
  }

  return rets;
}

vector<vector<int>> stringToIntegerVector2D(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<vector<int>> rets;

  size_t end = 0;
  while (true) {
    end = input.find(']') + 1;
    string segment = input.substr(0, end);
    auto ret = stringToIntegerVector(segment);
    rets.emplace_back(ret);
    if (end + 1 > input.length())
      break;
    input = input.substr(end + 1, input.length());
  }

  return rets;
}

vector<string> stringToStringVector(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);

  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<string> ret;

  ss.str(input);
  getline(ss, item, ',');
  ret.emplace_back(item);

  while (true) {
    if (!getline(ss, item, ',')) {
      break;
    }
    trimLeftTrailingSpaces(item);
    ret.emplace_back(item);
  }

  return ret;
}

ListNode *stringToListNode(string input) {
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list) {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

void prettyPrintLinkedList(ListNode *node) {
  while (node && node->next) {
    cout << node->val << "->";
    node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

TreeNode *stringToTreeNode(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(stoi(item));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    int number = list[index];
    result += to_string(number) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

string stringVectorToString(vector<string> list, int length = -1) {
  if (length == -1) {
    length = list.size();
  }

  if (length == 0) {
    return "[]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    string s = list[index];
    result += s + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

string integerVector2DToString(vector<vector<int>> lists, int length = -1) {
  if (length == -1) {
    length = lists.size();
  }

  if (length == 0) {
    return "[[]]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    vector<int> list = lists[index];
    result += integerVectorToString(list, list.size()) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

string stringVector2DToString(vector<vector<string>> lists, int length = -1) {
  if (length == -1) {
    length = lists.size();
  }

  if (length == 0) {
    return "[[]]";
  }

  string result;
  for (int index = 0; index < length; index++) {
    vector<string> list = lists[index];
    result += stringVectorToString(list, list.size()) + ", ";
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}
