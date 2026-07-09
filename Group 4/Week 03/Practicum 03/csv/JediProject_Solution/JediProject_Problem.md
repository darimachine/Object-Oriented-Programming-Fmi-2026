### **Jedi Project Requirements**

Create a structure **Jedi** with the following characteristics:

* **Name** (maximum length 50 characters)
* **Age**
* **Power**
* **LightSaber**

Each saber should be described with the following fields:

* **Color** – **RED**, **YELLOW**, **GREEN**, **BLUE**, **PURPLE**
* **Type** – **SINGLE_BLADED**, **DOUBLE_BLADED**, **CROSSGUARD**

---

### **JediCollection Class**

Write a class **JediCollection**, which can store a maximum of 100 jedi and their count. Implement the following set of member functions: (Where there are angle brackets, you must determine what types the functions should accept and return, where it should be **const**, where by reference, etc.)

* **Jedi (\<String\>name, \<Natural integer\> age, \<Natural integer\> power, \<LightSaber\> saber)** – constructor. Implement an **overload** that accepts a specific color and type of saber instead of a **LightSaber** object.

**Functions of JediCollection:**

* **void addJedi(\<Jedi\> jedi)** – adds a jedi to the collection.
* **void removeJedi(\<String\>name)** – removes the jedi with the given name from the collection and shifts to the left the elements that were to its right.
* **void print()** – prints the collection.

---

### **JediData Class**

Create a class **JediData**, which aims to present data about the jedi and implements the following functions:

* **void sortByAge(\<Collection of Jedi\> collection)** – sorts the collection in ascending order by age.
* **void sortByPower(\<Collection of Jedi\> collection)** – sorts the collection in ascending order by power.
* **Color mostPopularSaberColor(\<Collection of Jedi\> collection)** – returns the most used saber color by the jedi in the collection.
* **Type mostPopularSaberType(\<Collection of Jedi\> collection)** – returns the most used saber type by the jedi in the collection.

---

### **JediIO Class**

Create a class **JediIO**, which handles the reading and writing of collections from and to files and includes the following functions:

* **void saveToBinary(\<Collection of Jedi\> collection, \<String\> fileName)** – saves the collection to the given binary file.
* **\<Collection of Jedi\> readFromBinary(\<String\> fileName)** – reads the collection from a binary file and returns it.
* **void saveToTxt(\<Collection of Jedi\> collection, \<String\> fileName)** – saves the collection to the given text file.
* **\<Collection of Jedi\> readFromTxt(\<Collection of Jedi\> collection, \<String\> fileName)** – reads the collection from a text file and returns it.

**Note:** Implement an **overload** using streams for reading/writing for the 4 functions above.