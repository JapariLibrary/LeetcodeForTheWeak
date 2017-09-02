class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int beginRow = findRow(image, 0, x, true);
        int endRow = findRow(image, x + 1, image.size(), false);
        int beginCol = findCol(image, 0, y, true, beginRow, endRow);
        int endCol = findCol(image, y + 1, image[0].size(), false, beginRow, endRow);
        return (endRow - beginRow) * (endCol - beginCol);
    }
private:
    int findRow(vector<vector<char>>& image, int begin, int end, bool findBlack) {
        while (begin < end) {
            int mid = (begin + end) / 2;
            bool hasBlack = false;
            for (int i = 0; i < image[mid].size(); ++i) {
                if (image[mid][i] == '1') {
                    hasBlack = true;
                    break;
                }
            }
            if (findBlack == hasBlack) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
    
    int findCol(vector<vector<char>>& image, int begin, int end, bool findBlack, int beginRow, int endRow) {
        while (begin < end) {
            int mid = (begin + end) / 2;
            bool hasBlack = false;
            for (int i = beginRow; i < endRow; ++i) {
                if (image[i][mid] == '1') {
                    hasBlack = true;
                    break;
                }
            }
            if (findBlack == hasBlack) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return begin;
    }
};