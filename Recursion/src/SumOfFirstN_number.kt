fun main() {

    println(printSum(10))
}

fun printSum(n:Int): Int
{
    if ( n == 1)
        return 1
    return n + printSum(n-1)
}