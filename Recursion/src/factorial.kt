fun main() {
    println(factorial(6))
}

fun factorial(n:Int) :Int
{
    if(n == 0) return 1
    return n * factorial(n-1)
}