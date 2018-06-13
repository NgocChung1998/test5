#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Item {
    int id,ngay_ban,sl;
    string ten_ch, hang_ch, nha_cung_cap;
    long gia_ban,tt;
};

struct Node {
    Item info;
    Node *next;
};

struct Stack {
    int length=0;
    Node *top;
};

void Init(Stack &S) {
    S.top = NULL;
    S.length = 0;
}

int isEmpty(Stack s) {
    return (s.top == NULL);
}

Node *getNode(Item x) {
    Node *p = new Node;
    p -> next = NULL;
    p -> info = x;
    return p;
}

void Clear(Stack &s) {
    Init(s);
}

void Push(Stack &s, Item x) {
    Node *p = getNode(x);
    p->next = s.top;
    s.top = p;
    s.length++;
}

Item Front(Stack s) {
    return s.top -> info;
}

void Pop (Stack &s) {
    if (!isEmpty(s)) {
        Item x = s.top -> info;
        s.top = s.top ->next;
        s.length--;
    }
}

void printOne (Item item) {
    cout << "----" << endl;
    cout <<"***san pham****"<<endl;
    cout << "ID: " << item.id << endl;
    cout << "Ten: " << item.ten_ch << endl;
    cout << "Hang: " << item.hang_ch << endl;
    cout << "Nha cc: " << item.nha_cung_cap << endl;
    cout << "Gia: " << item.gia_ban << endl;
    cout <<"*****hoa don*****" <<endl;
    cout <<"ngay ban" <<item.ngay_ban <<endl;
    cout <<"so luong" <<item.sl <<endl;
    cout <<"thanh tien" <<item.tt <<endl;
    cout << "----" << endl;
}

void printAll (Stack &s) {
    Node *p = s.top;
    while (p!= NULL) {
        printOne(p->info);
        p = p->next;
    }
}

Item getItem() {
    Item item;
    cout<<"*******san pham*******"<<endl;
    cout << "Id: ";
    cin >> item.id;
    cout << "Ten can ho: ";
    cin >>item.ten_ch;
    cout << "Hang can ho: ";
    cin >> item.hang_ch;
    cout << "Nha cung cap: ";
    cin >> item.nha_cung_cap;
    cout << "Gia tien: ";
    cin >> item.gia_ban;
    cout<<"*******hoa don*****"<<endl;
    cout <<"so luong:";
    cin >>item.sl;
    cout<<"ngay ban:";
    cin>>item.ngay_ban;
     cout<<"thanhtien:";
     item.tt=item.sl*item.gia_ban;

    return item;
}

void Input(Stack &s) {
    int n;
    Item x;
    cout << "Nhap so luong can ho: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap can ho thu " << i + 1 << endl;
        x = getItem();
        Push(s, x);
    }
}

void timKiemTheoTen(Stack s, string ten) {
    Node *p = s.top;
    while (p!= NULL) {
        if (p->info.ten_ch == ten) {
            printOne(p->info);
        }
        p = p->next;
    }
}

void timKiemTheoHang(Stack s, string hang) {
    Node *p = s.top;
    while (p!= NULL) {
        if (p->info.hang_ch == hang) {
            printOne(p->info);
        }
        p = p->next;
    }
}

void sapXepTheoTen(Stack &s) {
    Node *p = s.top;
    Item tmp[1000];
    int cnt = 0;
    while (p!= NULL) {
        tmp[++cnt] = p->info;
        p = p->next;
    }
    for (int i = 1; i <= cnt-1; i++) {
        for (int j = i; j <= cnt; j++) {
            if (tmp[i].ten_ch < tmp[j].ten_ch) {
                Item tg = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tg;
            }
        }
    }
    Clear(s);
    for (int i = 1; i <= cnt; i++) {
        Push(s, tmp[i]);
    }
    printAll(s);
}

void docFile(Stack &s) {
    ifstream fin;
    fin.open("DATA");
    while (!fin.eof()) {
        Item item;
        fin >> item.id;
      fin.ignore();
        getline(fin, item.ten_ch);
        getline(fin, item.hang_ch);
        getline(fin, item.nha_cung_cap);
        fin >> item.gia_ban;
        Push(s, item);
    }
    fin.close();

}

void ghiFile(Stack s) {
    ofstream fout;
    fout.open("DATA");
    Node *p = s.top;
    while (p!= NULL) {
        fout << p->info.id << endl;
        fout << p->info.ten_ch << endl;
        fout << p->info.hang_ch << endl;
        fout << p->info.nha_cung_cap << endl;
        fout << p->info.gia_ban << endl;
        p = p->next;
    }
    fout.close();
}

int main() {
    Stack s;
    Init(s);
    int chon;
    do {
        cout << "MENU" << endl;
        cout << "0. Thoat" << endl;
        cout << "1. Khoi tao du lieu" << endl;
        cout << "2. Them phan tu" << endl;
        cout << "3. Xoa phan tu" << endl;
        cout << "4. Lay du lieu dau" << endl;
        cout << "5. Hien thi kich co Stack" << endl;
        cout << "6. In ra cac phan tu cua Stack" << endl;
        cout << "7. Tim kiem theo hang" << endl;
        cout << "8. Tim kiem theo ten" << endl;
        cout << "9. Sap xep theo ten" << endl;
        cout << "10. Xoa toan bo Stack" << endl;
        cout << "11. Doc tu file" << endl;
        cout << "12. Ghi ra file" << endl;
        cout << "Nhap mot so: ";
        cin >> chon;
        switch (chon) {
            case 1: {
                Input(s);
                break;
            }
            case 2: {
                cout << "Nhap du lieu: " << endl;
                Item item = getItem();
                Push(s, item);
                break;
            }
            case 3: {
                Pop(s);
                break;
            }
            case 4: {
                Item item = Front(s);
                printOne(item);
                cout << endl;
                break;
            }
            case 5: {
                cout << "Size: " << s.length << endl;
                break;
            }
            case 6: {
                printAll(s);
                cout << endl;
                break;
            }
            case 7: {
                string key;
                cout << "Nhap ten: ";
                cin >> key;
                timKiemTheoTen(s, key);
                break;
            }
            case 8: {
                string key;
                cout << "Nhap hang: ";
                cin >> key;
                timKiemTheoHang(s, key);
                break;
            }
            case 9: {
                sapXepTheoTen(s);
                break;
            }
            case 10: {
                Clear(s);
                break;
            }
            case 11: {
                docFile(s);
                break;
            }
            case 12: {
                ghiFile(s);
                break;
            }
            case 0: {
                return 0;
                break;
            }
            default : {
                cout << "Nhap lai!";
                break;
            }
        }
    } while (1);
    return 0;
}


