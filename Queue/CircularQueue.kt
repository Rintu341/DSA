
class CircularQueue
{
    private var front = -1
    private var rear = -1
    private val cQueue = IntArray(SIZE){Int.MIN_VALUE}

    fun empty() : Boolean =  rear != SIZE - 1 || front > 0

    fun enQueue( value : Int)
    {
        when{
            rear == -1 ->{
                rear++
                front++
                cQueue[front] = value
            }
            empty() ->{
                rear = (rear+1)%SIZE
                cQueue[rear] = value
            }
            else ->{
                println("OverFlow")
            }
        }
    }

    fun deQueue()
    {
        when{
            front == -1 ->{
                println("Underflow")
            }
            front == rear ->
            {
                cQueue[front] = Int.MIN_VALUE
                front =  -1
                rear = -1
            }
            else ->
            {
                cQueue[front++] = Int.MIN_VALUE
            }
        }
    }
    fun printQueue() {
        if (front == -1) {
            println("queue is empty")
            return
        }
        for (i in front..rear) {
            print("${cQueue[i]} ")
        }
        println()
    }
    fun front(): Int {
        return if (front == -1) Int.MIN_VALUE else cQueue[front]
    }

    fun rear(): Int {
        return if (rear == -1) Int.MIN_VALUE else cQueue[rear]
    }

}

fun main() {
    val cq = CircularQueue()
    cq.enQueue(5)
    cq.enQueue(6)
    cq.enQueue(7)
    cq.enQueue(8)
    cq.enQueue(9)
    cq.printQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.printQueue()
    cq.enQueue(5)
    cq.enQueue(6)
    cq.enQueue(7)
    cq.enQueue(8)
    cq.enQueue(9)
    cq.enQueue(10)
    cq.enQueue(11)
    cq.enQueue(12)
    cq.enQueue(13)
    cq.printQueue()


}