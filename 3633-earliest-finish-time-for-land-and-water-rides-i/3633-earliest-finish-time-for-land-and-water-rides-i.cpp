class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int result = INT_MAX;

        // land to water
        int min_land_finish = INT_MAX;
        for (int i = 0; i < landStartTime.size(); ++i) {
            min_land_finish = min(min_land_finish, landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            result = min(
                result,
                max(min_land_finish, waterStartTime[j])
                    + waterDuration[j]
            );
        }
        
        // water to land
        int min_water_finish = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); ++i) {
            min_water_finish = min(min_water_finish, waterStartTime[i] + waterDuration[i]);
        }

        for (int j = 0; j < landStartTime.size(); j++) {
            result = min(
                result,
                max(min_water_finish, landStartTime[j])
                    + landDuration[j]
            );
        }

        return result;
    }
};