node* getTail(node* head) {
    node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

node* partition(node* head, node* tail) {
    node* pivot = head;
    node* curr = head;
    node* prev = head;

    while (curr != tail->next) {
        if (pivot->data > curr->data) {
            swap(prev->next->data, curr->data);
            prev = prev->next;
        }
        curr = curr->next;
    }
    swap(prev->data, pivot->data);
    return prev;
}

void solveSort(node* head, node* tail) {
    if (head == NULL || tail == NULL || head == tail) {
        return;
    }
    node* pivot = partition(head, tail);
    solveSort(head, pivot);
    solveSort(pivot->next, tail);
}

void quickSort(node** headRef) {
    node* head = *headRef;
    if (head == NULL || head->next == NULL) {
        return;
    }
    node* tail = getTail(head);
    solveSort(head, tail);
}
