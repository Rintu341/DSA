class Solution {
    private val result = mutableListOf<MutableList<Int>>()

    private fun backtrack(nums: MutableList<Int>, idx: Int, temp: MutableList<Int>) {
        if (idx >= nums.size) {
            result.add(temp.toMutableList())
            return
        }

        temp.add(nums[idx])
        backtrack(nums, idx + 1, temp)
        temp.removeAt(temp.lastIndex)
        backtrack(nums, idx + 1, temp)
    }

    fun subsets(nums: MutableList<Int>): List<List<Int>> {
        val temp = mutableListOf<Int>()
        backtrack(nums, 0, temp)
        return result
    }
}

fun main() {
    val nums = mutableListOf(3, 2, 1)
    val s = Solution()
    val result = s.subsets(nums)
    for (i in result) {
        for (j in i) {
            print("$j ")
        }
        println()
    }
}