struct node {
    int data;
    struct node *next;
}

void push(Node** head_ref, int new_data)
{

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertmid(Node* prev_node, int new_data)
{
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
 
    Node* new_node = new Node();
 
    new_node->data = new_data;
 
    new_node->next = prev_node->next;
 
    prev_node->next = new_node;
}

