class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> reserved;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int seatNum = seat[1];
            if (reserved.find(row) == reserved.end()) {
                reserved[row] = vector<bool>(11, false);
            }
            reserved[row][seatNum] = true;
        }

        int count = (n - reserved.size()) * 2;

        for (const auto& [row, seats] : reserved) {
            bool leftOpen = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool rightOpen = !seats[6] && !seats[7] && !seats[8] && !seats[9];
            bool middleOpen = !seats[4] && !seats[5] && !seats[6] && !seats[7];

            if (leftOpen && rightOpen) {
                count += 2;
            } else if (leftOpen || rightOpen || middleOpen) {
                count += 1;
            }
        }

        return count;
    }
};
