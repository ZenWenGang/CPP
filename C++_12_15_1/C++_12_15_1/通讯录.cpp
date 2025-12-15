#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;

struct Persons
{
    string name;        // 姓名
    string sex;         // 性别
    unsigned int age;   // 年龄
    string phoneNumber; // 手机号码
    string address;     // 住址
};

class AddressBooks
{
public:
    vector<Persons> persons;                 // 通讯录中保存的联系人数组
    static constexpr int MAXSIZE = 1e3 + 10; // 通讯录最大容量

    AddressBooks() = default;
    ~AddressBooks() = default;
};

void showMenu();

void closeSystem();

bool addPerson(AddressBooks& addressBooks);

void showPersons(const AddressBooks& addressBooks);

int findPersonByName(const AddressBooks& addressBooks, const string& name);

int findPersonBySex(const AddressBooks& addressBooks, const string& sex);

int findPersonByAge(const AddressBooks& addressBooks, const int& age);

int findPersonByPhoneNumber(const AddressBooks& addressBooks, const string& phoneNumber);

int findPersonByAddress(const AddressBooks& addressBooks, const string& address);

bool removePerson(AddressBooks& addressBooks);

bool findPerson(const AddressBooks& addressBooks);

bool modifyPerson(AddressBooks& addressBooks);

void backupAddressBooks(const AddressBooks& addressBooks);

void restoreAddressBooks(AddressBooks& addressBooks);

void clearAddressBooks(AddressBooks& addressBooks);

int main()
{
    AddressBooks addressBooks;
    while (true)
    {
        showMenu(); // 菜单调用
        int select;
        cin >> select;
        system("cls");
        switch (select)
        {
        case 0: // 退出通讯录
        {
            closeSystem();
            break;
        }
        case 1: // 添加联系人
        {
            if (addPerson(addressBooks) == true)
            {
                cout << "联系人添加成功" << endl;
            }
            else
            {
                cout << "通讯录人数已满" << endl;
            }
            break;
        }
        case 2: // 显示联系人
        {
            showPersons(addressBooks);
            break;
        }
        case 3: // 删除联系人
        {
            if (removePerson(addressBooks) == true)
            {
                cout << "删除成功" << endl;
            }
            else
            {
                cout << "删除失败" << endl;
            }
            break;
        }
        case 4: // 查找联系人
        {
            if (!findPerson(addressBooks))
            {
                cout << "查无此人" << endl;
            }
            break;
        }
        case 5: // 修改联系人
            if (modifyPerson(addressBooks) == true)
            {
                cout << "修改成功" << endl;
            }
            else
            {
                cout << "修改失败" << endl;
            }
            break;
        case 6: // 备份通讯录
        {
            backupAddressBooks(addressBooks);
            break;
        }
        case 7: // 恢复通讯录
        {
            restoreAddressBooks(addressBooks);
            break;
        }
        case 8: // 清空通讯录
        {
            clearAddressBooks(addressBooks);
            cout << "通讯录已清空" << endl;
            break;
        }
        default:
        {
            cout << "输入错误，请重新输入" << endl;
             system("pause");
             system("cls");
            continue;
        }
        }
         system("pause");
         system("cls");
    }
    return 0;
}

void showMenu()
{
    cout << "***********************" << endl
        << "*****1、添加联系人*****" << endl
        << "*****2、显示联系人*****" << endl
        << "*****3、删除联系人*****" << endl
        << "*****4、查找联系人*****" << endl
        << "*****5、修改联系人*****" << endl
        << "*****6、保存通讯录*****" << endl
        << "*****7、恢复通讯录*****" << endl
        << "*****8、清空通讯录*****" << endl
        << "*****0、退出通讯录*****" << endl
        << "***********************" << endl;
}

void closeSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0); // 退出程序
}

bool addPerson(AddressBooks& addressBooks)
{
    if (addressBooks.persons.size() < AddressBooks::MAXSIZE)
    {
        Persons person;
        int sex;
        cout << "请输入姓名：";
        cin >> person.name;
        cout << "请输入性别：(男：1 女：0）";
        cin >> sex;
        person.sex = sex == 1 ? "男" : "女";
        cout << "请输入年龄：";
        cin >> person.age;
        cout << "请输入手机号码：";
        cin >> person.phoneNumber;
        cout << "请输入住址：";
        cin >> person.address;
        addressBooks.persons.emplace_back(person);
        return true;
    }
    else
    {
        return false;
    }
}

void showPersons(const AddressBooks& addressBooks)
{
    if (!addressBooks.persons.empty())
    {
        for (auto& person : addressBooks.persons)
        {
            cout << "姓名：" << person.name
                << "\t性别：" << person.sex
                << "\t年龄：" << person.age
                << "\t手机号码：" << person.phoneNumber
                << "\t住址：" << person.address
                << endl;
        }
    }
    else
    {
        cout << "通讯录为空" << endl;
    }
}

int findPersonByName(const AddressBooks& addressBooks, const string& name)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

int findPersonBySex(const AddressBooks& addressBooks, const string& sex)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].sex == sex)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByAge(const AddressBooks& addressBooks, const int& age)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].age == age)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByPhoneNumber(const AddressBooks& addressBooks, const string& phoneNumber)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].phoneNumber == phoneNumber)
        {
            return i;
        }
    }
    return -1;
}

int findPersonByAddress(const AddressBooks& addressBooks, const string& address)
{
    for (int i = 0; i < addressBooks.persons.size(); ++i)
    {
        if (addressBooks.persons[i].address == address)
        {
            return i;
        }
    }
    return -1;
}

bool removePerson(AddressBooks& addressBooks)
{
    int select, index;
    cout << "请输入查询方式\n1.姓名\n2.性别\n3.年龄\n4.手机号码\n5.住址" << endl;
    cin >> select;
    switch (select) // 选择查询方式
    {
    case 1:
    {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "请输入性别：(男：1 女：0）";
        int s;
        cin >> s;
        string sex = s == 1 ? "男" : "女";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "请输入年龄：";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "请输入手机号码：";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "请输入住址：";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "您输入有误" << endl;
    }
    }
    if (index != -1)
    {
        addressBooks.persons.erase(addressBooks.persons.begin() + index);
        return true;
    }
    return false;
}

bool findPerson(const AddressBooks& addressBooks)
{
    int select, index;
    cout << "请输入查询方式\n1.姓名\n2.性别\n3.年龄\n4.手机号码\n5.住址" << endl;
    cin >> select;
    switch (select) // 选择查询方式
    {
    case 1:
    {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "请输入性别：(男：1 女：0）";
        int s;
        cin >> s;
        string sex = s == 1 ? "男" : "女";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "请输入年龄：";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "请输入手机号码：";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "请输入住址：";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "您输入有误" << endl;
    }
    }
    if (index != -1)
    {
        Persons person = addressBooks.persons[index];
        cout << "姓名：" << person.name
            << "\t性别：" << person.sex
            << "\t年龄：" << person.age
            << "\t手机号码：" << person.phoneNumber
            << "\t住址：" << person.address
            << endl;
        return true;
    }
    return false;
}

bool modifyPerson(AddressBooks& addressBooks)
{
    int select, index;
    cout << "请输入查询方式\n1.姓名\n2.性别\n3.年龄\n4.手机号码\n5.住址" << endl;
    cin >> select;
    switch (select) // 选择查询方式
    {
    case 1:
    {
        cout << "请输入姓名：";
        string name;
        cin >> name;
        index = findPersonByName(addressBooks, name);
        break;
    }
    case 2:
    {
        cout << "请输入性别：(男：1 女：0）";
        int s;
        cin >> s;
        string sex = s == 1 ? "男" : "女";
        index = findPersonBySex(addressBooks, sex);
        break;
    }
    case 3:
    {
        cout << "请输入年龄：";
        int age;
        cin >> age;
        index = findPersonByAge(addressBooks, age);
        break;
    }
    case 4:
    {
        cout << "请输入手机号码：";
        string phoneNumber;
        cin >> phoneNumber;
        index = findPersonByPhoneNumber(addressBooks, phoneNumber);
        break;
    }
    case 5:
    {
        cout << "请输入住址：";
        string address;
        cin >> address;
        index = findPersonByAddress(addressBooks, address);
        break;
    }
    default:
    {
        index = -1;
        cout << "您输入有误" << endl;
    }
    }
    if (index != -1)
    {
        Persons person;
        cout << "请输入修改后的姓名：";
        cin >> person.name;
        cout << "请输入修改后的性别：(男：1 女：0）";
        int s;
        cin >> s;
        person.sex = s == 1 ? "男" : "女";
        cout << "请输入修改后的年龄：";
        cin >> person.age;
        cout << "请输入修改后的手机号码：";
        cin >> person.phoneNumber;
        cout << "请输入修改后的住址：";
        cin >> person.address;
        addressBooks.persons[index] = person;
        return true;
    }
    return false;
}

void backupAddressBooks(const AddressBooks& addressBooks)
{
    ofstream ofs;
    ofs.open("addressbook.txt", ios::out); // 打开文件
    ofs << "姓名\t\t性别\t\t年龄\t\t手机号码\t\t住址" << endl;
    for (auto& person : addressBooks.persons)
    {
        ofs << person.name
            << "\t\t" << person.sex
            << "\t\t" << person.age
            << "\t\t" << person.phoneNumber
            << "\t\t" << person.address
            << endl;
    }
    ofs.close(); // 关闭文件
    cout << "备份成功" << endl;
}

void restoreAddressBooks(AddressBooks& addressBooks)
{
    ifstream ifs;
    ifs.open("addressbook.txt", ios::in); // 打开文件
    if (ifs.is_open())
    {
        string temp;
        getline(ifs, temp); // 将文件上方的标签输入到临时字符串
        cout << temp;
        Persons person;
        clearAddressBooks(addressBooks);
        while (ifs >> person.name >> person.sex >> person.age >> person.phoneNumber >> person.address)
        {
            addressBooks.persons.emplace_back(person);
        }
        ifs.close(); // 关闭文件
        cout << "恢复成功" << endl;
    }
    else
    {
        cout << "文件打开失败" << endl;
    }
}

void clearAddressBooks(AddressBooks& addressBooks)
{
    addressBooks.persons.clear();
}