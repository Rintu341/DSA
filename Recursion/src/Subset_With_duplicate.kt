import java.util.*

class Solution2 {
    private val result: MutableList<MutableList<Int>> = mutableListOf()

    private fun backtrack(nums: IntArray, idx: Int, temp: MutableList<Int>) {
        if (idx >= nums.size) {
            temp.sort()
            if (!result.contains(temp)) {
                result.add(temp.toMutableList())
            }
            return
        }

        temp.add(nums[idx])
        backtrack(nums, idx + 1, temp)
        temp.removeAt(temp.size - 1)
        backtrack(nums, idx + 1, temp)
    }

    fun subsetsWithDup(nums: IntArray): List<List<Int>> {
        val temp: MutableList<Int> = mutableListOf()
        backtrack(nums, 0, temp)
        return result
    }
}

fun main() {
    val nums = intArrayOf(1, 2, 2)
    val s = Solution2()
    val result: List<List<Int>> = s.subsetsWithDup(nums)
    for (i in result.indices) {
        for (j in result[i].indices) {
            print("${result[i][j]} ")
        }
        println()
    }
}