

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) 
{
    int currentvalue  ;
    int nextvalue ; 
    SinglyLinkedListNode* tra = head ;
    SinglyLinkedListNode* temp1 ;
    while (tra!=NULL) 
    {
        // printf("%d ,",tra->data);
        temp1 = tra ; 
        tra = tra->next ;
        currentvalue = temp1->data;
        if (tra!=NULL)
        {

            nextvalue = tra->data;
            if (currentvalue==nextvalue)
            {
                temp1->next = temp1->next->next;
                tra = temp1;
            }
            
        }
        

    }
    return head  ; 

}



