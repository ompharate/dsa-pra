def hash_function(key,size):
    return hash(key) % size

def insertLinear(table,size,name,telephone):
    index = hash_function(name,size)
    while table[index] is not None:
        index = (index + 1) % size
    table[index] = (name,telephone)

def insertDoubleProbing(table,size,name,telephone):
    index = hash_function(name, size)
    attempt = 1
    while table[index] is not None:
        index = (index + attempt**2) % size
        attempt += 1
    table[index] = (name,telephone)

def display(table,size):
    for i in range(size):
            print(table[i])

def main():
    size = int(input("Enter the size of hash table: "))
    table = [None] * size
        
    while True:
        print("\n1. Insert")
        print("2. Display")
        print("3. Exit")
        ch = int(input("Enter your choice: "))
        if(ch==1):
            name = input("Enter the name:")          
            telephone = int(input("Enter the telephone number:"))
            print("1]liner probing..")
            print("2]quadratic probing..")
            ch1 =int(input("Enter your choice: "))
            if(ch1==1):
                insertLinear(table,size,name,telephone)
            else:
                insertDoubleProbing(table,size,name,telephone)
        elif(ch==2):
            display(table,size)
        elif(ch==3):
            break
        else:
            print("Invalid choice")

main()