template <typename MergeFn>
class SegmentTree {
private:
    std::vector<int> tree;
    MergeFn merge;
    int identity;
    int n;

    void build(const std::vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(arr, 2 * node + 1, l, mid);
            build(arr, 2 * node + 2, mid + 1, r);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || ql > r) return identity;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merge(
            query(ql, qr, 2 * node + 1, l, mid),
            query(ql, qr, 2 * node + 2, mid + 1, r)
        );
    }

    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(const std::vector<int>& arr, MergeFn mergeFn, int identityVal)
        : merge(mergeFn), identity(identityVal), n(arr.size()) {
        tree.resize(4 * n, identity);
        build(arr, 0, 0, n - 1);
    }

    int query(int l, int r) { return query(l, r, 0, 0, n - 1); }
    void update(int idx, int val) { update(idx, val, 0, 0, n - 1); }
};

class Solution {
public:
    // O(N * log^2 N)
    int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
        const int n = fruits.size(), m = baskets.size();
        if (m == 0) return n;

        auto mergeFn = [](int a, int b) { return std::max(a, b); };
        SegmentTree seg_tree(baskets, mergeFn, INT_MIN);

        // return leftmost pos >= val
        auto find_first_leftmost_larger = [&](int val) -> int {
            int l = 0, r = m - 1, ans = m;

            while (l <= r) {
                int mid = (l + r) / 2;
                (seg_tree.query(l, mid) >= val) ? (ans = mid, r = mid - 1)
                                                : (l = mid + 1);
            }
            return ans;
        };

        int unplaced = 0;

        for (const int fruit : fruits) {
            int pos = find_first_leftmost_larger(fruit);
            if (pos == m) {
                unplaced++;
            } else {
                seg_tree.update(pos, INT_MIN);
            }
        }
        return unplaced;
    }
};