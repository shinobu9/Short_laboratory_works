class Node:

    def __init__(self, data, prev=None, next=None):
        self.__data = data
        self.__prev__ = prev
        self.__next__ = next

    def get_data(self):
        return self.__data

    def __str__(self):
        s = f"data: {self.__data}, "
        if self.__prev__ != None:
            s += f"prev: {self.__prev__.__data}, "
        else:
            s += "prev: None, "
        if self.__next__ != None:
            s += f"next: {self.__next__.__data}"
        else:
            s += "next: None"
        return s


class LinkedList:

    def __init__(self, first=None, last=None):
        self.__first__ = None
        self.__last__ = None
        self.__length = 0

        if (first == None) and (last != None):
            raise ValueError("invalid value for last")
        elif (first != None) and (last == None):
            node = Node(first)
            self.__first__ = node
            self.__last__ = node
            self.__length = 1
        elif (first != None) and (last != None):
            node1 = Node(first)
            node2 = Node(last)
            node1.__next__ = node2
            node2.__prev__ = node1
            self.__first__ = node1
            self.__last__ = node2
            self.__length = 2

    def __len__(self):
        return self.__length

    def __str__(self):
        if self.__length == 0:
            return "LinkedList[]"
        current = self.__first__
        output = []
        while current != None:
            output.append(str(current))
            current = current.__next__
        return f"LinkedList[length = {self.__length}, [" + "; ".join(output) + "]]"

    def clear(self):
        self.__first__ = None
        self.__last__ = None
        self.__length = 0

    def append(self, element):
        node = Node(element)
        node.__prev__ = self.__last__
        if self.__first__ == None:
            self.__first__ = node
        if self.__last__ != None:
            self.__last__.__next__ = node
        self.__last__ = node
        self.__length += 1

    def pop(self):
        if self.__length == 0:
            raise IndexError("LinkedList is empty!")
        self.__last__.__prev__.__next__ = None
        self.__length -= 1

    def popitem(self, element):
        current = self.__first__
        while (current != None) and (current.get_data() != element):
            current=current.__next__
        if current != None:
            self.__length -= 1
            if current.__prev__ != None:
                current.__prev__.__next__ = current.__next__
            else:
                self.__first__ = current.__next__
            if current.__next__ != None:
                current.__next__.__prev__ = current.__prev__
            else:
                self.__last__ = current.__prev__
        else:
            raise KeyError(element.__str__() + " doesn't exist!")