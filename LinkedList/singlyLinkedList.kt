class Node(var data: Int, var next: Node? = null) {
    constructor(data: Int) : this(data, null)
}
class linkedList()
{   
    var head:Node? = null
    fun insert(data: Int) {
        val newNode = Node(data)

        if (head == null) {
            // If the linked list is empty, make the new node the head
            head = newNode
        } else {
            // Traverse to the end of the linked list and add the new node
            var temp = head
            while (temp?.next != null) {
                temp = temp.next
            }
            temp?.next = newNode
        }
    }
    fun printList() {
        var current = head
        while (current != null) {
            print("${current.data} -> ")
            current = current.next
        }
        println("null")
    }
    fun searchNode(data:Int):Boolean
    {   
        
        var flag:Boolean = false
        var current = head
        while(current != null)
        {
            if(current.data == data)
            {
                flag = true
                break
            }
            current = current.next
        }
        return flag
    }
    fun lengthOfList():Int
    {
        var current = head
        var len:Int = 0;
        while(current != null)
        {
            len++;
            current = current.next
        }
        return len;
    }
    
}
fun main() {
    val linkedList = linkedList()
    linkedList.insert(4)
    linkedList.insert(6)
    linkedList.insert(7)
    linkedList.insert(9)

    linkedList.printList()

    if(linkedList.searchNode(9))
        println("Found")
    else
        println("Not Found")
        println(linkedList.lengthOfList())
}