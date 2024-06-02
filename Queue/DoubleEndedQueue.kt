
class DoubleEndedQueue {

    private var rear: Int = -1
    private var front: Int = -1
    private val queue = IntArray(SIZE)

    fun insertAtRear(value: Int) {
        when {
            rear == -1 -> {
                rear++
                front++
                queue[rear] = value
            }
            rear == SIZE - 1 -> {
                println("Overflow")
            }
            else -> {
                queue[++rear] = value
            }
        }
    }

    fun insertAtFront(value: Int) {
        when {
            front == -1 -> {
                front++
                rear++
                queue[front] = value
            }
            rear == SIZE - 1 -> {
                println("Overflow")
            }
            else -> {
                for (i in rear downTo front) {
                    queue[i + 1] = queue[i]
                }
                queue[front] = value
                rear++
            }
        }
    }

    fun deleteAtRear() {
        when {
            rear == -1 -> {
                println("Underflow")
            }
            front == rear -> {
                queue[rear] = -1
                rear = -1
                front = -1
            }
            else -> {
                queue[rear--] = -1
            }
        }
    }

    fun deleteAtFront() {
        when {
            front == -1 -> {
                println("Underflow")
            }
            front == rear -> {
                queue[front] = -1
                front = -1
                rear = -1
            }
            else -> {
                queue[front] = -1
                front++
            }
        }
    }

    fun printQueue() {
        if (front == -1) {
            println("queue is empty")
            return
        }
        for (i in front..rear) {
            print("${queue[i]} ")
        }
        println()
    }

    fun front(): Int {
        return if (front == -1) -1 else queue[front]
    }

    fun rear(): Int {
        return if (rear == -1) -1 else queue[rear]
    }
}

fun main() {
    val dq = DoubleEndedQueue()
    dq.deleteAtFront()
    dq.insertAtFront(5)
    dq.insertAtRear(6)
    dq.printQueue()
    dq.deleteAtRear()
    dq.printQueue()
    println(dq.front())
    println(dq.rear())
}
