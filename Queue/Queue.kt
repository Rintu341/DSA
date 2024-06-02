const val SIZE = 100
/*
Using a constructor: IntArray(size) creates an array of the specified size with all elements initialized to 0.
 */
class Queue {
    private val arr = IntArray(SIZE){ -1 }
    private var front = -1
    private var rear = -1
    fun enQueue(value: Int) {
        if (rear == -1) {
            rear++
            arr[rear] = value
            front++
            /*print 
            println("$rear ")
            println("${arr[rear]}")
            */
        } else if (rear == SIZE - 1) {
            println("Overflow")
            println(rear)
        } else {
            rear++
            arr[rear] = value
            /*print 
            println("$rear ")
            println("${arr[rear]}")
            */
        }
    }

    fun deQueue(): Int {
        var temp = -1
        when {
            front == -1 -> {
                println("UnderFlow")
            }
            front == rear -> {
                temp = arr[front]
                /*print
                println("$front ")
                println("${arr[front]}")
                */
                arr[front] = -1
                rear = -1
                front = -1
            }
            else -> {
                temp = arr[front]
                /*print
                println("$front ")
                println("${arr[front]}")
                */
                arr[front++] = -1
            }
        }
        return temp
    }

    fun printQueue() {
        if (front == -1) {
            println("Queue is empty")
        } else {
            for (i in front..rear) {
                print("${arr[i]} ")
            }
            println()
        }
    }

}

fun main() {
    val q = Queue()
    q.printQueue()
    q.enQueue(5)
    q.enQueue(8)
    q.enQueue(9)
    q.enQueue(4)
    q.enQueue(3)
    q.printQueue()
    q.deQueue()
    q.deQueue()
    q.deQueue()
    q.printQueue()
}
