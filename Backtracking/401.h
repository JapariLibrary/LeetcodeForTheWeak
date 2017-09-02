class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        finder(times, 0, 0, num);
        return times;
    }
private:
    void finder(vector<string>& times, int time, int idx, int num) {
        if (num == 0) {
            string str = getTime(time);
            if (!str.empty()) times.push_back(str);
        } else {
            for (int i = idx; i < 10 - num + 1; ++i) {
                finder(times, time | (1 << i), i + 1, num - 1);
            }
        }
    }
    
    string getTime(int time) {
        int hour = time >> 6;
        int minute = time % 64;
        if (hour > 11 || minute > 59) return "";
        string strHour = to_string(hour);
        //if (strHour.size() < 2) strHour = "0" + strHour;
        string strMinute = to_string(minute);
        if (strMinute.size() < 2) strMinute = "0" + strMinute;
        return strHour + ":" + strMinute;
    }
};