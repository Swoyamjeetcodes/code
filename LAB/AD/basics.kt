fun main() 
{
    println("Hello, world!")
    // Hello, world!

    val popcorn = 5    // There are 5 boxes of popcorn
    val hotdog = 7     // There are 7 hotdogs
    var customers = 10 // There are 10 customers in the queue

    // Some customers leave the queue
    customers = 8
    println(customers)
    println("There are $customers customers")
    // There are 10 customers
    println("There are ${customers + 1} customers")
    // There are 11 customers

    //Kotlin's ability to infer the type is called type inference.
    val a = 1
    // Variable declared without initialization
    val z: Int
    // Variable initialized
    z = 3
    val a: Int = 1000 // Int
    val b: String = "log message"   // String
    val c: Double = 3.14    // Double
    val d: Long = 100_000_000_000_000   // Long
    val e: Boolean = false  // Boolean
    val f: Char = '\n'   // Char
    //Lists store items in the order that they are added, and allow for duplicate items.
    //To create a read-only list (List), use the listOf() function.
    val numbers = listOf(1, 2, 3, 4, 5)
    println(numbers)

    //To create a mutable list (MutableList), use the mutableListOf() function.
    val numbers = mutableListOf(1, 2, 3, 4, 5)
    
    //To prevent unwanted modifications, you can create a read-only view of a mutable list by assigning it to a List:
    val shapes: MutableList<String> = mutableListOf("triangle", "square", "circle")
    val shapesLocked: List<String> = shapes

    //To get the first or last item in a list, use .first() and .last() functions respectively:
    println("The first item in the list is: ${Shapes.first()}")

    //To get the number of items in a list, use the .count() function:
    println("The list has ${Shapes.count()} items")

    //To add an item to a list, use the .add() function:
    Shapes.add("rectangle")
    println(Shapes)

    //sets are unordered and only store unique items.
    //To create a read-only set (Set), use the setOf() function.
    // Read-only set
    val readOnlyFruit = setOf("apple", "banana", "cherry", "cherry")
    // Mutable set with explicit type declaration
    val fruit: MutableSet<String> = mutableSetOf("apple", "banana", "cherry", "cherry")
    println(readOnlyFruit)
    //You can see in the previous example that because sets only contain unique elements, the duplicate "cherry" item is dropped.

    //Maps store items as key-value pairs. You access the value by referencing the key. You can imagine a map like a food menu. You can find the price (value), by finding the food (key) you want to eat. Maps are useful if you want to look up a value without using a numbered index, like in a list.
    //To create a read-only map (Map), use the mapOf() function.

    // Read-only map
    val readOnlyJuiceMenu = mapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(readOnlyJuiceMenu)
    // {apple=100, kiwi=190, orange=100}

    // Mutable map with explicit type declaration
    val juiceMenu: MutableMap<String, Int> = mutableMapOf("apple" to 100, "kiwi" to 190, "orange" to 100)
    println(juiceMenu)
    // {apple=100, kiwi=190, orange=100}
    //To access a value in a map, use the indexed access operator [] with its key:
    println(juiceMenu["apple"])

    //You can also use the indexed access operator [] to add items to a mutable map:
    juiceMenu["coconut"] = 150 // Add key "coconut" with value 150 to the map
    println(juiceMenu)
} 