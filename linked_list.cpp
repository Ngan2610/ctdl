
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int info;
    Node* next;
};

// Khởi tạo danh sách rỗng
void Init(Node* &pHead) {
    pHead = NULL;
}

// Kiểm tra danh sách rỗng
bool IsEmpty(Node* pHead) {
    return (pHead == NULL);
}

// Tạo một Node mới
Node* CreateNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Duyệt danh sách
void ShowList(Node* pHead) {
    Node* p = pHead;
    while (p != NULL) {
        cout << p->info << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

// Thêm một phần tử vào đầu danh sách
void InsertFirst(Node* &pHead, int x) {
    Node* p = CreateNode(x);
    p->next = pHead;
    pHead = p;
}

// Thêm một phần tử sau một Node
void InsertAfter(Node* p, int x) {
    if (p != NULL) {
        Node* q = CreateNode(x);
        q->next = p->next;
        p->next = q;
    }
}

// Xóa phần tử đầu danh sách
void DeleteFirst(Node* &pHead) {
    if (pHead != NULL) {
        Node* p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Tìm kiếm phần tử
Node* Find(Node* pHead, int x) {
    Node* p = pHead;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->next;
    }
    return NULL;
}

// Xóa toàn bộ danh sách
void ClearList(Node* &pHead) {
    Node* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->next;
        delete p;
    }
}

// Sắp xếp danh sách (Selection Sort)
void SelectionSort(Node* &pHead) {
    Node *p, *q, *pMin;
    int minValue;
    for (p = pHead; p != NULL; p = p->next) {
        pMin = p;
        minValue = p->info;
        for (q = p->next; q != NULL; q = q->next) {
            if (q->info < minValue) {
                minValue = q->info;
                pMin = q;
            }
        }
        // Hoán đổi giá trị
        pMin->info = p->info;
        p->info = minValue;
    }
}

// Hàm main để kiểm tra các chức năng
int main() {
    Node* pHead;
    Init(pHead);

    // Thêm các phần tử vào danh sách
    InsertFirst(pHead, 30);
    InsertFirst(pHead, 20);
    InsertFirst(pHead, 10);
    InsertFirst(pHead, 40);

    cout << "Danh sách liên kết ban đầu: ";
    ShowList(pHead);

    // Sắp xếp danh sách
    SelectionSort(pHead);
    cout << "Danh sách sau khi sắp xếp: ";
    ShowList(pHead);

    // Xóa phần tử đầu tiên
    DeleteFirst(pHead);
    cout << "Danh sách sau khi xóa phần tử đầu: ";
    ShowList(pHead);

    // Tìm kiếm phần tử
    Node* found = Find(pHead, 20);
    if (found != NULL) {
        cout << "Tìm thấy phần tử: " << found->info << endl;
    } else {
        cout << "Không tìm thấy phần tử" << endl;
    }

    // Xóa toàn bộ danh sách
    ClearList(pHead);
    cout << "Danh sách sau khi xóa toàn bộ: ";
    ShowList(pHead);

    return 0;
}
