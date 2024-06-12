class LRUCache
{
public:
  class Node
  {
  public:
    int key;
    int value;

    Node *next;
    Node *prev;

    Node(int k, int v)
    {
      this->key = k;
      this->value = v;
    }
  };

  int cap;
  Node *head = new Node(-1, -1);
  Node *tail = new Node(-1, -1);

  unordered_map<int, Node *> mp;

  LRUCache(int capacity)
  {
    this->cap = capacity;
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
  }
  void addnode(Node *temp)
  {
    Node *n = head->next;
    temp->next = n;
    head->next = temp;
    temp->prev = head;
    n->prev = temp;
  }
  void deletenode(Node *temp)
  {
    Node *a = temp->prev;
    Node *b = temp->next;

    a->next = b;
    b->prev = a;
  }

  int get(int key)
  {
    if (mp.find(key) != mp.end())
    {
      Node *address = mp[key];
      int res = address->value;

      deletenode(address);
      addnode(address);

      return res;
    }
    return -1;
  }

  void put(int key, int val)
  {
    if (mp.find(key) != mp.end())
    {
      Node *ad = mp[key];
      ad->value = val;
      deletenode(ad);
      addnode(ad);
      mp[key] = head->next;
      return;
    }

    Node *newnode = new Node(key, val);

    if (mp.size() < cap)
    {
      addnode(newnode);
      mp[key] = head->next;
    }
    else
    {
      Node *del = tail->prev;
      deletenode(del);
      mp.erase(del->key);
      delete del;
      addnode(newnode);
      mp[key] = head->next;
    }
  }
};

int main()
{
  LRUCache *a = new LRUCache(5);
  a->put(1, new Node())
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */