class Solution {
    public int[] twoSum(int[] nums, int target) {

        //  HashMap to store the indices of the solution
        HashMap<Integer, Integer> solution = new HashMap<>();
        
        // Iterate through the nums array
        for (int i = 0; i < nums.length; i++) {
            // Calculate the complement that would sum to the target
            int complement = target - nums[i];
            
            // Check complement is in the array
            if (solution.containsKey(complement)) {
                // If found, return the indices
                return new int[] {solution.get(complement), i };
            }
            
            // Otherwise, add the current element and its index to the map
            solution.put(nums[i], i);
        }
        return new int[] {};
    }
}