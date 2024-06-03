fun main() {
    val arr = intArrayOf(5,9,10,4,6,7,3)
    reverse(arr, left = 0,right = arr.size -1)

    for(i in arr.indices)
    {
        println(arr[i])
    }
}

fun reverse(arr:IntArray,left: Int,right:Int)
{
    if(left >= right)
        return

    val temp = arr[left]
    arr[left] = arr[right]
    arr[right] = temp
    reverse(arr,left+1,right-1)
}