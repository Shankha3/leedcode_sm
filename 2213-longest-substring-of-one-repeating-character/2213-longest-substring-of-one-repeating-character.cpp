#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len = 1;
    char prefix_char = ' ';
    int prefix_len = 1;
    char suffix_char = ' ';
    int suffix_len = 1;
    int seg_len = 1;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.seg_len = left.seg_len + right.seg_len;
        res.max_len = max(left.max_len, right.max_len);

        res.prefix_char = left.prefix_char;
        res.prefix_len = left.prefix_len;
        res.suffix_char = right.suffix_char;
        res.suffix_len = right.suffix_len;

        if (left.suffix_char == right.prefix_char) {
            res.max_len = max(res.max_len, left.suffix_len + right.prefix_len);

            if (left.prefix_len == left.seg_len) {
                res.prefix_len = left.seg_len + right.prefix_len;
            }
            if (right.suffix_len == right.seg_len) {
                res.suffix_len = right.seg_len + left.suffix_len;
            }
        }
        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, s[start], 1, s[start], 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(s, 2 * node + 1, start, mid);
        build(s, 2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(s, 0, 0, n - 1);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node].prefix_char = ch;
            tree[node].suffix_char = ch;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, ch);
        } else {
            update(2 * node + 2, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int getMaxLen() const {
        return tree[0].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        int n = s.length();
        vector<int> ans(k);

        for (int i = 0; i < k; ++i) {
            st.update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = st.getMaxLen();
        }

        return ans;
    }
};