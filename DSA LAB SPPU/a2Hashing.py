"""

Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s
telephone number. Make use of two collision handling techniques and compare them using number of comparisons 
required to find a set of telephone numbers.

"""
class record:
    def __init__(self):
        self.name = None
        self.no = None

    def set_name(self, name):
        self.name = name

    def set_no(self, no):
        self.no = no

    def get_name(self):
        return self.name

    def get_no(self):
        return self.no

class hashtable:
    def __init__(self) :
        self.size = int(input("Enter The Size Of Hashtable "))
        self.table = list(None for i in range(self.size))
        self.elecount=0
        self.cmp =0
        self.m =int(input("Enter The Relative Prime Number:"))
    
    def isfull(self):
        if(self.elecount == self.size):
            return True
        return False
    
    def hashfunction(self,key):
        return key%self.size
    
    def hashfunction2(self,key):
        return self.m -(key%self.m)
    
    def linear_probing(self,c):
        if(self.isfull()):
            print("HashTable Is FULL!!")
        pos = self.hashfunction(c.get_no())
        if(self.table[pos]==None):
            self.table[pos]=c;
            print("Record Inserted Successfully!!!")
            self.elecount+=1
        else:
            print("COLLLISION")
            while(self.table[pos]!=None):
                pos+=1
                if(pos>=self.size):
                    pos =0
            self.table[pos]=c
            self.elecount+=1
    def double_hashing(self,c):
        if(self.isfull()):
            print("HashTable Is FULL!!")
        pos = self.hashfunction(c.get_no())
        if(self.table[pos]==None):
            self.table[pos]=c;
            print("Record Inserted Successfully!!!")
            self.elecount+=1
        else:
            print("collision")
            while(self.table[pos]!=None):
                pos = self.hashfunction(c.get_no())+self.hashfunction2(c.get_no())
                if pos>=self.size:
                    pos = pos%self.size
            self.table[pos]=c
            self.elecount+=1

    def display(self):
        for i in range(self.size):
            print("Hash Value : "+str(i) +"\t\t"+str(self.table[i]))
        print("The Total Number Of Elements :",self.elecount)

def main():
    a = hashtable()
    while(True):
        print("\n_______________________MENU______________________________\n")
        print("\t1.Dispaly Table ")
        print("\t2.Insert Record with Linear Probing")
        print("\t3.Insert Recors with Double Hashing")
        print("\t4.Check table is Full or not ")
        print("\t5.Exit")
        ch = int(input("Enter Your Choice : "))
        if(ch==1):
            a.display();
        elif(ch==2):
            n= int(input("Enter The No. Of Records "))
            for i in range(n):
                b= record()
                x = str(input("Enter name :"))
                y = int(input("Enter mob_no :"))
                b.set_name(x)
                b.set_no(y)
                a.linear_probing(b)
        elif (ch == 3):
            n = int(input("Enter the no of elements you want to insert : "))
            for i in range(n):
                b = record()
                x=str(input("Enter tha name : "))
                k=int(input("Enter tha number : "))
                b.set_name(x)
                b.set_no(k)
                a.double_hashing(b)
        elif (ch == 4):
            if (a.isFull()):
                print("\tTable is full !!!")
            else:
                print("\tTable is not full ")
        else:
            break

    



