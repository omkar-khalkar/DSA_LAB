"""
To create ADT that implement the "set" concept.
a. Add (new Element) -Place a value into the set ,
b. Remove (element) Remove the value 
c. Contains (element) Return true if element is in collection,
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection, 
e. Intersection of two sets , 
f. Union of two sets,
g. Difference between two sets, 
h. Subset

"""


class Set:
    def __init__(self):
        self.element = []

    def display(self):
        print(self.element)

    def Add(self, x):
        if x not in self.element:
            self.element.append(x)
        return -1

    def Remove(self, x):
        if x in self.element:
            self.element.remove(x)
        return -1

    def Contains(self, x):
        if x in self.element:
            return True
        return False

    def Size(self):
        return len(self.element)

    def Intersection(self, b):
        Inter = []
        for i in self.element:
            if i in b.element:
                Inter.append(i)
        return Inter

    def Union(self, b):
        un = self.element.copy()
        for i in b.element:
            if i not in un:
                un.append(i)
        return un

    def Difference(self, b):
        diff = []
        for i in self.element:
            if i not in b.element:
                diff.append(i)
        return diff

    def Symm_diff(self, b):
        symm = self.element.copy()
        for i in b.element:
            if i in symm:
                symm.remove(i)
            else:
                symm.append(i)
        return symm

    def issubset(self, b):
        for element in b.element:
            if element not in self.element:
                return False
        return True


def print_menu():
    print("Menu:")
    print("1. Add element to the set")
    print("2. Remove element from the set")
    print("3. Check if element is in the set")
    print("4. Get the size of the set")
    print("5. Find the intersection of two sets")
    print("6. Find the union of two sets")
    print("7. Find the difference between two sets")
    print("8. Check if one set is a subset of another")
    print("9. Exit")


def print_menu():
    print("Menu:")
    print("1. Add element to the set")
    print("2. Remove element from the set")
    print("3. Check if element is in the set")
    print("4. Get the size of the set")
    print("5. Find the intersection of two sets")
    print("6. Find the union of two sets")
    print("7. Find the difference between two sets")
    print("8. Find the symmetric difference between two sets")
    print("9. Check if one set is a subset of another")
    print("10. Display the set")
    print("11. Exit")


def main():
    set1 = Set()

    while True:
        print_menu()
        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = int(input("Enter the element to add: "))
            set1.Add(element)
        elif choice == 2:
            element = int(input("Enter the element to remove: "))
            set1.Remove(element)
        elif choice == 3:
            element = int(input("Enter the element to check: "))
            if set1.Contains(element):
                print("Element is in the set.")
            else:
                print("Element is not in the set.")
        elif choice == 4:
            print("Size of the set:", set1.Size())
        elif choice == 5:
            set2 = Set()
            no = int(input("Enter the no. Of Element To Added in Set2: "))
            for i in range(no):
                element=int(input("Enter Element:"))
                set2.Add(element)
            # intersection = set1.Intersection(set2)
            print("Intersection of the two sets:", set1.Intersection(set2))
        elif choice == 6:
            set2 = Set()
            no = int(input("Enter the no. Of Element To Added in Set2: "))
            for i in range(no):
                element=int(input("Enter Element:"))
                set2.Add(element)
            union = set1.Union(set2)
            print("Union of the two sets:", union)
        elif choice == 7:
            set2 = Set()
            no = int(input("Enter the no. Of Element To Added in Set2: "))
            for i in range(no):
                element=int(input("Enter Element:"))
                set2.Add(element)
            difference = set1.Difference(set2)
            print("Difference between the two sets:", difference)
        elif choice == 8:
            set2 = Set()
            no = int(input("Enter the no. Of Element To Added in Set2: "))
            for i in range(no):
                element=int(input("Enter Element:"))
                set2.Add(element)
            sym_diff = set1.Symm_diff(set2)
            print("Symmetric difference between the two sets:", sym_diff)
        elif choice == 9:
            set2 = Set()
            no = int(input("Enter the no. Of Element To Added in Set2: "))
            for i in range(no):
                element=int(input("Enter Element:"))
                set2.Add(element)
            if set1.issubset(set2):
                print("Set 1 is a subset of Set 2.")
            if set2.issubset(set1):
                print("Set 2 is a subset of Set 1.")

            else:
                print("Set 1 is not a subset of Set 2.")
        elif choice == 10:
            print("Set elements:")
            set1.display()
        elif choice == 11:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
