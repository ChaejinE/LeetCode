class ListNode:
    def __init__(self, key=None, value=None, prev_node=None, next_node=None):
        self.key = key
        self.value = value
        self.prev_node = prev_node
        self.next_node = next_node


class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hash_table = dict()
        self.head = ListNode()
        self.tail = ListNode()
        self.head.next_node = self.tail
        self.tail.prev_node = self.head

    def reorder(self, key: int) -> None:
        if key in self.hash_table.keys():
            node = self.hash_table[key]
            node.prev_node.next_node = node.next_node
            node.next_node.prev_node = node.prev_node

            self.tail.prev_node.next_node = node
            node.prev_node = self.tail.prev_node
            self.tail.prev_node = node
            node.next_node = self.tail

    def get(self, key: int) -> int:
        if key in self.hash_table.keys():
            self.reorder(key)
            return self.hash_table[key].value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if (
            key not in self.hash_table.keys()
            and len(self.hash_table) + 1 > self.capacity
        ):
            will_be_deleted_key = self.head.next_node.key
            if self.head.next_node.next_node:
                self.head.next_node.next_node.prev_node = self.head
                self.head.next_node = self.head.next_node.next_node
            del self.hash_table[will_be_deleted_key]
            self.hash_table.pop(will_be_deleted_key, None)

        if key in self.hash_table.keys():
            self.reorder(key)
            node = self.hash_table[key]
            node.value = value
        else:
            node = ListNode(
                key=key, value=value, prev_node=self.tail.prev_node, next_node=self.tail
            )
            self.tail.prev_node.next_node = node
            self.tail.prev_node = node
            self.hash_table[key] = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
