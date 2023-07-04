#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int qsize = queries.size();
        vector<int> res(qsize);

        // Add indexes of the queries as an extra value
        for (int i = 0; i < qsize; i++)
            queries[i].push_back(i);

        // Sort rooms and queries in descending order of room size
        sort(rooms.begin(), rooms.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        // Ascending order of room IDs
        set<int> ids;

        for (int i = 0, j = 0; i < qsize; i++) {
            // Insert room IDs for rooms with size >= query size
            for (; j < rooms.size() && rooms[j][1] >= queries[i][1]; j++)
                ids.insert(rooms[j][0]);

            // If ids is empty, no room satisfies the size condition, set -1
            if (ids.empty()) {
                res[queries[i][2]] = -1;
                continue;
            }

            int id, find, prevVal, nextVal;

            // Find the upper bound of the query room ID
            find = queries[i][0];
            auto iter = ids.upper_bound(find);

            // If iter is at the beginning, no previous possible, choose the beginning value as closest
            if (iter == ids.begin())
                id = *ids.begin();
            else {
                // The closest ID will be either in the upper bound iter or its previous iter

                nextVal = (iter == ids.end()) ? INT_MAX : *iter;
                prevVal = *prev(iter);

                id = (abs(prevVal - find) <= abs(nextVal - find)) ? prevVal : nextVal;
            }

            res[queries[i][2]] = id;
        }

        return res;
    }
};
