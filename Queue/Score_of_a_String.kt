class Solution {
    private val q: ArrayList<Int> = arrayListOf()
    /*
    ArrayList is Suitable when you need a dynamic list that can grow or shrink.
     */

    fun scoreOfString(s: String): Int {
        stringToQueue(s)
        var sum = 0
        if (q.isNotEmpty()) {
            var first = q.removeAt(0)
            val size = q.size

            for (i in 0 until size) {
                val second = q.removeAt(0)
                sum += kotlin.math.abs(first - second)
                first = second
            }
        }
        return sum
    }

    // Push string into a queue
    private fun stringToQueue(s: String) {
        for (c in s) {
            q.add(c.code)
        }
    }

    fun printQueue() {
        for (element in q) {
            print("$element ")
        }
        println()
    }
}

fun main() {
    val s = "hello"
    val s1 = Solution()
    println(s1.scoreOfString(s))
}
