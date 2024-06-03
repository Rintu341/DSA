fun main() {
    println("Enter number:")
    val n = readlnOrNull()?.toInt()
    printN(n!!)
    println()
    printNto1(n)
}


//Print 1 to N
fun printN(n:Int)
{
    if(n == 1) {
        print(1)
        return
    }
    printN(n-1)
    print(n)
}

//print N to 1

fun printNto1(n:Int)
{
    if( n == 1)
    {
        print(1)
        return
    }
    print(n)
    printNto1(n-1)
}
